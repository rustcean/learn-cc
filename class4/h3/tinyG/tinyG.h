#pragma once

#include <QtWidgets/QMainWindow>
#include <QApplication>  
#include <QPushButton>  
#include <QTextEdit>  
#include <QVBoxLayout>  
#include <QWidget>  
#include "ui_tinyG.h"

class tinyG : public QMainWindow
{
    Q_OBJECT

public:
    tinyG(QWidget *parent = nullptr);
    ~tinyG();

private:
    Ui::tinyGClass ui;
    //¹¦ÄÜº¯Êý
    void buttonClicked();


    //
private:
    QPushButton* button1;
    QPushButton* button2;
    QTextEdit* textEdit;
    QVBoxLayout* layout;

};
