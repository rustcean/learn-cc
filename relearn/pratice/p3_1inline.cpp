/*内联函数,设置为内联时,执行速度较快,但函数应该尽量小,因为占的不是普通的位置
 *

*/
#include <iostream>
using namespace std;
inline double CalArea(double radius);
int main()
{
    double r(3.0);
    double area;
    area=CalArea(r);
    cout<<"area:"<<area<<endl;
    return 0;
}
inline double CalArea(double radius)
{
    return 3.14*radius*radius;
}