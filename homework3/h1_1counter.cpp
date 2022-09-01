//完成--存在问题:当分母为0时虽然会报错，但有依然会继续运算
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<char,int> exps;//


//两数运算函数
int cal(char expt,double num1,double num2)
{
	if(expt=='/')
		if(num2==0)
		{
			cout<<"error!!!"<<endl;
			return 0;
		}
    int ans=0;
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
int main()
{
	exps['*']=0;
	exps['/']=1;
	exps['+']=3;
	exps['-']=4;

	char arr[100];    //记录字符
	char a[20],b[20]; //中间量和运算符
	int c[100]={0};   //记录数字
	int result;       //结果
	int j=0,k=0,l=0;  //

	cin>>arr;         //cin.getline(arr,100)
	if(arr[strlen(arr)-1]!='=')    //如果最后一个字符不是"="
	{
        cout<<"1"<<endl;
		cout<<"error"<<endl;
        return 0;
	}

	for(int i=0;i<strlen(arr)-1;i++)
	{
		if(int(arr[i])>=48 && int(arr[i])<=57 )                          //如果是数字
		{
			a[j]=arr[i];
			j++;
		} 			
		else
		{                                                              //如果是非数字
		   if(i==0 || i==strlen(arr)-2) {cout<<"2error"<<endl;break;}  //如果非数字出现在第一个字符

		   if (arr[i]=='+' || arr[i]=='-' || arr[i]=='/'|| arr[i]=='*')//如果是运算符
		   {
			c[l]=atoi(a);l++;                //将收到的数字转为int型
            memset(a,0,sizeof(a));j=0;       //清零
			b[k]=arr[i];k+=1;                //记录运算符
		   }
		   else {cout<<"3error"<<endl;break;}                           //除了上面两种情况
		}
	}
    c[l]=atoi(a);l+=1;               //将收到的数字转为int型
    memset(a,'0',sizeof(a));j=0;     //清零
	if(k!=(l-1))                     //如果出现都多个运算符
	{
		cout<<"error"<<endl;
	}

	//检验
	for(int i=0;i<l;i++)
		cout<<c[i]<<endl;
	for(int i=0;i<k;i++)
		cout<<b[i]<<endl;

	//计算
	result=c[0];
	for(int i=0;i<k;i++)
	{
		result=cal(b[i],result,c[i+1]);
	}
	cout<<"结果为: "<<result<<endl;
	return 0;

}
/*
123+123+123+123+123+123=
123/123+1-1+123*1=
123/0=
*/
/*
//计算函数
int cal(char expt,int num1,int num2)
{
    int ans=0;
    try
    {    
        if(exps[expt]=1)
        {
            if(num2==0)
                throw(-1);//如果分母为0,出错,因为丢出去后，会先被catch所以不会进一步运算
        }
        switch(exps[expt])
        {
            case 0:  ans=num1*num2;break;
            case 1:  ans=num1/num2;break;
            case 3:  ans=num1+num2;break;
            case 4:  ans=num1-num2;break;
            default: break;
        }
    }
    catch(int i)
    {
        cout<<"运算出错";return 0;
    }
    
    return ans;
}
*/

// cout<<abs('0')<<endl;
// cout<<int('0')<<endl;
