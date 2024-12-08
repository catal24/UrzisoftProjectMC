#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include "GameWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameWidget gameWidget;
    gameWidget.resize(800, 600);
    gameWidget.show();
    
    return app.exec();
}
