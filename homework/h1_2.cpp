/*排序*/
 #include <iostream>
 #include <cstring>
 using namespace std;
 int main()
 {
    string array;
    cin>>array;
    cout<<array<<endl;
    int i=strlen(std::array);
    for(int j=0;j<i/2;j++,i--)
    {
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
    cout<<array<<endl;

 }