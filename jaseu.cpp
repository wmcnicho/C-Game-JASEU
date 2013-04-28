#include <QtGui/QApplication>
#include "jaseuwindow.h"

/** @mainpage CSCI 102 PA #5
@section purpose Purpose/Overview
This is da game!!
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JaseuWindow w;

    w.show();

    return a.exec();
}
