#include "ClientMC.h"
#include "Login.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setQuitOnLastWindowClosed(true); // Închide aplicația când ultima fereastră este închisă
    app.setWindowIcon(QIcon("resources/images/icon.ico"));

    ClientMC mainWindow;
    mainWindow.setWindowIcon(QIcon("resources/images/icon.ico"));
    mainWindow.setWindowTitle("StarFire");
	

    Login login;
	login.setWindowTitle("Login");
    login.setWindowIcon(QIcon("resources/images/icon.ico"));

    QObject::connect(&login, &Login::loginSuccess, [&]() {
        mainWindow.show();
        mainWindow.activateWindow();
        mainWindow.raise();
        login.hide();
        });

    login.show();
    return app.exec();
    
}
