//第一个qt程序--了解开发过程
#include <QApplication>
#include <QLabel>
using namespace std;
int main(int argc,char **argv )
{
    //创建qt应用程序对象
    QApplication app(argc,argv);
    //创建标签控件
    QLabel label("Hello Qt!");
    
    //显示
    label.show();

    //让应用程序进入事件循环
    return app.exec();
}
