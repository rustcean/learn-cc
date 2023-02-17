#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

int main(int argc,char **argv)
{
    //开始使用
    QApplication app(argc,argv);

    //显示类 
    QDialog parent;
    //

    parent.show();


    return app.exec();
}