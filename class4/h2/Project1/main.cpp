#include "Nfa.h"

using namespace std;

string REFILE = "RE.txt";	
string NFAFILE = "NFA.txt";

vector<string> get_filedata(string filename)
{
	vector<string> lines;
	ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "�޷����ļ�" << std::endl;
	}
	string line;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	file.close();
	return lines;
}


int main() {


	cout << "���RE.txt���б༭��Ȼ�������б��ļ�������1:" << endl;
	int re;
	cin >> re;
	if (re != 1)
		return 0;

	ofstream fout(NFAFILE);
	int count = 1;
	//��ȡ
	vector<string> re_lines = get_filedata(REFILE);
	for (const string& re_line : re_lines) {
		cout << "-----------------------------------" << endl;
		cout << "�� " << count << " ��" << endl; count++;
		cout <<"��������ʽ: "<< re_line << endl;
		Nfa nfa(re_line);
		nfa.insertContact();
		nfa.re2Pe();
		nfa.pe2NFA();
		cout << "NFA(Ҳ�ɲ鿴NFA.txt�ļ�):" << endl;
		nfa.printNFA(fout);
		fout.close();

		//תΪDFA
		nfa.NFA2DFA();
		cout << endl;
		cout << "DFA:" << endl;
		nfa.printDNF();
		//DFA��С��
		cout << endl;
		cout << "��С����dfa:" << endl;
		nfa.miniDFA();
		//���mini
		nfa.printDNFmini();

		//�������
		cout << endl;
		cout << "���ɸ��жϵĴ���:" << endl;
		nfa.printCode();
		cout << "-------------------------------" << endl;
	}

	system("pause");
}





