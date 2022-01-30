#include <iostream>
using namespace std;
class Apple
{
    public:
    static void printMsg()
    {
        cout<<"Welcome!"<<endl;
    }
};
//main function
int main()
{
    //invoking a static member function
    Apple::printMsg();//不需特地创建对象
    return 0;
}