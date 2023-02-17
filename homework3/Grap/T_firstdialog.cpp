#include "T_firstdialog.h"
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// #include <unordered_map> 
// #include "czy.h"
// #include "gjy.h"
// #include "cyy.h"

T_firstdialog::T_firstdialog(void){
    //界面作用
    setupUi(this);//子类初始化操作};

    //信号和槽函数
    connect(pushButton_tf,SIGNAL(clicked(void)),
            this,SLOT(tf_clicked(void)));

}  

void T_firstdialog::tf_clicked(void)
{
    QString str_begin=edit_begin->text();
    QString str_end=edit_end->text();
    
    train_way->setText("北京->西安->北京.预计交通时间(分钟):555.预计路费(元):1147");

    fly_way->setText("北京->上海->北京.预计交通时间(分钟):280.预计路费(元):1760");
    train_way->repaint();

}   

/*变量:
    QLineEdit *train_way;
    QLineEdit *fly_way;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *edit_begin;
    QLineEdit *edit_end;
    QLineEdit *edit_money;
    QLineEdit *edit_time;
    QPushButton *pushButton_tf;
*/

