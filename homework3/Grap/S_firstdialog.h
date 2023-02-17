#ifndef __S_FIRSTDIALOG_H
#define __S_FIRSTDIALOG_H

#include "ui_S_first.h"

class S_firstdialog:public QDialog,public Ui_S_F{
    Q_OBJECT
public:
    //构造函数
    S_firstdialog();
public slots:
    void sf_clicked(void);
};
#endif