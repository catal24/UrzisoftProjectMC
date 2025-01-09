#include "GameWindow.h"
#include <QPainter>
#include <QTimer>

GameWindow::GameWindow(QWidget* parent)
    : QWidget(parent)
{
    // Setează dimensiunea și titlul ferestrei
    this->showFullScreen();
    this->setWindowTitle("STARFIRE");

    //negru pentru test
    this->setStyleSheet("background-color: black;");
    //windowed fullscreen 
    this->setWindowFlags(Qt::FramelessWindowHint);  
    this->setWindowState(Qt::WindowFullScreen);     
    this->show();

    //butoanele pentru a putea inchide a minimiza si a maximiza fereastra
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint);
    setWindowState(Qt::WindowNoState);

    QTimer* gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, [&]() {
        
        update();  
        });
    gameTimer->start(16);  
}

GameWindow::~GameWindow() {
   
}
