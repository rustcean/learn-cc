/****************************************************/
/* File: parse.c                                    */
/* The parser implementation for the TINY compiler  */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

static TokenType token; /* holds current token */

/* function prototypes for recursive calls */
static TreeNode* stmt_sequence(void);
static TreeNode* statement(void);
static TreeNode* if_stmt(void);
static TreeNode* else_stmt(void);
static TreeNode* repeat_stmt(void);
static TreeNode* assign_stmt(void);
static void assign_complex(TokenType t);
static TreeNode* read_stmt(void);
static TreeNode* write_stmt(void);
static TreeNode* exp(void);
static TreeNode* _bitor(void);
static TreeNode* _bitand(void);
static TreeNode* simple_exp(void);
static TreeNode* term(void);
static TreeNode* power(void);  // ^
static TreeNode* _bitnot(void);
static TreeNode* factor(void);
/* for loop */
static TreeNode* for_stmt(void);
/* regualr expression */
static void reexp();
static TreeNode* re_or();
static TreeNode* re_t();
static TreeNode* re_closure();
static TreeNode* re_factor();

static void syntaxError(std::string message)
{
	/*fprintf(listing, "\n>>> ");
	fprintf(listing, "Syntax error at line %d: %s", lineno, message.c_str());*/
	/* Modify error handling */
	MyError e;
	e.errorType = "Syntax error at line";
	e.lineno = lineno;
	e.msg = message;
	errors.push_back(e);
	Error = TRUE;
}

static void match(TokenType expected)
{
	if (token == expected) token = getToken();
	else {
		syntaxError("unexpected token -> ");
		/* Modify error handling */
		auto e = errors.back();
		errors.pop_back();
		string s = printToken(token);
		switch (token)
		{
		case WRITE:
		case NUM:
		case ID:
		case ERROR:
			s.append(tokenString);
			break;
		default:
			break;
		}
		if (s == "Unknown token: ")
			s += token;
		e.msg.append(s);
		errors.push_back(e);
		//fprintf(listing, "      ");
	}
}

TreeNode* stmt_sequence(void)
{
	TreeNode* t = statement();
	TreeNode* p = t;
	while ((token != ENDFILE) && (token != END) &&
		(token != ELSE) && (token != UNTIL) && (token != ENDDO))
	{
		TreeNode* q;
		if (token == SEMI) match(SEMI);
		if (((token != ENDFILE) && (token != END) &&
			(token != ELSE) && (token != UNTIL) && (token != ENDDO)))
		{
			q = statement();
			if (q != NULL) {
				if (t == NULL) t = p = q;
				else /* now p cannot be NULL either */
				{
					p->sibling = q;
					p = q;
				}
			}
		}
	}
	return t;
}


//P394 
//lineno: 961
TreeNode* statement(void)
{
	TreeNode* t = NULL;
	switch (token) {
	case IF: t = if_stmt(); break;
	case REPEAT: t = repeat_stmt(); break;
	case ID: t = assign_stmt(); break;
	case READ: t = read_stmt(); break;
	case WRITE: t = write_stmt(); break;
	case FOR: t = for_stmt(); break;
	default: syntaxError("unexpected token -> ");
		/* Modify error handling */
		auto e = errors.back();
		errors.pop_back();
		string s = printToken(token);
		switch (token)
		{
		case WRITE:
		case NUM:
		case ID:
		case ERROR:
			s.append(tokenString);
			break;
		default:
			break;
		}
		if (s == "Unknown token: ")
			s += token;
		e.msg.append(s);
		errors.push_back(e);
		token = getToken();
		break;
	} /* end case */
	return t;
}


//P394 
//lineno: 977
TreeNode* if_stmt(void)
{
	// Rewrite if_stmt() to match the grammar.
	TreeNode* t = newStmtNode(IfK);
	match(IF);
	if (t != NULL)
	{
		match(LPAREN);  // (
		t->child[0] = exp();
		match(RPAREN);  // )
	}
	if (t != NULL) t->child[1] = stmt_sequence();
	if (token == ELSE) {
		if (t != NULL) t->child[2] = else_stmt();
	}
	//match(END);
	return t;
}

TreeNode* else_stmt(void)
{
	TreeNode* t = newStmtNode(ElseK);
	match(ELSE);
	if (t != NULL) t->child[0] = stmt_sequence();
	return t;
}

//P394 
//lineno:991
TreeNode* repeat_stmt(void)
{
	TreeNode* t = newStmtNode(RepeatK);
	match(REPEAT);
	if (t != NULL) t->child[0] = stmt_sequence();
	match(UNTIL);
	if (t != NULL) t->child[1] = exp();
	return t;
}

TreeNode* assign_stmt(void)
{
	TreeNode* t = newStmtNode(AssignK);
	if ((t != NULL) && (token == ID))
		t->attr.name = copyString(tokenString);
	match(ID);
	if (token == ASSIGN)
		match(ASSIGN);
	else if (token == PLUSASSIGN)
	{
		assign_complex(PLUSASSIGN);
		match(PLUSASSIGN);
	}

	if (token == REEXP)
	{
		reexp();
		match(REEXP);
		if (t != NULL) t->child[0] = re_or();
		
		//Regular = false;
	}
	else if (t != NULL) t->child[0] = exp();
	return t;
}

// 处理+=
void assign_complex(TokenType t)
{
	string buf = getlinebuf();
	int no = getlineno();

	// 找+=符号的位置
	int pos_op = buf.find("+=");
	// 修改为:= id + 的结构
	string id = buf.substr(0, pos_op);
	string newbuf = id + ":=" + id + "+ " + buf.substr(pos_op + 2, buf.length() - pos_op - 2);
	int newno = pos_op + 2;
	setlinebuf(newbuf);
	setlinepos(newno);
}

TreeNode* read_stmt(void)
{
	TreeNode* t = newStmtNode(ReadK);
	match(READ);
	if ((t != NULL) && (token == ID))
		t->attr.name = copyString(tokenString);
	match(ID);
	return t;
}

TreeNode* write_stmt(void)
{
	TreeNode* t = newStmtNode(WriteK);
	match(WRITE);
	if (t != NULL) t->child[0] = exp();
	return t;
}

TreeNode* exp(void)
{
	TreeNode* t = _bitor();
	if ((token == LT) || (token == GT) || (token == EQ) || (token == LEQ) || (token == GEQ) || (token == NEQ)) {
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
		}
		match(token);
		if (t != NULL)
			t->child[1] = _bitor();
	}
	return t;
}

TreeNode* _bitor(void)
{
	TreeNode* t = _bitand();
	if (token == BITOR)
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
		}
		match(token);
		if (t != NULL)
			t->child[1] = _bitand();
	}
	return t;
}

TreeNode* _bitand(void)
{
	TreeNode* t = simple_exp();
	if (token == BITAND)
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
		}
		match(token);
		if (t != NULL)
			t->child[1] = simple_exp();
	}
	return t;
}

TreeNode* simple_exp(void)
{
	TreeNode* t = term();
	while ((token == PLUS) || (token == MINUS))
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
			match(token);
			t->child[1] = term();
		}
	}
	return t;
}

TreeNode* term(void)
{
	TreeNode* t = power();
	while ((token == TIMES) || (token == OVER) || (token == REM))
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
			match(token);
			p->child[1] = power();
		}
	}
	return t;
}

// ^
TreeNode* power(void)
{
	TreeNode* t = _bitnot();
	while ((token == POW))
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
			match(token);
			p->child[1] = _bitnot();
		}
	}
	return t;
}

TreeNode* _bitnot(void)
{
	TreeNode* t = NULL;
	while ((token == BITNOT))
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
			match(token);
			p->child[1] = factor();
		}
	}
	while ((token == NUM) || (token == ID) || (token == LPAREN))
	{
		t = factor();
	}
	return t;
}

TreeNode* factor(void)
{
	TreeNode* t = NULL;
	switch (token) {
	case NUM:
		t = newExpNode(ConstK);
		if ((t != NULL) && (token == NUM))
			t->attr.val = atoi(tokenString);
		match(NUM);
		break;
	case ID:
		t = newExpNode(IdK);
		if ((t != NULL) && (token == ID))
			t->attr.name = copyString(tokenString);
		match(ID);
		break;
	case LPAREN:
		match(LPAREN);
		t = exp();
		match(RPAREN);
		break;
	default:
		syntaxError("unexpected token -> ");
		printToken(token, tokenString);
		token = getToken();
		break;
	}
	return t;
}

// 扩充的for stmt
TreeNode* for_stmt(void)
{
	TreeNode* t = newStmtNode(ForK);
	match(FOR);
	if (t != NULL) t->child[0] = assign_stmt();
	if (token == TO)
	{
		match(TO);
		if (t != NULL) t->child[1] = simple_exp();
	}
	else
	{
		match(DOWNTO);
		if (t != NULL) t->child[1] = simple_exp();
	}
	match(DO);
	if (t != NULL) t->child[2] = stmt_sequence();
	match(ENDDO);
	return t;
}

void reexp()
{
	/*
	* TODO:
	* Remove '$' symbols in linebuf and tokenString,
	* Then, enter re_or() to process regular expresion.
	*/
	string buf = getlinebuf();
	int pos = buf.find('$');
	while (pos != buf.npos)
	{
		buf.erase(pos, 1);
		pos = buf.find('$');
	}
	/* get ':=' positon */
	pos = buf.find(":=");
	pos += 2;  // skip := and first letter.
	setlinebuf(buf);
	setlinepos(pos);
	//Regular = true;
	string tks = tokenString;
	tks.erase(tks.find('$'), 1);
	strcpy(tokenString, tks.c_str());
}

TreeNode* re_or()
{
	TreeNode* t = re_t();
	while ((token == RE)) {
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
		}
		match(token);
		if (t != NULL)
			t->child[1] = re_t();
	}
	return t;
}

TreeNode* re_t()
{
	TreeNode* t = re_closure();
	while ((token == RT)) {
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
		}
		match(token);
		if (t != NULL)
			t->child[1] = re_closure();
	}
	return t;
}

TreeNode* re_closure()
{
	TreeNode* t = re_factor();
	if ((token == RCS) || (token == RCQ)) {
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = token;
			t = p;
			match(token);
		}
	}
	return t;
}

TreeNode* re_factor()
{
	TreeNode* t = NULL;
	switch (token) {
	case NUM:
		t = newExpNode(ConstK);
		if ((t != NULL) && (token == NUM))
			t->attr.val = atoi(tokenString);
		match(NUM);
		break;
	case ID:
		t = newExpNode(IdK);
		if ((t != NULL) && (token == ID))
			t->attr.name = copyString(tokenString);
		match(ID);
		break;
	case LPAREN:
		match(LPAREN);
		t = re_or();
		match(RPAREN);
		break;
	default:
		syntaxError("unexpected token -> ");
		printToken(token, tokenString);
		token = getToken();
		break;
	}
	return t;
}

/****************************************/
/* the primary function of the parser   */
/****************************************/
/* Function parse returns the newly
 * constructed syntax tree
 */
TreeNode* parse(void)
{
	TreeNode* t;
	token = getToken();
	t = stmt_sequence();
	if (token != ENDFILE)
		syntaxError("Code ends before file\n");
	return t;
}
