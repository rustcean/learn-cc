#include <QApplication>
#include <QLabel>
#include <QPushButton>

//转换格式用的头文件
#include <QTextCodec>
int main(int argc, char **argv)
{
    QApplication app(argc,argv);

    //创建编码对象
    QTextCodec* coder=QTextCodec::codecForName("utf-8");

    QLabel label(coder->toUnicode("标签对象"));
    label.show();

    QPushButton button(coder->toUnicode("按钮对象"));
    button.show();

    return app.exec();

}







