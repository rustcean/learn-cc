/*排序*/
 #include <iostream>
 #include <cstring>
 using namespace std;
 int main()
 {
    string array;
    cin>>array;//读不了空格
    cout<<array<<endl;
    int i=array.size();//
    cout<<i<<endl;
    int reverse(string *a,int i);
    reverse(&array,i);
    cout<<array<<endl;
return 0;
 }
 int reverse(string *a,int i)
 {
     int b=i/2;
     for(int j=0;j<b;j++,i--)
    {
        string temp=*(a+j);
        *(a+j)=*(a+i);
        *(a+i)=temp;
    }  
    return 0;  
 }