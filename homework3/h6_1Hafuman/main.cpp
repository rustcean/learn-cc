#include "main.h"
using namespace std;
int main()
{
    string filename;
    cout<<"请输入进行编码的文件名: "<<endl;
    cin>>filename;
    ifstream infile(filename,ios::in);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    int length_code;//编码数据长度
    string str;//保存行数据
    getline(infile,str);
    length_code=atoi(str.c_str());//转int
    getline(infile,str);
    string str1="";
    string arrstr[length_code+1];//放字符,加一个单位,虽然没必要
    int i,j=0;
    for(i=0;i<str.length();i++)
    {
        if(str[i]!=',')
            str1+=str[i];
        else
        {
            arrstr[j++]=str1;
            str1="";
        }
    }
    str1="";
    j=0;
    int arrint[length_code+1];//放频率
    getline(infile,str);
    for(i=0;i<str.length();i++)
    {
        if(str[i]!=',')
            str1+=str[i];
        else
        {
            arrint[j++]=atoi(str1.c_str());
            str1="";
        }
    }
    infile.close();
    // // 输出检验
    // for(int i=0;i<length_code;i++) cout<<arrint[i]<<",";;
    // cout<<endl;
    // for(int i=0;i<length_code;i++) cout<<arrstr[i];
    // cout<<endl;
    
    //创建树
    HFTree t;
    t.createHFTree(arrstr,arrint,length_code);
    cout<<"树的结构: "<<endl;    
    t.printHFTree();//输出数组
    //存储
    cout<<"输入树存储的文件名:"<<endl;
    cin>>filename;
    ofstream outfile(filename,ios::out);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    string str_HF=t.printF();
    outfile<<str_HF;
    outfile.close();
    
    //创建哈夫曼表
    t.CreateHFCode();
    //进行编码
    cout<<"请输入待编码的文件名: "<<endl;
    cin>>filename;
    ifstream infile2(filename,ios::in);
    if(!infile2)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    string str_test;
    getline(infile2,str_test) ;        //读取一行
    string a=t.Encodestr(str_test);    //编码
    cout << "编码结果:" << endl;
    cout<<a<<endl;
    cout<<"请输入编码结果储存的文件名:"<<endl;
    cin>>filename;
    ofstream outfile2(filename,ios::out);
    if(!outfile2)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    outfile2<<a;
    outfile2.close();
    infile2.close();

    //解码
    string b=t.Decode(a);
    cout<<"解码结果:"<<endl;
    cout<<b<<endl;
    cout<<"请输入解码结果储存的文件名:"<<endl;
    cin>>filename;
    ofstream outfile3(filename,ios::out);
    if(!outfile3)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    outfile3<<b;
    outfile3.close();

    //print
    cout<<endl<<"下面展示代码:"<<endl;
    for(i=0;i<a.length();i++)
    {
        cout<<a[i];
        if(i>0 && i%50==0)
            cout<<endl;
    }
    cout<<endl;
    cout<<"接下来将结果存储,请输入文件名:"<<endl;
    cin>>filename;
    ofstream outfile4(filename,ios::out);
    if(!outfile4)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<a.length();i++)
    {
        outfile4<<a[i];
        if(i>0 && i%50==0)
            outfile4<<"\n";
    }
    outfile4.close();
    cout<<"树的结构存在hafuman"<<endl;
    cout<<"结束！"<<endl;
    return 0;
}



