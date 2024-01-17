#include <stack>
#include <iostream>
#include <string>

using namespace std;

//判断级别函数
int prio(char op)
{
	int priority=0; 
	if (op == '*' || op == '/')
		priority = 2;
	else if (op == '+' || op == '-')
		priority = 1;
	else if (op == '(')   //当栈为空的时候会压入
		priority = 0;
	return priority;
}


//转换函数
bool Trans(string& str, string& str1)
{
	stack<char> s; //
	int i;
	for (i = 0; i< str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			str1 += str[i];				//是数字就直接存
		else
		{
			if (s.empty())				//如果栈是空的，入栈
				s.push(str[i]);		
			else if (str[i] == '(')		//如果是左括号，也入栈
				s.push(str[i]);
			else if (str[i] == ')')		//如果遇到右括号，出栈并输出
			{
				while (s.top() != '(')
				{
					str1 += s.top();
					s.pop();
				}
				s.pop();	//左括号也要弹出，但不输出到str1
			}
			else
			{
				while (prio(str[i]) <= prio(s.top()))	//当栈顶优先级大于等于当前运算符
				{
					str1 += s.top();    //运算优先级高的先添加，保证先被运算，如果是同优先级则也按先来后到，先添加进来，保证先被运算
					s.pop();
					if (s.empty())
						break;		//如果栈空了，就跳出此循环
				}
				s.push(str[i]);		//当前运算符入栈
			}
		}
	}
	while (!s.empty())
	{
		str1 += s.top();
		s.pop();
	}
	return true;
}



//后缀表达式计算
int su_compute(string &str)
{
	stack<char> s;//暂存结果,以char类型，所以要记得减去'0'
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') //如果是数字直接入栈
		{
			s.push(str[i]);
		}
		else
		{
			int number1, number2, temporary_result;
			if (str[i] == '+')
			{
				number2 = s.top()-'0';
				s.pop();
				number1 = s.top() - '0';
				s.pop();
				temporary_result = number1 + number2;
				s.push(temporary_result+'0');   //压回去
				cout << temporary_result << endl;
			}
			else if (str[i] == '-')
			{
				number2 = s.top() - '0';
				s.pop();
				number1 = s.top() - '0';
				s.pop();
				temporary_result = number1 - number2;
				s.push(temporary_result + '0');   //压回去
				cout << temporary_result << endl;
			}
			else if (str[i] == '*')
			{
				number2 = s.top() - '0';
				s.pop();
				number1 = s.top() - '0';
				s.pop();
				temporary_result = number1 * number2;
				s.push(temporary_result + '0');   //压回去
				cout << temporary_result << endl;
			}
			else if (str[i] == '/')
			{
				number2 = s.top() - '0';
				s.pop();
				number1 = s.top() - '0';
				s.pop();
				temporary_result = number1 / number2;
				s.push(temporary_result + '0');   //压回去
				cout << temporary_result << endl;
			}
		}
	}
	return s.top()-'0';
}


//后缀表达式计算
int su_compute1(string& str)
{
	stack<int> s;//暂存结果
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') //如果是数字直接入栈
		{
			s.push(str[i]-'0');//因为是char类型，要减去'0'
		}
		else
		{
			int number1, number2, temporary_result;
			if (str[i] == '+')
			{
				number2 = s.top();
				s.pop();
				number1 = s.top() ;
				s.pop();
				temporary_result = number1 + number2;
				s.push(temporary_result );   //压回去
				cout << temporary_result << endl;
			}
			else if (str[i] == '-')
			{
				number2 = s.top();
				s.pop();
				number1 = s.top();
				s.pop();
				temporary_result = number1 - number2;
				s.push(temporary_result );   //压回去
				cout << temporary_result << endl;
			}
			else if (str[i] == '*')
			{
				number2 = s.top() ;
				s.pop();
				number1 = s.top() ;
				s.pop();
				temporary_result = number1 * number2;
				s.push(temporary_result );   //压回去
				cout << temporary_result << endl;
			}
			else if (str[i] == '/')
			{
				number2 = s.top() ;
				s.pop();
				number1 = s.top() ;
				s.pop();
				temporary_result = number1 / number2;
				s.push(temporary_result );   //压回去
				cout << temporary_result << endl;
			}
		}
	}
	return s.top() ;
}


int main()
{
	string inffix="(2+4-3)+6*2";
	string suffix;
	Trans(inffix, suffix);

	cout <<"后缀表达式: " << suffix << endl;

	int result = su_compute(suffix);
	cout << "计算结果: " << result << endl;

	result = su_compute1(suffix);
	cout << "计算结果: " << result << endl;
}


