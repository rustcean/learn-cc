#ifndef __LOGINDIALOG_H
#define __LOGINDIALOG_H

#include "ui_LoginDialog.h"
#include <QMessageBox>//消息提示框
#include <QDebug> //打印提示
//组合方式
class LoginDialog:public QDialog{
    Q_OBJECT  //语法宏
    //构造函数
    public:
    LoginDialog(void);
    ~LoginDialog(void); //组合是动态创建的需要西沟函数进行删除delete
    public slots:
    //处理ok按钮
    void onAccepted(void);
    //处理cancle按钮
    void onRejected(void);
    private:
    Ui::LoginDialog* ui;

};

#endif