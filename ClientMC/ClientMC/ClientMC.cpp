#include "ClientMC.h"
#include <QPushButton>
#include "MovementInfoDisplay.h"
#include "LeaderboardDisplay.h"
//#include <QCoreApplication>
#include <QCloseEvent>
#include <QVBoxLayout>

ClientMC::ClientMC(QWidget *parent)
    : QMainWindow(parent)
{
	this->setStyleSheet("QMainWindow {"
		"   background-image: url(resources/images/wallpaper.jpg);"// path to wallpaper
		"   background-repeat: no-repeat;"
		"   background-position: center;"
		"   background-size: cover;"// resize wallpaper 
		"}");

	this->setWindowTitle("Menu");
	this->setFixedSize(800, 600);

    m_infoButton = new QPushButton(this);
	setupButtonWithImage(m_infoButton, 25, 25, 50, 50, "resources/images/infoButton.png");

	m_leaderboardButton = new QPushButton(this);
	setupButtonWithImage(m_leaderboardButton, 25, 80, 50, 50,"resources/images/rankButton.png");


	m_findGame = new QPushButton("Find Game",this);
	m_findGame->setGeometry( 350, 275, 100, 50);
	m_findGame->setStyleSheet(
		"QPushButton {"
		"    background-color: #3498db;"
		"    color: white;"
		"    border: 2px solid #2980b9;"
		"    border-radius: 10px;"
		"    font-size: 16px;"
		"    padding: 10px;"
		"}"
		"QPushButton:hover {"
		"    background-color: #2980b9;"
		"}"
		"QPushButton:pressed {"
		"    background-color: #1c5985;"
		"}"
	);


	m_mapSelector = new QPushButton(this);
	setupButtonWithImage(m_mapSelector, 725, 25, 50, 50,"resources/images/mapSelector.png");

	m_upgrade = new QPushButton(this);
	setupButtonWithImage(m_upgrade, 725, 80, 50, 50, "resources/images/upgrade.png");

	connect(m_findGame, &QPushButton::clicked, this, [&]() {
		qDebug() << "Find Game button clicked!";
		});

	


	connect(m_infoButton, &QPushButton::clicked, this, [&]() {
		MovementInfoDisplay* infoWindow = new MovementInfoDisplay(this);  
		infoWindow->setAttribute(Qt::WA_DeleteOnClose);
		infoWindow->show();
		toggleBButtons(false);

		connect(infoWindow, &MovementInfoDisplay::backButtonClicked, this, [=]() {
			infoWindow->close();         
			toggleBButtons(true);
		});
	});

	connect(m_leaderboardButton, &QPushButton::clicked, this, [&]() {
		LeaderboardDisplay* leaderboardWindow = new LeaderboardDisplay(this); 
		leaderboardWindow->setAttribute(Qt::WA_DeleteOnClose);
		leaderboardWindow->show();
		toggleBButtons(false);

		connect(leaderboardWindow, &LeaderboardDisplay::backButtonClicked, this, [=]() {
			leaderboardWindow->close();
			toggleBButtons(true);
		});
	});
	
}

ClientMC::~ClientMC()
{}

void ClientMC::closeEvent(QCloseEvent * event)
{
	QCoreApplication::quit();
	event->accept();
}



void ClientMC::toggleBButtons(bool visible)
{
	m_findGame->setVisible(visible);
	m_infoButton->setVisible(visible);
	m_leaderboardButton->setVisible(visible);
	m_upgrade->setVisible(visible);
	m_mapSelector->setVisible(visible);
}


void ClientMC::setupButtonWithImage(QPushButton* button, int x, int y, int width, int height,const std::string& imagePath)
{
	button->setGeometry(x, y, width, height);
	button->setStyleSheet(
		"QPushButton {"
		"   border-radius: 25px;"
		"   background: transparent;"
		"    background-image: url(" +QString::fromStdString(imagePath) +"); "
		"    background-repeat: no-repeat;"
		"    background-position: center;"
		"}"
	);
}