#include "MainGrap.h"

MainGrap::MainGrap(void)
{
    //界面作用
    setupUi(this);//子类初始化操作

    //信号和槽函数
    connect(Button_1,SIGNAL(clicked(void)),
        this,SLOT(f_clicked(void)));
    connect(Button_2,SIGNAL(clicked(void)),
        this,SLOT(s_clicked(void)));
    connect(Button_3,SIGNAL(clicked(void)),
        this,SLOT(t_clicked(void)));
    connect(Button_exit,SIGNAL(clicked(void)),
        this,SLOT(e_clicked(void)));

}
//1.
void MainGrap::f_clicked(void)
{
    //开启子窗口1
    firstDialog=new F_firstdialog;
    firstDialog->show();    
}
//2.
void MainGrap::s_clicked(void)
{
    //开启子窗口2
    secondDialog=new S_firstdialog;
    secondDialog->show();    
}
//3.
void MainGrap::t_clicked(void)
{
    //开启子窗口3
    thirdDialog=new T_firstdialog;
    thirdDialog->show();
}
//4.退出
void MainGrap::e_clicked(void)
{
    //关闭窗口
    close();
}



