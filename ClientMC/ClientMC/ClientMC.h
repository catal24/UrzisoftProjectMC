#pragma once
#include <QPushButton>

#include <QtWidgets/QMainWindow>


class ClientMC : public QMainWindow
{
    Q_OBJECT

public:
    ClientMC(QWidget *parent = nullptr);
    ~ClientMC();

private:
    QPushButton* infoButton;
	QPushButton* leaderboardButton;
};
