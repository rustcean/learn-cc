/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
void printToken(TokenType token, const char* tokenString)
{
	switch (token)
	{
	case IF:
	case THEN:
	case ELSE:
	case END:
	case REPEAT:
	case UNTIL:
	case READ:
	case WRITE:
		fprintf(listing,
			"reserved word: %s\n", tokenString);
		break;
	case ASSIGN: fprintf(listing, ":=\n"); break;
	case PLUSASSIGN: fprintf(listing, "+:=\n"); break;
	case LT: fprintf(listing, "<\n"); break;
	case LEQ: fprintf(listing, "<=\n"); break;
	case GT: fprintf(listing, ">\n"); break;
	case GEQ: fprintf(listing, ">=\n"); break;
	case EQ: fprintf(listing, "=\n"); break;
	case NEQ: fprintf(listing, "<>\n"); break;
	case LPAREN: fprintf(listing, "(\n"); break;
	case RPAREN: fprintf(listing, ")\n"); break;
	case SEMI: fprintf(listing, ";\n"); break;
	case PLUS: fprintf(listing, "+\n"); break;
	case MINUS: fprintf(listing, "-\n"); break;
	case TIMES: fprintf(listing, "*\n"); break;
	case REM: fprintf(listing, "%\n"); break;
	case POW: fprintf(listing, "^\n"); break;
	case OVER: fprintf(listing, "/\n"); break;
	case ENDFILE: fprintf(listing, "EOF\n"); break;
	case BITAND: fprintf(listing, "and\n"); break;
	case BITOR: fprintf(listing, "or\n"); break;
	case BITNOT: fprintf(listing, "not\n"); break;
	case REEXP: fprintf(listing, "Regular Expression\n"); break;
	case RE: fprintf(listing, "|\n"); break;
	case RCS: fprintf(listing, "#\n"); break;
	case RCQ: fprintf(listing, "?\n"); break;
	case RT: fprintf(listing, "&\n"); break;
	case TO: fprintf(listing, "to\n"); break;
	case DOWNTO: fprintf(listing, "downto\n"); break;
	case FOR: fprintf(listing, "for\n"); break;
	case DO: fprintf(listing, "do\n"); break;
	case ENDDO: fprintf(listing, "enddo\n"); break;
	case NUM:
		fprintf(listing,
			"NUM, val= %s\n", tokenString);
		break;
	case ID:
		fprintf(listing,
			"ID, name= %s\n", tokenString);
		break;
	case ERROR:
		fprintf(listing,
			"ERROR: %s\n", tokenString);
		break;
	default: /* should never happen */
		fprintf(listing, "Unknown token: %d\n", token);
	}
}

string printToken(TokenType token)
{
	switch (token)
	{
	case IF:
	case THEN:
	case ELSE:
	case END:
	case REPEAT:
	case UNTIL:
	case READ:
	case WRITE:
		return "reserved word: ";
		break;
	case ASSIGN: return ":="; break;
	case PLUSASSIGN: return "+:="; break;
	case LT: return "<"; break;
	case LEQ: return "<="; break;
	case GT: return ">"; break;
	case GEQ: return ">="; break;
	case EQ: return "="; break;
	case NEQ: return "<>"; break;
	case LPAREN: return "("; break;
	case RPAREN: return ")"; break;
	case SEMI: return ";"; break;
	case PLUS: return "+"; break;
	case MINUS: return "-"; break;
	case TIMES: return "*"; break;
	case REM: return "%"; break;
	case POW: return "^"; break;
	case OVER: return "/"; break;
	case ENDFILE: return "EOF"; break;
	case BITAND: return "and"; break;
	case BITOR: return "or"; break;
	case BITNOT: return "not"; break;
	case REEXP: return "Regular Expression"; break;
	case RE: return "|"; break;
	case RCS: return "#"; break;
	case RCQ: return "?"; break;
	case RT: return "&"; break;
	case TO: return "to"; break;
	case DOWNTO: return "downto"; break;
	case FOR: return "for"; break;
	case DO: return "do"; break;
	case ENDDO: return "enddo"; break;
	case NUM:
		return
			"NUM, val= ";
		break;
	case ID:
		return
			"ID, name= ";
		break;
	case ERROR:
		return
			"ERROR: ";
		break;
	default: /* should never happen */
		return "Unknown token: ";
	}
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode* newStmtNode(StmtKind kind)
{
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = StmtK;
		t->kind.stmt = kind;
		t->lineno = lineno;
	}
	return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode* newExpNode(ExpKind kind)
{
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = kind;
		t->lineno = lineno;
		t->type = Void;
	}
	return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char* copyString(char* s)
{
	int n;
	char* t;
	if (s == NULL) return NULL;
	n = strlen(s) + 1;
	t = (char*)malloc(n);
	if (t == NULL)
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	else strcpy(t, s);
	return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{
	int i;
	for (i = 0; i < indentno; i++)
		fprintf(listing, " ");
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode* tree)
{
	int i;
	INDENT;
	while (tree != NULL) {
		printSpaces();
		if (tree->nodekind == StmtK)
		{
			switch (tree->kind.stmt) {
			case IfK:
				fprintf(listing, "If\n");
				break;
			case ElseK:
				fprintf(listing, "Else\n");
				break;
			case RepeatK:
				fprintf(listing, "Repeat\n");
				break;
			case AssignK:
				fprintf(listing, "Assign to: %s\n", tree->attr.name);
				break;
			case ReadK:
				fprintf(listing, "Read: %s\n", tree->attr.name);
				break;
			case WriteK:
				fprintf(listing, "Write\n");
				break;
			case ForK:
				fprintf(listing, "For: \n");
				break;
			default:
				fprintf(listing, "Unknown ExpNode kind\n");
				break;
			}
		}
		else if (tree->nodekind == ExpK)
		{
			switch (tree->kind.exp) {
			case OpK:
				fprintf(listing, "Op: ");
				printToken(tree->attr.op, "\0");
				break;
			case ConstK:
				fprintf(listing, "Const: %d\n", tree->attr.val);
				break;
			case IdK:
				fprintf(listing, "Id: %s\n", tree->attr.name);
				break;
			default:
				fprintf(listing, "Unknown ExpNode kind\n");
				break;
			}
		}
		else fprintf(listing, "Unknown node kind\n");
		for (i = 0; i < MAXCHILDREN; i++)
			printTree(tree->child[i]);
		tree = tree->sibling;
	}
	UNINDENT;
}
