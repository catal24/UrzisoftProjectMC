#include "ClientMC.h"
#include <QPushButton>
#include "MovementInfoDisplay.h"
#include "LeaderboardDisplay.h"
ClientMC::ClientMC(QWidget *parent)
    : QMainWindow(parent)
{

	this->setWindowTitle("Menu");
	this->setFixedSize(800, 600);

    m_infoButton = new QPushButton("INFO",this);
	m_infoButton->setGeometry(25, 25, 50, 50);
	m_leaderboardButton = new QPushButton("", this);
	m_leaderboardButton->setGeometry(725, 25, 50, 50);

	connect(m_infoButton, &QPushButton::clicked, this, [&]() {
		MovementInfoDisplay* infoWindow = new MovementInfoDisplay(this);  // Creează instanța ferestrei
		infoWindow->setAttribute(Qt::WA_DeleteOnClose);
		infoWindow->show();  // Deschide fereastra
		m_infoButton->hide();
		m_leaderboardButton->hide();
		});
	connect(m_leaderboardButton, &QPushButton::clicked, this, [&]() {
		LeaderboardDisplay* leaderboardWindow = new LeaderboardDisplay(this); 
		leaderboardWindow->setAttribute(Qt::WA_DeleteOnClose);
		leaderboardWindow->show();
		m_infoButton->hide();
		m_leaderboardButton->hide();
		});
	
}

ClientMC::~ClientMC()
{}
