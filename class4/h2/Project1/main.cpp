#include "Nfa.h"

using namespace std;

string REFILE = "RE.txt";	
string NFAFILE = "NFA.txt";

vector<string> get_filedata(string filename)
{
	vector<string> lines;
	ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "无法打开文件" << std::endl;
	}
	string line;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	file.close();
	return lines;
}


int main() {


	cout << "请对RE.txt进行编辑，然后再运行本文件并输入1:" << endl;
	int re;
	cin >> re;
	if (re != 1)
		return 0;

	ofstream fout(NFAFILE);
	int count = 1;
	//读取
	vector<string> re_lines = get_filedata(REFILE);
	for (const string& re_line : re_lines) {
		cout << "-----------------------------------" << endl;
		cout << "第 " << count << " 个" << endl; count++;
		cout <<"该正则表达式: "<< re_line << endl;
		Nfa nfa(re_line);
		nfa.insertContact();
		nfa.re2Pe();
		nfa.pe2NFA();
		cout << "NFA(也可查看NFA.txt文件):" << endl;
		nfa.printNFA(fout);
		fout.close();

		//转为DFA
		nfa.NFA2DFA();
		cout << endl;
		cout << "DFA:" << endl;
		nfa.printDNF();
		//DFA最小化
		cout << endl;
		cout << "最小化的dfa:" << endl;
		nfa.miniDFA();
		//输出mini
		nfa.printDNFmini();

		//输出代码
		cout << endl;
		cout << "生成该判断的代码:" << endl;
		nfa.printCode();
		cout << "-------------------------------" << endl;
	}

	system("pause");
}





