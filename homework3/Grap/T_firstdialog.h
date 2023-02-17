#ifndef __T_FIRSTDIALOG_H
#define __T_FIRSTDIALOG_H


#include "ui_T_first.h"

class T_firstdialog:public QDialog,public Ui_T_F{
    Q_OBJECT
public :
    //构造函数
    T_firstdialog();
public slots:
    //按钮功能
    void tf_clicked(void);//输出数据

};


#endif