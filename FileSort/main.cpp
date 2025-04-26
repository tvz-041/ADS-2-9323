#include "FileSortWidget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileSortWidget w;
    w.show();
    return a.exec();
}
