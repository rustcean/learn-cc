#include "Nfa.h"


Nfa::Nfa(string re)
{
	this->re = re;
	re_ = pe = "";
	stateNum_NFA = 0;			//初始化状态为0
	graphNFA.push_back(vector<pair<int, char>>());	
}

// 插入连接符 .
void Nfa::insertContact()
{
	for (int i = 0; i < re.size() - 1; i++)
	{
		re_ += re[i];
		if (re[i] != '(' && re[i + 1] != ')' && re[i] != '|' && re[i + 1] != '|' && re[i+1]!='*')
		{
			re_ += '.';		//添加符号'.'
		}
	}
	re_ += re.back();	//添加最后一个元素
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
		//反弹出
		else if (c == ')')
		{
			while (op.top() != '(')
			{
				pe += op.top();			//符号接入pe
				op.pop();
			}
			op.pop();
		}
		else if (c == '*' || c == '.' || c == '|')
		{
			while (op.size())  
			{
				// 栈顶优先级
				if (priority(c) <= priority(op.top())) {
					pe += op.top();
					op.pop();
				}
				else break;
			}
			op.push(c);
		}
		//不是特殊符号
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
	// cout << "初态: " << se.first << "终态: " << se.second << endl;
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

//还要有一个函数处理通过一个字符后下一个集合


void Nfa::NFA2DFA()
{
	graphDFA[0].id = 0;		//初始id
	stateNum_DFA = 0;
	mp.clear();	//先清空map 记录了
	set<int> edge,newedge;
	edge.insert(1);
	edge = getSET_DFA(edge);
	graphDFA[0].now = edge;
	mp[edge] = 0;
	queue<set<int>> q;
	set<set<int>> mq;	//存拿来判断重复的
	q.push(edge);		//
	mq.insert(edge);	//用来判断
	while (!q.empty())
	{
		auto str = q.front(); //拿到队列前的edge
		//对每一个字符遍历
		for (auto ch : charstring)
		{
			set<int> str1;
			int id = mp[str];
			//对队列的edge的每一个数字
			for (auto number : str)
			{
				//查找数字对应的下一个数字
				for (auto edge : graphNFA[number])
				{
					if (edge.second == ch) //如果是通过该字符到的下一个数字就加入到str1中
					{
						str1.insert(edge.first);
					}
				}
			}
			edge = getSET_DFA(str1); //获取str1对应的集合
			graphDFA[id].next[ch] = edge;//加入到新状态中
			if (mq.count(edge) == 0&&!edge.empty()) //如果该set不在原本就有的状态中
			{
				mq.insert(edge);
				q.push(edge);
				
				stateNum_DFA++;	//进入新状态
				mp[edge] = stateNum_DFA;   //mp记录该edge对应的数字
				graphDFA[stateNum_DFA].now = edge; //该edge成为新状态的本状态
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



//判断是否是终态
bool Nfa::check_final(set<int>edge)
{
	if (edge.count(se.second) > 0)
		return true;
	else return false;
}

void Nfa::miniDFA()
{

	//判断终态非终态
	int numGroup = 0;
	groups->clear();
	stateNum_mini = 2; //先初始化为终态非终态两个，所以初始为2
	set<int> newgroups[105];//临时存放
	int new_stateNum_mini = 0;
	belong.clear();
	for (int i = 0; i <= stateNum_DFA; i++) {
		if (!check_final(graphDFA[i].now)) { //0是非终态
			groups[0].insert(mp[graphDFA[i].now]);
			belong[mp[graphDFA[i].now] ]= 0;
		}
		else {
			groups[1].insert(mp[graphDFA[i].now]);
			belong[mp[graphDFA[i].now]] = 1;
		}
	}
	
	//划分
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
					bool flag = true; //默认相同
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
			// 格式化
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

	// 格式化
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














