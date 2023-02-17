#ifndef F_FIRSTDIALOG_H
#define F_FIRSTDIALOG_H

#include "ui_F_first.h"

class F_firstdialog:public QDialog, public Ui_F_F{
    Q_OBJECT
    public:
    F_firstdialog();

    public slots:
    void ff_clicked(void);//功能函数

    //链接函数  
};


#endif