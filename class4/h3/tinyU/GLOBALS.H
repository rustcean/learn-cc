/****************************************************/
/* File: globals.h                                  */
/* Global types and vars for TINY compiler          */
/* must come before other include files             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* MAXRESERVED = the number of reserved words */
#define MAXRESERVED 13

typedef enum
/* book-keeping tokens */
{
	ENDFILE, ERROR,
	/* reserved words */
	IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE,
	/* multicharacter tokens */
	ID, NUM,
	/* special symbols */
	ASSIGN, PLUSASSIGN, EQ, LT, GT, LEQ, GEQ, NEQ, PLUS, MINUS, TIMES, OVER, LPAREN, RPAREN, SEMI, REM, POW,
	/* for loop */
	FOR, TO, DO, DOWNTO, ENDDO,
	/* Regular Expressions */
	RE, RT, RCS, RCQ, RF, REEXP,
	/* Bit symbols */
	BITAND, BITOR, BITNOT
} TokenType;

struct MyError
{
	string errorType;
	int lineno;
	string msg;
};

__declspec(selectany) FILE* source; /* source code text file */
__declspec(selectany) FILE* listing; /* listing output text file */
__declspec(selectany) FILE* code; /* code text file for TM simulator */

__declspec(selectany) int lineno; /* source line number for listing */
__declspec(selectany) vector<MyError> errors;

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum { StmtK, ExpK } NodeKind;
typedef enum { IfK, ElseK, RepeatK, AssignK, ReadK, WriteK, ForK } StmtKind;
typedef enum { OpK, ConstK, IdK } ExpKind;

/* ExpType is used for type checking */
typedef enum { Void, Integer, Boolean } ExpType;

#define MAXCHILDREN 3

typedef struct treeNode
{
	struct treeNode* child[MAXCHILDREN];
	struct treeNode* sibling;
	int lineno;
	NodeKind nodekind;
	union { StmtKind stmt; ExpKind exp; } kind;
	union {
		TokenType op;
		int val;
		char* name;
	} attr;
	ExpType type; /* for type checking of exps */
} TreeNode;

/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/* EchoSource = TRUE causes the source program to
 * be echoed to the listing file with line numbers
 * during parsing
 */
__declspec(selectany) int EchoSource = 0;

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
__declspec(selectany) int TraceScan = 0;

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized form
 * (using indents for children)
 */
__declspec(selectany) int TraceParse = 0;

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
__declspec(selectany) int TraceAnalyze = 0;

/* TraceCode = TRUE causes comments to be written
 * to the TM code file as code is generated
 */
__declspec(selectany) int TraceCode = 0;

/* Error = TRUE prevents further passes if an error occurs */
__declspec(selectany) int Error = 0;
#endif
