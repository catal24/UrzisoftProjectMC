#pragma once
#include <QPushButton>
#include <QtWidgets/QMainWindow>



class ClientMC : public QMainWindow
{
    Q_OBJECT

public:
    ClientMC(QWidget *parent = nullptr);
    ~ClientMC();

protected:
    void closeEvent(QCloseEvent* event)override;

private:
    void toggleBButtons(bool visible);
private:
    QPushButton* m_findGame;
    QPushButton* m_infoButton;
	QPushButton* m_leaderboardButton;
    QPushButton* m_mapSelector;
    QPushButton* m_upgrade;
};
