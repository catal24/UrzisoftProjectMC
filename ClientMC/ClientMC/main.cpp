#include "ClientMC.h"
#include "Login.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    app.setQuitOnLastWindowClosed(true); // inchide aplicatia cand ultima fereastra este inchisa
    app.setWindowIcon(QIcon("resources/images/icon.ico"));  // seteaza iconita aplicatiei

    //crearea ferestrei principale (ClientMC)
    ClientMC mainWindow;
    mainWindow.setWindowIcon(QIcon("resources/images/icon.ico"));  // seteaza iconita pentru fereastra principala
    mainWindow.setWindowTitle("StarFire");  // seteaza titlul ferestrei principale

    //crearea ferestrei de logare
    Login login;
    login.setWindowTitle("Login");  // seteaza titlul ferestrei de logare
    login.setWindowIcon(QIcon("resources/images/icon.ico"));  // seteaza iconita pentru fereastra de logare

    
    QObject::connect(&login, &Login::loginSuccess, [&]() {
        mainWindow.show();  // afiseaza fereastra principala
        mainWindow.activateWindow();  // activeaza fereastra principala
        mainWindow.raise();  // pune fereastra principala deasupra altor ferestre
        login.hide();  // ascunde fereastra de logare
        });

    // afiseaza fereastra de logare
    login.show();

    // executa
    return app.exec();  
}
