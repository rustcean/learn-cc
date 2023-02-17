#define _CRT_SECURE_NO_WARNINGS
#include "MainGrap.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    //菜单栏
    MainGrap mainwindow;
    mainwindow.show();//进入菜单栏
	
	//结束
	return app.exec();
}


