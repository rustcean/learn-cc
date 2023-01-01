#include <QApplication>
#include "calculatordialog.h"
int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    
    Calculatordialog calc;
    calc.show();
    return app.exec();
}