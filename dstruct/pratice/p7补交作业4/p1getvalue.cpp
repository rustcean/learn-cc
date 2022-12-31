#include <iostream>
#include <stack>
#define MAXSIZE 100
using namespace std;

//判断表达式优先级
int symcmp(char a,char b)
{
    if(b=='(')
        return 1;
    else if((b=='*' || b=='/') && (a=='+' || a=='-' || a=='('))
        return 1;
    else if((b=='+' || b=='-') && (a=='('))
        return 1;
    else return 0;
}

//计算栈顶两个元素
int calculate(char c, int a,int b)
{
    int tmp=0;
    switch(c)
    {
        case '+':tmp=b+a;break;
        case '-':tmp=b-a;break;
        case '*':tmp=b*a;break;
        case '/':tmp=b/a;break;
    }
    return tmp;
}

//计算中缀表达式
int calculate_expression(char *str)
{
    int num_stack[MAXSIZE]; //运算栈
    int num_top=-1;         //运算栈指针
    char sym_stack[MAXSIZE];//操作栈
    int sym_top=-1;         //操作栈指针
    int i=0;
    while(str[i]!='\0')
    {
        if(isdigit(str[i]))//判断是否为数字
        {
            //将数字字符转为数值型并入栈
            int val=0;
            while(isdigit(str[i]))
            {
                val=val*10+str[i]-'0';//转换为数字
                i++;
            }
            num_stack[++num_top]=val;
        }
        else
        {
            if(str[i] == ')')
            {
                while(sym_stack[sym_top]!='(')
                {
                    //计算
                    int ret=calculate(sym_stack[sym_top],num_stack[num_top],num_stack[num_top-1]);
                    sym_top--;
                    num_top-=2;
                    num_stack[++num_top]=ret;
                }
                sym_top--;
                i++;
            }
            else if(!symcmp(sym_stack[sym_top],str[i]))
            {
                while(sym_top>-1 && (!symcmp(sym_stack[sym_top],str[i])))
                {
                    int ret=calculate(sym_stack[sym_top],num_stack[num_top],num_stack[num_top-1]);
                    sym_top--;
                    num_top-=2;
                    num_stack[++num_top]=ret;
                }
                sym_stack[++sym_top] = str[i];
                i++;
            }
            else
            {
                sym_stack[++sym_top] = str[i];
                i++;
            }
        }
    }
    while(sym_top > -1)
    {
        int ret = calculate(sym_stack[sym_top], num_stack[num_top], num_stack[num_top - 1]); 
        sym_top--;
        num_top -= 2;
        num_stack[++num_top] = ret;
    }
    return num_stack[0];
}

int main()
{
    char str[] = "50+3*(2+1)-5*5*(5+5)";
    int ret = calculate_expression(str);
    cout<<"50+3*(2+1)-5*5*(5+5)结果为: "<<ret<<endl;
    return 0;
}