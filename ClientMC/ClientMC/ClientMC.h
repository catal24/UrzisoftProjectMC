#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClientMC.h"

class ClientMC : public QMainWindow
{
    Q_OBJECT

public:
    ClientMC(QWidget *parent = nullptr);
    ~ClientMC();

private:
    Ui::ClientMCClass ui;
};
