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

int main(int argc, char *argv[])
{

	cout << "请先把程序粘贴到temp.tny文件中再按1:";
	int flag = 0;
	cin >> flag;
	if (flag != 1) return 0;

	//开始
	string filename = "temp.tny"; //元数据文件
	fstream fopen(filename);
	if (!fopen.is_open()) { // 检查文件是否成功打开  
		std::cerr << "Failed to open file." << std::endl;
		return 1;
	}
	string str;

	char ch;
	while (fopen.get(ch)) { // 逐个字符读取文件内容，直到文件末尾  
		str += ch;
	}
	fopen.close(); // 关闭文件  

	std::cout << str << std::endl; // 输出字符串变量 str  

	return 0;


}
