#ifndef __LOGINDIALOG_H
#define __LOGINDIALOG_H

#include "ui_LoginDialog.h"
#include <QMessageBox>//消息提示框
#include <QDebug> //打印提示

class LoginDialog:public QDialog,public Ui_LoginDialog{
    Q_OBJECT  //语法宏
    //构造函数
    public:
    LoginDialog(void);
    public slots:
    //处理ok按钮
    void onAccepted(void);
    //处理cancle按钮
    void onRejected(void);
};

#endif