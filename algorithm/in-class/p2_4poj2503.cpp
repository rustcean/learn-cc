//北京大学-2503
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
class node
{
    public:
    node* ch[28];
    char str[12];
    node()
    {
        memset(ch,NULL,sizeof(ch));
        memset(str,'\0',sizeof(str));
    }
};
node *root;//外部 头指针

void inset(char *str1,char *str2)//建树
{
    int length=strlen(str1);
    node *temp=root;
    for(int i=0;i<length;i++)
    {
        if(temp->ch[str1[i]-'a']==NULL)//该位置为空,new一个
        {
            temp->ch[str1[i]-'a']=new node();
            temp=temp->ch[str1[i]-'a'];
        }
        else temp=temp->ch[str1[i]-'a'];
        if(i==length-1)
            strcpy(temp->str,str2);
    }
}

void finds(char *str)
{
    int length=strlen(str);
    node *temp=root;
    for(int i=0;i<length;i++)
    {   
        if(temp->ch[str[i]-'a']!=NULL)
        {
            temp=temp->ch[str[i]-'a'];
        }
        else
        {
            printf("eh\n");
            return ;
        }
    }
    printf("%s\n",temp->str);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char str1[15],str2[15],str[30];
    int i,j;
    root=new node();
    while(cin.get(str,15))
    {
        if(strlen(str)==0)//r如果空行
        break;
        i=0;j=0;
        while(str[i]!=' ')
            str1[j++]=str[i++];
        str1[j]='\0';i++;
        j=0;
        while(str[i]!='\0')
            str2[j++]=str[i++];
        str2[j]='\0';
        inset(str2,str1);
    }
    while(scanf("%s",str));
    {
        finds(str);
    }
    return 0;
}