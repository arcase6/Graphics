// SandboxGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <QtWidgets/qapplication.h>
#include "GLWindow.h"


int main(int argc, char* argv[])
{
    std::cout << "Starting QT\n";
	QApplication application(argc, argv);
	//QWidget myWidget;
	//myWidget.show();
	GLWindow myWindow;
	myWindow.show();

	return application.exec();
}