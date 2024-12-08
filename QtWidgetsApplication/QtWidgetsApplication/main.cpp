#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include "qmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication w;
    w.show();
    return a.exec();
}
