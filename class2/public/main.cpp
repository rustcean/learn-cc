#include "project.cpp"

int main()
{
    Student1 s1;
    cout<<"依次输入数字,姓名,性别:XX XX XX"<<endl;
    s1.get_value();
    cout<<"依次输入年龄,住址:XX XX"<<endl;
    s1.get_value_1();
    s1.display_1();
    return 0;
}