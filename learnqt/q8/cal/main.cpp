#include "caldialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalDialog w;
    w.show();
    return a.exec();
}
