#include "ClientMC.h"
#include "Login.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setQuitOnLastWindowClosed(true); // Închide aplicația când ultima fereastră este închisă

    QMainWindow* window = new QMainWindow;
    ClientMC mainWindow(window);
	

    Login login;
	login.setWindowTitle("Login");

    QObject::connect(&login, &Login::loginSuccess, [&]() {
        login.close();          // Inchide fereastra de login
        mainWindow.show();      // Deschide fereastra principala
        });

    login.show();
    return app.exec();
    
}
