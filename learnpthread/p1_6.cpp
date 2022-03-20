//个人实践
#include <iostream>
#include <string>
#include <pthread.h>
using namespace std;
struct Sd
{
    int num;
    char *name;
    string a;
};

void *thread(void *id)
{
    Sd *s;
    s=(Sd *)id;
    cout<<"姓名: "<<s->name<<endl;
    cout<<" 学号: "<<s->num<<endl;
    cout<<"开销:  "<<s->a<<endl;
    pthread_exit(NULL);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pthread_t num[4];
    Sd s[4];
    for(int i=0;i<4;i++)
    {
        s[i].num=i+2;
        s[i].name=(char *)"heel";
        s[i].a=s[i].name;
        int rc=pthread_create(&num[i],NULL,thread,(void *)&s[i]);
        if(rc)
        {
            cout<<"出错!"<<endl;
        }
    }
    pthread_exit(NULL);
    return 0;   
}