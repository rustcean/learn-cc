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

	cout << "���Ȱѳ���ճ����temp.tny�ļ����ٰ�1:";
	int flag = 0;
	cin >> flag;
	if (flag != 1) return 0;

	//��ʼ
	string filename = "temp.tny"; //Ԫ�����ļ�
	fstream fopen(filename);
	if (!fopen.is_open()) { // ����ļ��Ƿ�ɹ���  
		std::cerr << "Failed to open file." << std::endl;
		return 1;
	}
	string str;

	char ch;
	while (fopen.get(ch)) { // ����ַ���ȡ�ļ����ݣ�ֱ���ļ�ĩβ  
		str += ch;
	}
	fopen.close(); // �ر��ļ�  

	std::cout << str << std::endl; // ����ַ������� str  

	return 0;


}
