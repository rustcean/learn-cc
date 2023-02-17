#include "LoginDialog.h"
LoginDialog::LoginDialog(void)
{
    //父类构造--界面初始化
    setupUi(this);
    //信号和槽链接
    //点击ok发送信号accepted
    connect(m_buttonBox,SIGNAL(accepted(void)),
            this,SLOT(onAccepted(void)));
    //点击Cancle
    connect(m_buttonBox,SIGNAL(rejected(void)),
            this,SLOT(onRejected(void)));
}
//
void LoginDialog::onAccepted(void)
{
    //假设名字密码-tarena/123456
    if(m_usernameEdit->text()== "tarena" &&
        m_passwordEdit->text()=="123456"){
            qDebug()<<"登录成功";
        close();//关闭登录窗口
        }
    else{
        QMessageBox msgBox(
            QMessageBox::Critical,  //图标风格
            "Error",                //标题
            "用户名或者密码错误",      //提示消息
            QMessageBox::Ok,        //按钮
            this);//父窗口
        msgBox.exec();//显示消息提示框并进入事件循环
    }

}
//处理cancle按钮
void LoginDialog::onRejected(void)
{
    //询问是否取消
    QMessageBox msgBox(
        QMessageBox::Question,
        "登录",
        "是否确定取消登录?",
        QMessageBox::Yes|QMessageBox::No,
        this);
    //显示并进入事件循环--没有close()-即不关闭
    if(msgBox.exec() == QMessageBox::Yes){
        close();//若选择Yes,此时关闭
    }

}