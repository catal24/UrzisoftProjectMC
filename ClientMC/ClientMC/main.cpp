#include "ClientMC.h"
#include "Login.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Login login;
    QMainWindow* window = new QMainWindow;
    ClientMC mainWindow(window);
	mainWindow.setWindowTitle("Menu");
	login.setWindowTitle("Login");

    QObject::connect(&login, &Login::loginSuccess, [&]() {
        login.close();          // Închide fereastra de login
        mainWindow.show();      // Deschide fereastra principală
        });

    login.show();
    return app.exec();
    
}
