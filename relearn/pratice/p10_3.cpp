#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream iofile;
    iofile.open("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::out);
    iofile<<"张三"<<" "<<76<<" "<<98<<" "<<67<<endl;
    iofile<<"李四"<<" "<<89<<" "<<70<<" "<<60<<endl;
    iofile<<"王五"<<" "<<91<<" "<<88<<" "<<77<<endl;
    iofile<<"黄二"<<" "<<62<<" "<<81<<" "<<75<<endl;
    iofile<<"刘六"<<" "<<90<<" "<<78<<" "<<67<<endl;
    iofile.close();
    iofile.open("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::in|ios::binary);
    char name[10];
    int chinese,math,computer;
    cout<<"姓名\t中文\t数学\t计算机\t总分"<<endl;
    iofile>>name;
    while(!iofile.eof())
    {
        iofile>>chinese>>math>>computer;
        cout<<name<<"\t"<<chinese<<"\t"<<math<<"\t"<<computer<<"\t"
        <<chinese+math+computer<<endl;
        iofile>>name;
    }
    iofile.close();


}