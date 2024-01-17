#include <iostream>
#include <cstring>
#include <fstream>
#include <string>


#include "ANALYZE.H"
#include "CGEN.H"
#include "GLOBALS.H"
#include "PARSE.H"
#include "SCAN.H"
#include "SYMTAB.H"
#include "UTIL.H"

using namespace std;

//树函数
void PrintTree(TreeNode* tree)
{
	int i;
	string nodeText;
	while (tree != NULL)
	{
		if (tree->nodekind==StmtK)
		{
			switch(tree->kind.stmt)
			{
			case IfK:
				nodeText = "If";
				break;
			case ElseK:
				nodeText = "Else";
				break;
			case RepeatK:
				nodeText = "Repeat";
				break;
			case AssignK:
				nodeText = "Assign to: "+string((tree->attr.name));
				break;
			case ReadK:
				nodeText = "Read: "+string((tree->attr.name));
				break;
			case WriteK:
				nodeText = "Write";
				break;
			case ForK:
				nodeText = "For: ";
				break;
			default:
				nodeText = "Unknown ExpNode kind";
				break;
			}
		}
		else if (tree->nodekind == ExpK)
		{
			switch (tree->kind.exp)
			{
			case OpK:
				nodeText = "Op: " + tree->attr.op;
				break;
			case ConstK:
				nodeText = "Const: "+tree->attr.val;
				break;
			case IdK:
				nodeText = "Id: "+string(tree->attr.name);
				break;
			default:
				nodeText = "Unknown ExpNode kind";
				break;
			}
		}
		else
		{
			nodeText = "Unknown node kind";
		}
		for (i = 0; i < MAXCHILDREN; i++)
			PrintTree(tree->child[i]);
		tree = tree->sibling;
	}
}


int main(int argc, char *argv[])
{

	cout << "请先把程序粘贴到temp.tny文件中再按1:";
	int flag = 0;
	cin >> flag;
	if (flag != 1) return 0;
	//开始
	string filename = "temp.tny"; //元数据文件
	ifstream fopen(filename);
	if (!fopen.is_open()) { // 检查文件是否成功打开  
		std::cerr << "Failed to open file." << std::endl;
		return 1;
	}
	string str;//目标str
	char ch;//按字符存
	while (fopen.get(ch)) { // 逐个字符读取文件内容，直到文件末尾  
		str += ch;
	}
	string source = str;
	//先清空
	lineno = 0;
	memset(tokenString, '\0', sizeof(tokenString));
	resetlinebuf();
	
	//开始分析
	TreeNode* syntaxTree;
	syntaxTree = parse();

	PrintTree(syntaxTree);
	printTree()

	fopen.close(); // 关闭文件  
	return 0;


}
