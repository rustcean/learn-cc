#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

stack<string> expss; //装符号的栈 
stack<double> nums;  //数字的栈
map<string,int> exps;//


//
bool pri(string exp1,string exp2)//如果exp1
{
    if(exps[exp2]-exps[exp1]>1)
        return true;
    else
        return false;
}

//计算num1(expt)num2
double cal(string expt,double num1,double num2)
{
    double ans=0;
    switch(exps[expt])
    {
        case 0:  ans=num1*num2;break;
        case 1:  ans=num1/num2;break;
        case 3:  ans=num1+num2;break;
        case 4:  ans=num1-num2;break;
        default: break;
    }
    return ans;
}



double loop(string ss)
{
    ss+=" ";
    ss+="$";
    expss.push("#");

    istringstream str(ss);//转为string流--原题目每一项都有空格
    /*
    是将字符串变成字符串迭代器一样，将字符串流在依次拿出，比较好的是，
    它不会将空格作为流。这样就实现了字符串的空格切割。
    #include<sstream>
    */
   string out;
   while(str>>out)
   {
    if(out=="+"|| out=="-"||out=="*"||out=="/"||out=="$")
    {
        string exp2=expss.top();
        while(!pri(out,exp2))   //判断输入的字符串是否还比单个字符长
        {
            double a=nums.top();nums.pop();
            double b=nums.top();nums.pop();
            double ans=cal(exp2,b,a); //计算
            nums.push(ans);
            expss.pop();
            exp2=expss.top();
        }
        if(pri(out,exp2))
            expss.push(out);
        if(expss.top()=="$")
            break;
    }
    else
        nums.push(stod(out));   //把参数指定的字符串转换为double精度的浮点数
   }
    if(!nums.empty())
        return nums.top();
    else
        return -37;
}

int main()
{
    string ss;
    exps["*"]=0;
    exps["/"]=1;
    exps["+"]=3;
    exps["-"]=4;
    exps["$"]=6;
    exps["#"]=8;

    while(getline(cin,ss))
    {
        if(ss=="0")
            break;
        double ans=loop(ss);
        printf("%.21f\n",ans);//小数后两位浮点数
        while(!nums.empty())
            nums.pop();
        while(!expss.empty())
            expss.pop();
    }
    return 0;
}
