#ifndef __MAINGRAP_H
#define __MAINGRAP_H

//菜单栏窗口
#include "ui_Grap.h"
//子窗口
#include "F_firstdialog.h"
#include "S_firstdialog.h"
#include "T_firstdialog.h"

//继承
class MainGrap:public QDialog,public Ui_Dialog {
    Q_OBJECT
public:
    //构造函数
    MainGrap(void);
    //选择用的变量
    F_firstdialog *firstDialog; //第一个子窗口指针
    S_firstdialog *secondDialog;//第二个子窗口
    T_firstdialog *thirdDialog; //第三个子窗口
public slots:
    //按钮功能曹函数
    void f_clicked(void);    //第一个功能
    void s_clicked(void);    //第二个功能
    void t_clicked(void);    //第三个功能
    void e_clicked(void);    //退出
};





#endif