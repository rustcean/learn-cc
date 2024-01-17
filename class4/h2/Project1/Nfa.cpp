#include "Nfa.h"


Nfa::Nfa(string re)
{
	this->re = re;
	re_ = pe = "";
	stateNum_NFA = 0;			//��ʼ��״̬Ϊ0
	graphNFA.push_back(vector<pair<int, char>>());	
}

// �������ӷ� .
void Nfa::insertContact()
{
	for (int i = 0; i < re.size() - 1; i++)
	{
		re_ += re[i];
		if (re[i] != '(' && re[i + 1] != ')' && re[i] != '|' && re[i + 1] != '|' && re[i+1]!='*')
		{
			re_ += '.';		//��ӷ���'.'
		}
	}
	re_ += re.back();	//������һ��Ԫ��
}

//
int Nfa::priority(char c)
{
	if (c == '*') return 3;
	else if (c == '.') return 2;
	else if (c == '|') return 1;
	else return 0;
}

//
void Nfa::re2Pe()
{
	stack<char> op;
	for (auto c : re_) {
		if (c == '(') op.push(c);
		//������
		else if (c == ')')
		{
			while (op.top() != '(')
			{
				pe += op.top();			//���Ž���pe
				op.pop();
			}
			op.pop();
		}
		else if (c == '*' || c == '.' || c == '|')
		{
			while (op.size())  
			{
				// ջ�����ȼ�
				if (priority(c) <= priority(op.top())) {
					pe += op.top();
					op.pop();
				}
				else break;
			}
			op.push(c);
		}
		//�����������
		else pe += c;
	}
	while (op.size()) 
	{
		pe += op.top();
		op.pop();
	}
}

int Nfa::newState()
{
	graphNFA.push_back(vector<pair<int, char> >());
	return ++stateNum_NFA;
}


//
void Nfa::pe2NFA()
{
	stack<pair<int, int> > states;
	int s, e;
	for (auto c : pe)
	{
		if (c != '*' && c != '.' && c != '|')
		{
			charstring.insert(c);
			s = newState();
			e = newState();
			states.push(make_pair(s, e));
			graphNFA[s].push_back(make_pair(e, c));
			continue;
		}
		switch (c)
		{
		case '*': {
			pair<int, int> origin = states.top(); states.pop();
			s = newState();
			e = newState();
			states.push(make_pair(s, e));
			graphNFA[s].push_back(make_pair(origin.first, ' '));
			graphNFA[s].push_back(make_pair(e, ' '));
			graphNFA[origin.second].push_back(make_pair(e, ' '));
			graphNFA[origin.second].push_back(make_pair(origin.first, ' '));
			break;
		}
		case '.' : {
			pair<int, int> right = states.top(); states.pop();
			pair<int, int> left = states.top(); states.pop();
			states.push(make_pair(left.first, right.second));
			graphNFA[left.second].push_back(make_pair(right.first, ' '));
			break;
		}
		case '|' : {
			pair<int, int> down = states.top(); states.pop();
			pair<int, int> up = states.top(); states.pop();
			s = newState();
			e = newState();
			states.push(make_pair(s, e));
			graphNFA[s].push_back(make_pair(up.first, ' '));
			graphNFA[s].push_back(make_pair(down.first, ' '));
			graphNFA[up.second].push_back(make_pair(e, ' '));
			graphNFA[down.second].push_back(make_pair(e, ' '));
			break;
		}
		default:
				break;
		}
	}
	se = make_pair(states.top().first, states.top().second);
	// cout << "��̬: " << se.first << "��̬: " << se.second << endl;
}


void Nfa::printNFA(ofstream& fout)
{
	for (int i = 1; i <= stateNum_NFA; i++) {
		for (auto edge : graphNFA[i]) {
			fout << i << "----" << edge.second << "---->" << edge.first << "\n";
		}
	}
	fout << endl;
	for (int i = 1; i <= stateNum_NFA; i++) {
		for (auto edge : graphNFA[i]) {
			cout << i << "----" << edge.second << "---->" << edge.first << "\n";
		}
	}
	cout << endl;

}



set<int> Nfa::getSET_DFA(set<int> str)
{
	set<int> result = str;
	queue<int> str_flag;
	for (auto it=result.begin();it!=result.end();++it)
	{
		str_flag.push(*it);
	}
	while (!str_flag.empty())
	{
		int a = str_flag.front();
		for (auto edge : graphNFA[a]) {
			if (result.count(edge.first) == 0 && edge.second==' ')	
			{
				str_flag.push(edge.first);
				result.insert(edge.first);
			}
		}
		str_flag.pop();
	}
	return result;
}

//��Ҫ��һ����������ͨ��һ���ַ�����һ������


void Nfa::NFA2DFA()
{
	graphDFA[0].id = 0;		//��ʼid
	stateNum_DFA = 0;
	mp.clear();	//�����map ��¼��
	set<int> edge,newedge;
	edge.insert(1);
	edge = getSET_DFA(edge);
	graphDFA[0].now = edge;
	mp[edge] = 0;
	queue<set<int>> q;
	set<set<int>> mq;	//�������ж��ظ���
	q.push(edge);		//
	mq.insert(edge);	//�����ж�
	while (!q.empty())
	{
		auto str = q.front(); //�õ�����ǰ��edge
		//��ÿһ���ַ�����
		for (auto ch : charstring)
		{
			set<int> str1;
			int id = mp[str];
			//�Զ��е�edge��ÿһ������
			for (auto number : str)
			{
				//�������ֶ�Ӧ����һ������
				for (auto edge : graphNFA[number])
				{
					if (edge.second == ch) //�����ͨ�����ַ�������һ�����־ͼ��뵽str1��
					{
						str1.insert(edge.first);
					}
				}
			}
			edge = getSET_DFA(str1); //��ȡstr1��Ӧ�ļ���
			graphDFA[id].next[ch] = edge;//���뵽��״̬��
			if (mq.count(edge) == 0&&!edge.empty()) //�����set����ԭ�����е�״̬��
			{
				mq.insert(edge);
				q.push(edge);
				
				stateNum_DFA++;	//������״̬
				mp[edge] = stateNum_DFA;   //mp��¼��edge��Ӧ������
				graphDFA[stateNum_DFA].now = edge; //��edge��Ϊ��״̬�ı�״̬
			}
		}
		q.pop();
	}

}
void Nfa::printDNF()
{
	cout << "\t\t";
	for (auto ch : charstring)
	{
		cout << "" << ch << "\t\t\t";
	}
	cout << endl;
	for (int i = 0; i <= stateNum_DFA; i++)
	{
		for (auto x : graphDFA[i].now)
			cout << x << " ";
		for (auto ch : charstring)
		{
			cout << "\t";
			for (auto x : graphDFA[i].next[ch])
				cout<< x <<" ";
			cout << "\t\t";
		}
		cout << endl;
	}

}



//�ж��Ƿ�����̬
bool Nfa::check_final(set<int>edge)
{
	if (edge.count(se.second) > 0)
		return true;
	else return false;
}

void Nfa::miniDFA()
{

	//�ж���̬����̬
	int numGroup = 0;
	groups->clear();
	stateNum_mini = 2; //�ȳ�ʼ��Ϊ��̬����̬���������Գ�ʼΪ2
	set<int> newgroups[105];//��ʱ���
	int new_stateNum_mini = 0;
	belong.clear();
	for (int i = 0; i <= stateNum_DFA; i++) {
		if (!check_final(graphDFA[i].now)) { //0�Ƿ���̬
			groups[0].insert(mp[graphDFA[i].now]);
			belong[mp[graphDFA[i].now] ]= 0;
		}
		else {
			groups[1].insert(mp[graphDFA[i].now]);
			belong[mp[graphDFA[i].now]] = 1;
		}
	}
	
	//����
	while (1)
	{
		for (int i = 0; i < stateNum_mini; i++)
		{
			map<int, int>vis;
			for (auto x : groups[i])
			{
				if (vis[x])
					continue;
				set<int> new_line;
				vis[x] = 1;
				new_line.insert(x);

				for (auto y : groups[i])
				{
					if (vis[y])
						continue;
					bool flag = true; //Ĭ����ͬ
					for (auto ch : charstring)
					{
						int now = belong[mp[graphDFA[x].next[ch]]];
						int tp = belong[mp[graphDFA[y].next[ch]]];
						if (now != tp)
						{
							flag = false;
						}
					}
					if (flag)
					{
						//stateNum_mini++;
						new_line.insert(y);
						vis[y] = 1;
					}
				}
				newgroups[new_stateNum_mini++] = new_line;
			}
		}
		if (new_stateNum_mini > stateNum_mini)
		{
			for (int i = 0; i < new_stateNum_mini; i++)
			{
				groups[i] = newgroups[i];
				for (auto x : groups[i])
				{
					belong[x] = i;
				}

			}
			stateNum_mini = new_stateNum_mini;
		}
		else break;
	}

}

void Nfa::printDNFmini()
{
	for (auto ch : charstring)
		cout << "\t" << ch ;
	cout << endl;
	for (int i = 0; i < stateNum_mini; i++)
	{
		cout << i << "\t";
		for (auto ch : charstring)
		{
			auto x = *groups[i].begin();
			if (graphDFA[x].next[ch].empty())cout << "  \t";
			else cout << belong[mp[graphDFA[x].next[ch]]] << " \t";
		}cout << endl;
	}
}


void output(string s, int tabs = 0) {
	for (int i = 0; i < tabs; i++) { cout << '\t'; }
	cout << s << endl;
}

void Nfa::printCode()
{
	cout << "#include <iostream>" <<endl;
	cout << "using namespace std;" <<endl;
	output("#define Accept return true");
	output("#define Reject return false");
	cout << endl;
	output("int transfer(int state1, char ch)");
	output("{");
	
	for (int i = 0; i < stateNum_mini;i++) {
		for (auto ch:charstring) {
			auto x = *groups[i].begin();
			int first = i;
			int second ;
			if (graphDFA[x].next[ch].empty()) second = -1;
			else second = belong[mp[graphDFA[x].next[ch]]];
			// ��ʽ��
			string format("if (state == %d && ch == '%c')return %d;");
			char targetString[1024];
			snprintf(targetString, sizeof(targetString), format.c_str(),
				first+1, ch, second+1);
			output(string(targetString), 1);
		}
	}
	//work(string s)
	output("bool work(string s)");
	output("{");
	output("int now = 1;", 1);
	output("for (int i = 0; i < s.size(); i++)", 1);
	output("{", 1);
	output("now = transfer(now, s[i]);", 2);
	output("if (now == -1)Reject;", 2);
	output("}", 1);

	// ��ʽ��
	string fmt("if (now == %d)Accept;");
	char tS[128];
	snprintf(tS, sizeof(tS), fmt.c_str(), stateNum_mini);
	output(string(tS), 1);

	output("Reject;", 1);
	output("}");


	//main()
	output("int main()");
	output("{");
	output("string s;", 1);
	output("while (cin >> s)", 1);
	output("{", 1);
	output("if (test(s))puts(\"Accept!\");", 2);
	output("else puts(\"Reject!\");", 2);
	output("}", 1);
	output("}");


	return ;
}














