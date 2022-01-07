#include <iostream>
 
// overloading "operator = " outside class
// < 和 > 是二元操作符
 
//////////////////////////////////////////////////////////
 
class Rectangle
{
public:
    Rectangle(int w, int h)
        : width(w), height(h)
    {};
 
    ~Rectangle() {};
 
 
    bool operator< (Rectangle& rec);//注意比较的顺序。this是被比的对象。
    bool operator> (Rectangle& rec);
 
 
 
public:
    int width;
    int height;
};
 
 
bool
Rectangle::operator< (Rectangle & rec)//相同的class对象互为友元，所以可以访问private对象。< 是二元操作符，class内隐藏了this
{
    return this->height * this->width < rec.height * rec.width;
}
 
bool
Rectangle::operator> (Rectangle & rec)//二元操作符，class内隐藏了this
{
    return !(*this < rec);
}
 
//////////////////////////////////////////////////////////
 
int main()
{
    Rectangle a(40, 10);
    Rectangle b(40, 56);
 
    std::cout << (a < b) << std::endl;
    std::cout << (a > b) << std::endl;
 
    return 0;
}