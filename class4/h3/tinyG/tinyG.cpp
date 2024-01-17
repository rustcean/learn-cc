#include "tinyG.h"
#include <iostream>
using namespace std;

tinyG::tinyG(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    button1 = new QPushButton("Button 1");
    button2 = new QPushButton("Button 2");
    textEdit = new QTextEdit();
    layout = new QVBoxLayout();

    connect(button1, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(button2, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(textEdit);

    setLayout(layout);

}

void tinyG::buttonClicked() {
    std::cout << "Button clicked!" << std::endl;
}

tinyG::~tinyG()
{}

