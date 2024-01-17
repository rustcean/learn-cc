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

//������
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

	cout << "���Ȱѳ���ճ����temp.tny�ļ����ٰ�1:";
	int flag = 0;
	cin >> flag;
	if (flag != 1) return 0;
	//��ʼ
	string filename = "temp.tny"; //Ԫ�����ļ�
	ifstream fopen(filename);
	if (!fopen.is_open()) { // ����ļ��Ƿ�ɹ���  
		std::cerr << "Failed to open file." << std::endl;
		return 1;
	}
	string str;//Ŀ��str
	char ch;//���ַ���
	while (fopen.get(ch)) { // ����ַ���ȡ�ļ����ݣ�ֱ���ļ�ĩβ  
		str += ch;
	}
	string source = str;
	//�����
	lineno = 0;
	memset(tokenString, '\0', sizeof(tokenString));
	resetlinebuf();
	
	//��ʼ����
	TreeNode* syntaxTree;
	syntaxTree = parse();

	PrintTree(syntaxTree);
	printTree()

	fopen.close(); // �ر��ļ�  
	return 0;


}
