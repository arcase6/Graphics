// SandboxGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <QtWidgets/qapplication.h>


int main(int argc, char* argv[])
{
    std::cout << "Starting QT\n";
	QApplication application(argc, argv);
	std::cout << "Finished creation";
	return application.exec();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu