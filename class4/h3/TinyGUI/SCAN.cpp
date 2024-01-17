/****************************************************/
/* File: scan.c                                     */
/* The scanner implementation for the TINY compiler */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "scan.h"

/* states in scanner DFA */
typedef enum
{
	START, INASSIGN, INPLUS, INLESS, INGREAT, INCOMMENT, INNUM, INID, DONE, INREGULAR, INREEXP
}
StateType;

/* lexeme of identifier or reserved word */


/* BUFLEN = length of the input buffer for
   source code lines */
#define BUFLEN 256

static char lineBuf[BUFLEN]; /* holds the current line */
static int linepos = 0; /* current position in LineBuf */
static int bufsize = 0; /* current size of buffer string */
static int EOF_flag = FALSE; /* corrects ungetNextChar behavior on EOF */

/* getNextChar fetches the next non-blank character
   from lineBuf, reading in a new line if lineBuf is
   exhausted */
static int getNextChar(void)
{
	if (!(linepos < bufsize))
	{
		lineno++;
		if (fgets(lineBuf, BUFLEN - 1, source))
		{
			if (EchoSource) fprintf(listing, "%4d: %s", lineno, lineBuf);
			bufsize = strlen(lineBuf);
			linepos = 0;
			return lineBuf[linepos++];
		}
		else
		{
			EOF_flag = TRUE;
			return EOF;
		}
	}
	else return lineBuf[linepos++];
}

/* ungetNextChar backtracks one character
   in lineBuf */
static void ungetNextChar(void)
{
	if (!EOF_flag) linepos--;
}

/* lookup table of reserved words */
static struct
{
	std::string str;
	TokenType tok;
} reservedWords[MAXRESERVED]
= { {"if",IF},{"then",THEN},{"else",ELSE},{"end",END},
   {"repeat",REPEAT},{"until",UNTIL},{"read",READ},
   {"write",WRITE},{"for",FOR},{"to",TO},{"downto",DOWNTO},{"do", DO},{"enddo",ENDDO} };

/* lookup an identifier to see if it is a reserved word */
/* uses linear search */
static TokenType reservedLookup(char* s)
{
	int i;
	for (i = 0; i < MAXRESERVED; i++)
		if (!strcmp(s, reservedWords[i].str.c_str()))
			return reservedWords[i].tok;
	return ID;
}

/****************************************/
/* the primary function of the scanner  */
/****************************************/
/* function getToken returns the
 * next token in source file
 */
TokenType getToken(void)
{  /* index for storing into tokenString */
	int tokenStringIndex = 0;
	/* holds current token to be returned */
	TokenType currentToken;
	/* current state - always begins at START */
	StateType state = START;
	/* flag to indicate save to tokenString */
	int save;
	while (state != DONE)
	{
		int c = getNextChar();
		save = TRUE;
		switch (state)
		{
		case START:
			if (isdigit(c))
				state = INNUM;
			else if (isalpha(c))
				state = INID;
			else if (c == ':')
				state = INASSIGN;
			else if (c == '+')
				state = INPLUS;
			else if (c == '<')
				state = INLESS;
			else if (c == '>')
				state = INGREAT;
			else if ((c == ' ') || (c == '\t') || (c == '\n'))
				save = FALSE;
			else if (c == '$')
				state = INREGULAR;
			else if (c == '{')
			{
				save = FALSE;
				state = INCOMMENT;
			}
			else
			{
				state = DONE;
				switch (c)
				{
				case EOF:
					save = FALSE;
					currentToken = ENDFILE;
					break;
				case '=':
					currentToken = EQ;
					break;
				case '-':
					currentToken = MINUS;
					break;
				case '*':
					currentToken = TIMES;
					break;
				case '%':
					currentToken = REM;
					break;
				case '^':
					currentToken = POW;
					break;
				case '/':
					currentToken = OVER;
					break;
				case '(':
					currentToken = LPAREN;
					break;
				case ')':
					currentToken = RPAREN;
					break;
				case '|':
					currentToken = RE;
					break;
				case '#':
					currentToken = RCS;
					break;
				case '?':
					currentToken = RCQ;
					break;
				case '&':
					currentToken = RT;
					break;
				case ';':
					currentToken = SEMI;
					break;
				default:
					currentToken = ERROR;
					break;
				}
			}
			break;
		case INCOMMENT:
			save = FALSE;
			if (c == EOF)
			{
				state = DONE;
				currentToken = ENDFILE;
			}
			else if (c == '}') state = START;
			break;
		case INASSIGN:
			state = DONE;
			if (c == '=')
				currentToken = ASSIGN;
			else
			{ /* backup in the input */
				ungetNextChar();
				save = FALSE;
				currentToken = ERROR;
			}
			break;
		case INPLUS:
			state = DONE;
			if (c == '=')
				currentToken = PLUSASSIGN;
			else
			{
				ungetNextChar();
				save = FALSE;
				currentToken = PLUS;
			}
			break;
		case INLESS:
			state = DONE;
			if (c == '=')
			{
				currentToken = LEQ;
			}
			else if (c == '>')
			{
				currentToken = NEQ;
			}
			else
			{
				ungetNextChar();
				save = FALSE;
				currentToken = LT;
			}
			break;
		case INGREAT:
			state = DONE;
			if (c == '=')
			{
				currentToken = GEQ;
			}
			else
			{
				ungetNextChar();
				save = FALSE;
				currentToken = GT;
			}
			break;
		case INREGULAR:
			state = DONE;
			if (c != '$')
			{
				currentToken = REEXP;
			}
			break;
		case INNUM:
			if (!isdigit(c))
			{ /* backup in the input */
				ungetNextChar();
				save = FALSE;
				state = DONE;
				currentToken = NUM;
			}
			break;
		case INID:
			if (!isalpha(c))
			{ /* backup in the input */
				ungetNextChar();
				save = FALSE;
				state = DONE;
				currentToken = ID;
			}
			break;
		case DONE:
		default: /* should never happen */
			//fprintf(listing, "Scanner Bug: state= %d\n", state);
			/* Modify error handling */
			MyError e;
			e.errorType = "Scanner Bug";
			e.lineno = lineno;
			e.msg = state;
			errors.push_back(e);
			state = DONE;
			currentToken = ERROR;
			break;
		}
		if ((save) && (tokenStringIndex <= MAXTOKENLEN))
			tokenString[tokenStringIndex++] = (char)c;
		if (state == DONE)
		{
			tokenString[tokenStringIndex] = '\0';
			if (strcmp(tokenString, "and") == 0)
				currentToken = BITAND;
			if (strcmp(tokenString, "or") == 0)
				currentToken = BITOR;
			if (strcmp(tokenString, "not") == 0)
				currentToken = BITNOT;
			if (currentToken == ID)
				currentToken = reservedLookup(tokenString);
		}
	}
	if (TraceScan) {
		fprintf(listing, "\t%d: ", lineno);
		printToken(currentToken, tokenString);
	}
	return currentToken;
} /* end getToken */

string getlinebuf()
{
	string s = lineBuf;
	return s;
}
int getlineno()
{
	return lineno;
}

void setlinebuf(string s)
{
	strcpy(lineBuf, s.c_str());
}

void setlinepos(int n)
{
	linepos = n;
	bufsize = strlen(lineBuf);
}

void resetlinebuf()
{
	memset(lineBuf, '\0', sizeof(lineBuf));
	linepos = 0;
	bufsize = 0;
	EOF_flag = FALSE;
}
