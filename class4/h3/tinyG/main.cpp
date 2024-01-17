#include "tinyG.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tinyG w;
    w.show();
    return a.exec();
}
