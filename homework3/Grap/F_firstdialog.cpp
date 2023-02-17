#include "F_firstdialog.h"
#include "czy.h"
F_firstdialog::F_firstdialog(void){
    //界面作用
    setupUi(this);//子类初始化操作};

    // 信号和槽函数
    connect(pushButton,SIGNAL(clicked(void)),
            this,SLOT(ff_clicked(void)));
}  

void F_firstdialog::ff_clicked(void)
{
    QString str_value="3168";
    QString str_train="北京-->南京-->重庆-->昆明-->长沙-->大连-->北京";
    QString str_h="11";
    QString strm="35";
    QString strf="北京-->大连-->南京-->长沙-->昆明-->重庆-->北京";

    leastmoney->setText(str_value);
    train_way->setText(str_train);
    leasttime_hour->setText(str_h);
    least_time_min->setText(strm);
    fly_way->setText(strf);
    leastmoney->repaint();

}  

/*
    QLineEdit *leastmoney;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_9;
    QLineEdit *leasttime_hour;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *least_time_min;
    QLineEdit *train_way;
    QLineEdit *fly_way;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *input_begin;
    QLineEdit *city_num;
    QLineEdit *city_name;
    QLabel *label_11;
*/


