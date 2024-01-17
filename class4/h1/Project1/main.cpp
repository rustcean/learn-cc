#include<iostream>
#include<string>
#include<algorithm>
#include <graphics.h>
#include <conio.h>
#include<vector>
using namespace std;


//
string kw[1005];
string spe_symbol[1005], opt_symbol[1005];
int cnt1, cnt2, cnt3;
string type_name[10] = { "标识符","关键字","数","字符串","字符","注释","特殊符号","运算符号" };

// 关键文件
const char* Keywordfile = "keyword.txt";
const char* Special_symbolfile = "special_symbol.txt";
const char* Opt_symbolfile = "opt_symbol.txt";


//函数
bool Compare(string s1, string s2);					//比较
void Get_keywords();								// 获取关键字
void Get_symbols();									// 获取标识
string Read_test(string path);						// 读取源文件
void Replace(string& s, string s1, string s2);		//替换
int find_first(string s, string s1, int begin);	//首先找到
string Sub_str(string s, int l, int r);				//
string Fillint_str(int len);
void Check_1(string& s);							//检查注释和字符串
void Check_2(string& s);							//关键字和特殊符号
void Check_3(string& s);							//检查数字和标识符
void Long_match(string& s, string* s1, int n, int type);
//
void Print();
void Test(string path);
//void Print_GUI();

//
bool Compare(string s1, string s2)
{
	return s1.size() < s2.size();
}
//
void Get_keywords()
{
	freopen(Keywordfile, "r", stdin);
	while (getline(cin, kw[++cnt1]))
	{
		continue;
	}
	cnt1--;
	sort(kw + 1, kw + cnt1 + 1, Compare);
	freopen("CON", "r", stdin);
	cin.clear();
}
//
void Get_symbols()
{
	freopen(Special_symbolfile, "r", stdin);
	while (getline(cin, spe_symbol[++cnt2]))
	{
		continue;
	}
	cnt2--;
	sort(spe_symbol + 1, spe_symbol + cnt2 + 1, Compare);
	freopen("CON", "r", stdin);
	cin.clear();

	freopen(Opt_symbolfile, "r", stdin);
	while (getline(cin, opt_symbol[++cnt3]))
	{
		//cout << opt_symbol[cnt3] << endl;
		continue;
	}
	cnt3--;
	sort(opt_symbol + 1, opt_symbol + cnt3 + 1, Compare);
	freopen("CON", "r", stdin);
	cin.clear();
}
//
string Read_test(string path)
{
	string s = "", s1;
	const char* path1 = path.c_str();
	freopen(path1, "r", stdin);
	while (getline(cin, s1))
	{
		s += s1 + "\n";
	}
	//	cout << s;
	freopen("CON", "r", stdin);
	cin.clear();
	return s;
}
//
void Replace(string& s, string s1, string s2)
{
	string s3 = "";
	for (int i = 0; i < s.size();)
	{
		bool flag = 1;
		for (int j = 0; j < s1.size(); j++)
		{
			if ((i + j) >= s.size())break;
			if (s[i + j] != s1[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			s3 += s2;
			int l = i, r = l + s1.size() - 1;
			i = r + 1;
		}
		else
		{
			s3 += s[i];
			i++;
		}
	}
	s = s3;
}
//
int find_first(string s, string s1, int begin = 0)
{
	for (int i = begin; i < s.size(); i++)
	{
		bool flag = 1;
		for (int j = 0; j < s1.size(); j++)
		{
			if ((i + j) >= s.size())break;
			if (s[i + j] != s1[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			return i;
		}
	}return -1;
}
//
string Sub_str(string s, int l, int r)
{
	string s1 = "";
	for (int i = l; i <= r; i++)s1 += s[i];
	return s1;
}
//
string Fillint_str(int len)
{
	string s = "";
	for (int i = 1; i <= len; i++)s += '$';
	return s;
}

//
struct Ans
{
	int pos, type;
	string s;
	bool operator <(Ans x)const
	{
		return pos < x.pos;
	}
}arr[10005];

int cnt;

//检查注释和字符串
void Check_1(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		//cout << s << endl;
		if (s[i] == '"' && (i == 0 || s[i - 1] != '\\'))
		{
			int l = i;
			int r = find_first(s, "\"", l + 1);
			while (r != 0 && s[r - 1] == '\\')
			{
				r = find_first(s, "\"", r + 1);
			}
			++cnt;
			arr[cnt].s = Sub_str(s, l, r);
			arr[cnt].pos = l;
			arr[cnt].type = 3;
			s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
			//	cout<<s<<endl;
		}
		if (s[i] == '\'' && (i == 0 || s[i - 1] != '\\'))
		{
			int l = i;
			int r = find_first(s, "\'", l + 1);
			while (r != 0 && s[r - 1] == '\\')
			{
				r = find_first(s, "\'", r + 1);
			}
			++cnt;
			arr[cnt].s = Sub_str(s, l, r);
			arr[cnt].pos = l;
			arr[cnt].type = 4;
			s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
		}
		if (i == (s.size() - 1))continue;
		if (s[i] == '/' && s[i + 1] == '/')
		{
			int l = i;
			int r = find_first(s, "\n", l + 1);
			++cnt;
			arr[cnt].s = Sub_str(s, l, r - 1);
			arr[cnt].pos = l;
			arr[cnt].type = 5;
			s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
		}
		// 注释
		if (s[i] == '/' && s[i + 1] == '*')
		{

			int l = i;
			int r = find_first(s, "*/", l + 1) + 1;
			++cnt;
			arr[cnt].s = Sub_str(s, l, r);
			arr[cnt].pos = l;
			arr[cnt].type = 5;
			s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
			//	cout<<s<<endl;
		}
	}
}
//
void Long_match(string& s, string* s1, int n, int type)
{
	for (int i = n; i >= 1; i--)
	{
		int last = 0;
		while (last != -1)
		{
			int l = find_first(s, s1[i], last);
			int r = l + s1[i].size() - 1;

			if (l != -1)
			{
				last = l + 1;
				if (type == 1 && l != 0 && (s[l - 1] == '_' || (s[l - 1] >= 'a' && s[l - 1] <= 'z') || (s[l - 1] >= 'A' && s[l - 1] <= 'Z') || (s[l - 1] >= '0' && s[l - 1] <= '9')))
				{
					//cout<<s[l-1]<<"sdv ";
					continue;
				}
				if (type == 1 && r + 1 != s.size() && (s[r + 1] == '_' || (s[r + 1] >= 'a' && s[r + 1] <= 'z') || (s[r + 1] >= 'A' && s[r + 1] <= 'Z') || (s[r + 1] >= '0' && s[r + 1] <= '9')))
				{
					//	cout<<s[r+1]<<" dsv";
					continue;
				}
				++cnt;
				arr[cnt].pos = l;
				arr[cnt].s = s1[i];
				arr[cnt].type = type;
				s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
			}
			else break;

		}
		//Replace(s,s1[i],Fillint_str(s1[i].size()));
	}
}
//关键字和特殊符号
void Check_2(string& s)
{
	/*处理关键字*/
	Long_match(s, kw, cnt1, 1);
	/*处理特殊符号*/
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
		{
			int l = i; int r = find_first(s, ">", l + 1);
			if (r == -1)break;
			bool flag = 1;
			for (int j = l + 1; j < r; j++)
			{
				if (s[j] >= 'a' && s[j] <= 'z')continue;
				if (s[j] >= 'A' && s[j] <= 'Z')continue;
				if (s[j] == '.' || s[j] == ' ')continue;
				flag = 0;
			}
			if (flag)
			{
				++cnt;
				arr[cnt].pos = l;
				arr[cnt].s = Sub_str(s, l, r);
				arr[cnt].type = 6;
				s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
			}
		}
	}
	Long_match(s, spe_symbol, cnt2, 6);
	//处理运算符号
	Long_match(s, opt_symbol, cnt3, 7);
}
//检查数字和标识符
void Check_3(string& s)
{
	Replace(s, "\n", "$");
	Replace(s, " ", "$");
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '$')continue;
		if (s[i] < '0' || s[i]>'9')
		{
			int l = i, r = i;
			while (r + 1 < s.size() && s[r + 1] != '$')r += 1;
			++cnt;
			arr[cnt].pos = l;
			arr[cnt].s = Sub_str(s, l, r);
			arr[cnt].type = 0;
			s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
		}
		else
		{
			int l = i, r = i;
			while (r + 1 < s.size() && s[r + 1] != '$')r += 1;
			++cnt;
			arr[cnt].pos = l;
			arr[cnt].s = Sub_str(s, l, r);
			arr[cnt].type = 2;
			s = Sub_str(s, 0, l - 1) + Fillint_str(r - l + 1) + Sub_str(s, r + 1, s.size() - 1);
		}
	}
}
//
void Print()
{
	string line;
	cout << "扫描结果：\n";
	sort(arr + 1, arr + cnt + 1);
	for (int i = 1; i <= cnt; i++)
	{
		line = arr[i].s + "    " + type_name[arr[i].type];
		cout << line << endl;
		//		cout << arr[i].s << "    " << type_name[arr[i].type] << endl;
	}
}
//

void Print_GUI()
{
	vector<string> lines;
	string line = "扫描结果：\n";
	lines.push_back(line);
	sort(arr + 1, arr + cnt + 1);
	for (int i = 1; i <= cnt; i++)
	{
		line = arr[i].s + "    " + type_name[arr[i].type];
		lines.push_back(line);
	}
	const int lineHeight = 30;
	initgraph(800, 600);
	setbkcolor(WHITE); // 设置背景颜色为白色
	settextcolor(BLACK); // 设置文本颜色为黑色
	settextstyle(15, 0, _T("宋体")); // 设置文本样式，20号字体，宋体

	int y = 20; // 初始绘制位置的垂直坐标
	int windowHeight = 600; // 窗口高度
	int maxScroll = max(0, static_cast<int>(lines.size()) * lineHeight - windowHeight); // 最大滚动距离
	int scrollOffset = 0; // 当前滚动偏移量

	cleardevice();
	for (size_t i = 0; i < lines.size(); ++i) {
		if (y < windowHeight) {
			const char* cstr = lines[i].c_str();
			outtextxy(50, y, cstr); // 输出可见的文本
			y += 20;
		}
	}


	// 监测鼠标滚轮事件
	MOUSEMSG m;
	if (MouseHit()) {
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEWHEEL) {
			scrollOffset += m.wheel > 0 ? 30 : -30;
			scrollOffset = max(0, min(scrollOffset, maxScroll));
		}
	}
	while (1) {}
	closegraph(); // 关闭图形窗口

}


void Test(string path)
{
	//读取各种特殊字符
	Get_keywords();
	Get_symbols();

	string s = Read_test(path);
	//cout << s << endl;
	cnt = 0;
	//识别
	Check_1(s);
	//cout << "111" << endl;
	Check_2(s);
	//cout << "222" << endl;
	Check_3(s);
	//cout << "333" << endl;
}


// 标识符:0，关键字:1，数（包括整数、浮点数）:2，字符串:3、注释：4、特殊符号（分界符）：5、运算符号：6
int main()
{
	//
	string file_name = "Test.cpp";
	//
	Test(file_name);
	//
//	Print();
	Print_GUI();
	return 0;
}