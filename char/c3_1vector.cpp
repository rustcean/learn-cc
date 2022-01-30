#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i=0;
    vector <int> a;
    for(i=0;i<5;i++)
        a.push_back(i);//输入i对应的值给a对应的位置
    a.insert(a.begin()+2,10);//插入10到a的第三个位置,其他值会往后排
    for(i=0;i<5+1;i++)
        cout<<a[i]<<" ";//可以以下标的方式输出
    cout<<endl;
    a.erase(a.begin()+2);//擦除掉第二个元素
    for(i=0;i<5;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    //注意,下面第一个a.+2是擦除其所在的第三个元素,第二个是擦除其所在的第三个元素
    //也就是原来的第四个元素
    a.erase(a.begin()+2,a.begin()+2);//擦除第三和第5的元素  
    //注意下标的使用,如果大于a的大小,也会输出,但这是不好的
    for(i=0;i<3;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}