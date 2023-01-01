//信号和槽
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    
    QDialog parent;//父窗口
    parent.resize(320,240);

    QLabel label("我是标签",&parent);
    label.move(50,40);
    QPushButton button("我是按钮",&parent);
    button.move(50,140);
    QPushButton button2("退出",&parent);
    button2.move(150,140);
    parent.show();
    //点击按钮关闭标签
    QObject::connect(&button,SIGNAL(clicked(void)),
                &label,SLOT(close(void)));
    //点击按钮退出
    QObject::connect(&button2,SIGNAL(clicked(void)),
                &app,SLOT(closeAllWindows()));//quit(void)
    return app.exec();

}