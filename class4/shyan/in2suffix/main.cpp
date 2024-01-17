#include <stack>
#include <iostream>
#include <string>

using namespace std;

//�жϼ�����
int prio(char op)
{
	int priority=0; 
	if (op == '*' || op == '/')
		priority = 2;
	else if (op == '+' || op == '-')
		priority = 1;
	else if (op == '(')   //��ջΪ�յ�ʱ���ѹ��
		priority = 0;
	return priority;
}


//ת������
bool Trans(string& str, string& str1)
{
	stack<char> s; //
	int i;
	for (i = 0; i< str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			str1 += str[i];				//�����־�ֱ�Ӵ�
		else
		{
			if (s.empty())				//���ջ�ǿյģ���ջ
				s.push(str[i]);		
			else if (str[i] == '(')		//����������ţ�Ҳ��ջ
				s.push(str[i]);
			else if (str[i] == ')')		//������������ţ���ջ�����
			{
				while (s.top() != '(')
				{
					str1 += s.top();
					s.pop();
				}
				s.pop();	//������ҲҪ���������������str1
			}
			else
			{
				while (prio(str[i]) <= prio(s.top()))	//��ջ�����ȼ����ڵ��ڵ�ǰ�����
				{
					str1 += s.top();    //�������ȼ��ߵ�����ӣ���֤�ȱ����㣬�����ͬ���ȼ���Ҳ�������󵽣�����ӽ�������֤�ȱ�����
					s.pop();
					if (s.empty())
						break;		//���ջ���ˣ���������ѭ��
				}
				s.push(str[i]);		//��ǰ�������ջ
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



//��׺���ʽ����
int su_compute(string &str)
{
	stack<char> s;//�ݴ���,��char���ͣ�����Ҫ�ǵü�ȥ'0'
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') //���������ֱ����ջ
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
				s.push(temporary_result+'0');   //ѹ��ȥ
				cout << temporary_result << endl;
			}
			else if (str[i] == '-')
			{
				number2 = s.top() - '0';
				s.pop();
				number1 = s.top() - '0';
				s.pop();
				temporary_result = number1 - number2;
				s.push(temporary_result + '0');   //ѹ��ȥ
				cout << temporary_result << endl;
			}
			else if (str[i] == '*')
			{
				number2 = s.top() - '0';
				s.pop();
				number1 = s.top() - '0';
				s.pop();
				temporary_result = number1 * number2;
				s.push(temporary_result + '0');   //ѹ��ȥ
				cout << temporary_result << endl;
			}
			else if (str[i] == '/')
			{
				number2 = s.top() - '0';
				s.pop();
				number1 = s.top() - '0';
				s.pop();
				temporary_result = number1 / number2;
				s.push(temporary_result + '0');   //ѹ��ȥ
				cout << temporary_result << endl;
			}
		}
	}
	return s.top()-'0';
}


//��׺���ʽ����
int su_compute1(string& str)
{
	stack<int> s;//�ݴ���
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') //���������ֱ����ջ
		{
			s.push(str[i]-'0');//��Ϊ��char���ͣ�Ҫ��ȥ'0'
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
				s.push(temporary_result );   //ѹ��ȥ
				cout << temporary_result << endl;
			}
			else if (str[i] == '-')
			{
				number2 = s.top();
				s.pop();
				number1 = s.top();
				s.pop();
				temporary_result = number1 - number2;
				s.push(temporary_result );   //ѹ��ȥ
				cout << temporary_result << endl;
			}
			else if (str[i] == '*')
			{
				number2 = s.top() ;
				s.pop();
				number1 = s.top() ;
				s.pop();
				temporary_result = number1 * number2;
				s.push(temporary_result );   //ѹ��ȥ
				cout << temporary_result << endl;
			}
			else if (str[i] == '/')
			{
				number2 = s.top() ;
				s.pop();
				number1 = s.top() ;
				s.pop();
				temporary_result = number1 / number2;
				s.push(temporary_result );   //ѹ��ȥ
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

	cout <<"��׺���ʽ: " << suffix << endl;

	int result = su_compute(suffix);
	cout << "������: " << result << endl;

	result = su_compute1(suffix);
	cout << "������: " << result << endl;
}


