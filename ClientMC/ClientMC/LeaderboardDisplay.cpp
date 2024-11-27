#include "LeaderboardDisplay.h"
#include <QLabel>

LeaderboardDisplay::LeaderboardDisplay(QWidget* parent)
	:QWidget(parent)
{
	this->setWindowTitle("Leaderboard");
	this->setFixedSize(800, 600);
	this->setContentsMargins(20, 20, 20, 20);
	gridLayout = new QGridLayout(this);
	QLabel* n1 = new QLabel("1", this);
	gridLayout->addWidget(n1, 0, 0);


	setLayout(gridLayout);
}

LeaderboardDisplay::~LeaderboardDisplay()
{}
