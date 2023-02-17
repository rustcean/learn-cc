#include "S_firstdialog.h"

// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// #include <unordered_map> 
// #include "czy.h"
// #include "gjy.h"
// #include "cyy.h"

//构造函数
S_firstdialog::S_firstdialog(void)
{
    //界面作用
    setupUi(this);//子类初始化操作

    //信号和槽函数
    connect(pushButton,SIGNAL(clicked(void)),
            this,SLOT(sf_clicked(void)));
}
void S_firstdialog::sf_clicked(void)
{
    QString way="昆明-->广州-->大连";
    textEdit_way->setText(way);
    textEdit_way->repaint();
}
//功能函数--点击后要链接另外两个函数

