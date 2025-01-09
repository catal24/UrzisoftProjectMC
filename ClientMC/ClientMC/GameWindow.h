#pragma once
#include <QWidget>
class GameWindow: public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = nullptr);
    ~GameWindow();

};

