#ifndef __CLACULATORDIALOH_H
#define __CLACULATORDIALOH_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit> //行编辑控件
#include <QHBoxLayout>//水平布局器
#include <QDoubleValidator>//验证器

class Calculatordialog:public QDialog{
        Q_OBJECT //moc  语法扩展需要-自定义槽函数
    public:
        Calculatordialog(void);
    public slots://槽函数
        //使能等号按钮的槽操作数
        void enableButton(void);
        //计算结果和现实的槽函数
        void calClicked(void);
    private:
        QLineEdit* m_editX;//左操作数
        QLineEdit* m_editY;//右操作数
        QLineEdit* m_editZ;//显示结果
        QLabel* m_label;//"+"
        QPushButton* m_button;//"="
};


#endif


