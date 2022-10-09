#include <iostream>
#include <fstream>
#include <cstring>
#include  <sstream>
using namespace std;
//文件
string f1="inv1.csv";
string f2="inv2.csv";
const int NUMBER=15;

/*
需要的函数功能:
1.建立两个线性表
2.输出所有信息
3.按时间先后插入线性表
4.查找所有地点中包含超市的记录输出
5.将包含超市的记录存放到一个新的线性表SuperM中，删除原线性表的相关记录
6.合并SuperM的相同地点
7.将SuperM按序号时间地点输出并写入inv_superm.csv 文件
*/
struct Illpeople
{
    string time;    //记录时间
    string place;   //记录地点
};
class Market
{
   public:
    Illpeople data;
};

//文件读取函数
int Readfile(string file,Market *s,int Length)
{
    int i=0;
    ifstream infile(file,ios::in);    
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        abort();//中止程序执行，直接从调用的地方跳出
    }
    string line ;    
    while(getline(infile,line))
    {   
        // printf("%s\n",line.data());  //输出  .c_str()
        istringstream _Readstr(line);//分割
        string token;                //接受
        int j=0;
        string ss[2];
        while(getline(_Readstr,token,','))
        {
            ss[j++]=token;
        }
        s[i].data.place=ss[1];
        s[i].data.time=ss[0];
        i++;
        if(i>Length)
        {
            cout<<"出错! 超出数组范围"<<endl;
            cout<<"已退出"<<endl;
            break;
        }
    }
    infile.close();
    return i;  
}

//文件写入函数
int Writefile(string file,Market *s,int Length)
{
    int i=0;
    fstream outfile(file,ios::out);    
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        abort();//中止程序执行，直接从调用的地方跳出
    }
    for( i=0;i<Length;i++)
    {
        outfile<<s[i].data.time<<","<<s[i].data.place<<endl;
    }
    outfile.close();
    return i;  
}


//信息输出函数
void Display(int num,Market *ss)
{
    for(int i=1;i<num;i++)
    {
        cout<<ss[i].data.place<<" \t\t"<<ss[i].data.time<<endl;
    }
}

//添加函数
int  Add(Market *s1,int Length1,Market *s2,int Length2,Market *Target,int TargetLength)
{
    if(Length1+Length2>TargetLength)
    {
        cout<<"数组超出范围"<<endl;
        return Length1+Length2;
    }
    //存储
    int i;
    for(i=1;i<Length1;i++)
    {
        Target[i-1].data.place=s1[i].data.place;
        Target[i-1].data.time=s1[i].data.time;
    }
    int j=i-1;
    for(i=1;i<Length2;i++)
    {
        Target[j+i-1].data.place=s2[i].data.place;
        Target[j+i-1].data.time=s2[i].data.time;
    }
    return Length1+Length2-2;
}

//时间排序函数
void Timesort(Market *s,int Length )
{
    //数字化
    int time[Length];
    int hour,minutes;
    int i;
    for(i=0;i<Length;i++)
    {
        istringstream _Readstr(s[i].data.time); //分割    
        string token;                           //接受
        int j=0;
        string ss[2];
        while(getline(_Readstr,token,':'))      //分割
        {
            ss[j++]=token;
        }
        hour=float(atoi(ss[0].c_str()));        //格式转换
        minutes=float(atoi(ss[1].c_str()));     //格式转换
        time[i]=hour*60+minutes;                //换算成分钟数
    }
    //选择排序
    for(i=0;i<Length;i++)
    {
        int tmp=i;
        for(int j=i;j<Length;j++)
        {
            if(time[tmp]>time[j])
            tmp=j;
        }
        //变换
        Market ss=s[i];
        s[i]=s[tmp];
        s[tmp]=ss;
        //time数组需要同步变化
        int t=time[i];
        time[i]=time[tmp];
        time[tmp]=t;
        // cout<<time[i]<<typeid(time[i]).name()<<endl;
    }
    return ;
}

int main()
{
    Market M[NUMBER],N[NUMBER];
    int length1=Readfile(f1,M,NUMBER);                          //从第一个文件读取
    int length2=Readfile(f2,N,NUMBER);                          //从第二个文件读取
    cout<<"输出所有信息:"<<endl;
    Display(length2,N);  //输出
    Display(length1,M);  //输出

    Market SortM[NUMBER*2];                                       //新数组
    int sort_length3=Add(M,length1,N,length2,SortM,NUMBER*2);     //组合新数组
    Timesort(SortM,sort_length3);                           //按时间排序
    // for(int i=0;i<sort_length3;i++)
    // cout<<SortM[i].data.place<<" \t\t"<<SortM[i].data.time<<endl;


    cout<<endl<<"查找所有地点中包含超市的记录输出: "<<endl;
    string str="Supermarket";
    Market SuperM[NUMBER*2];
    int SuperMlength=0;
    for(int i=0;i<sort_length3;i++)
        if(SortM[i].data.place.find(str)!=string::npos) //如果没有则返回npos
        {
            cout<<SortM[i].data.place<<endl;
            SuperM[SuperMlength++]=SortM[i];
        }
    
    for(int i=0;i<SuperMlength;i++)
    {
        for(int j=i+1;j<SuperMlength;j++)
        if(SuperM[i].data.place==SuperM[j].data.place)
        {
            SuperM[i].data.time+=",";
            SuperM[i].data.time+=SuperM[j].data.time;
            for(int l=j;l<SuperMlength-1;l++)                       //进行前置覆盖
            {
                SuperM[l]=SuperM[l+1];
            }
            SuperMlength--;                                         //长度缩小一个
        }
    }

    cout<<endl<<"去重:"<<endl;
    for(int i=0;i<SuperMlength;i++)
        cout<<SuperM[i].data.place<<" "<<SuperM[i].data.time<<endl;
    
    string f3="inv_superm.csv";
    Writefile(f3,SuperM,SuperMlength);
    return 0;
}





