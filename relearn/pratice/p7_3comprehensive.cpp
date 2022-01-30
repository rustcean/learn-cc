/**
 * schar *strcpy(char *dest,const char *src);--回传dest的地址
 * char *strncpy(char *dest,const char *src,size_t coubt);
 * char * strcat(char * destination, const char * source);
 * 會將 source 字串連接在 destination 字串後
 * 还有关于new和delete的的使用
 * 因为友元不是授权类的成员，所
 * 以它不受其所在类的声明区域public private 和protected 的影响。 
*/


#include <iostream>
#include <cstring>
using namespace std;
class String
{
    private:
    int length;//长度
    char *sPtr;//指针存放字符串
    void setString(const char *s2);///private?
    friend ostream &operator<<(ostream &os,const String &s)
    {return os<<s.sPtr;}
    friend istream &operator>>(istream &is,const String &s)
    {return is>>s.sPtr;}
    
    public:
    String(const char * ="");///赋初值的意思
    const String&operator=(const String &R)
    {
        length=R.length;
        strcpy(R.sPtr,sPtr);
        return *this;
    };
    const String &operator+=(const String &R);//重载=
    bool operator==(const String &R);//重载==
    bool operator!=(const String &R);//重载!=
    bool operator!();//重载!
    bool operator<(const String &R)const;//重载<
    bool operator>(const String &R);//重载>
    bool operator>=(const String &R);//重载>=
    char &operator[](int);//重载[],注意,引用 值可改
    ~String(){};
};
void String::setString(const char *s2)
{
    char *temp=sPtr;//指向原本的空间
    length=sizeof(s2);
    sPtr=new char[length+1];//给一个新的空间
    strcpy(sPtr,s2);//赋值
    delete [] temp;//将原本的空间delete掉
}
//函数
const String & String::operator+=(const String &R)
{
    char *temp=sPtr;//指向原本的空间
    length+=R.length;//添加长度
    sPtr=new char[length+1];//给一个新的空间
    strcpy(sPtr,temp);//将原本的值给回来
    strcat(sPtr,R.sPtr);///增加新的字符串
    delete [] temp;//将原本的空间释放
    return *this;
}
String::String(const char *str)
{
    sPtr =new char [strlen(str)+1];//给一个空间
    strcpy(sPtr,str);//拷贝
    length=strlen(str);//重新测量长度
}
bool String::operator==(const String &R){return strcmp(sPtr,R.sPtr)==0;}
bool String::operator!=(const String &R){return !(*this==R);}
bool String::operator!(){return length==0;}
bool String::operator<(const String &R)const{return strcmp(sPtr,R.sPtr)<0;}
bool String::operator>(const String &R){return R<*this;}///
bool String::operator>=(const String &R){return !(*this<R);}
char & String::operator[](int subscript){return sPtr[subscript];}

int main()
{
    String s1("happy"),s2("new year"),s3;
    cout<<"s1 is "<<s1<<"\ns2 is "<<s2<<"\ns3 is "<<s3
        <<"\n比较s2和s1: "
        <<"\ns2== s1 结果是 "<<(s2==s1?"ture":"false")
        <<"\ns2!= s1 结果是 "<<(s2!=s1?"ture":"false")
        <<"\ns2 > s1 结果是 "<<(s2>s1?"ture":"false")
        <<"\ns2 < s1 结果是 "<<(s2<s1?"ture":"false")
        <<"\ns2>= s1 结果是 "<<(s2>=s1?"ture":"false");
    cout<<"\n\n测试s3是否为空:";
    if(!s3)
    {
        cout<<"s3是空串"<<endl;
        cout<<"把s1的值赋给s3的结果是:";
        s3=s1;
        cout<<"s3="<<s3<<"\n" ; 
    }
    cout<<"s1+=s2的结果是:";
    s1+=s2;
    cout<<"s1="<<s1<<endl;

    cout<<"s1+= to you 的结果是:";
    s1+=" to you";
    cout<<"s1="<<s1<<endl;
    s1[0]='H';
    s1[6]='N';
    s1[10]='Y';
    cout<<"s1="<<s1<<endl;
    return 0;
}