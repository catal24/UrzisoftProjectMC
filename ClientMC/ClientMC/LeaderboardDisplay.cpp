#include "LeaderboardDisplay.h"

LeaderboardDisplay::LeaderboardDisplay(QWidget* parent)
	:QWidget(parent)
{
	this->setWindowTitle("Leaderboard");
	this->setFixedSize(800, 600);
	m_table = new QTableWidget(5,2,this);
	m_table->setHorizontalHeaderLabels(QStringList() << "Name" << "Points");
	m_table->horizontalHeader()->setStretchLastSection(true);
	m_table->verticalHeader()->setVisible(true);
	m_table->setShowGrid(true);

	m_table->setItem(0, 0, new QTableWidgetItem("1"));
	m_table->setItem(0, 1, new QTableWidgetItem("2"));
	m_table->setItem(1, 0, new QTableWidgetItem("3"));
	m_table->setItem(1, 1, new QTableWidgetItem("4"));
	m_table->setItem(2, 0, new QTableWidgetItem("5"));
	m_table->setItem(2, 1, new QTableWidgetItem("6"));
	m_table->setItem(3, 0, new QTableWidgetItem("7"));
	m_table->setItem(3, 1, new QTableWidgetItem("8"));
	m_table->setItem(4, 0, new QTableWidgetItem("9"));
	m_table->setItem(4, 1, new QTableWidgetItem("10"));


	auto layout = new QVBoxLayout(this);
	layout->addWidget(m_table);
	layout->setContentsMargins(20, Qt::AlignVCenter, 20, 20);
	QPushButton* backButton = new QPushButton("Back", this);
	QVBoxLayout* layoutButton = new QVBoxLayout(this);
	layoutButton->addWidget(backButton,0,Qt::AlignRight);
	connect(backButton, &QPushButton::clicked, this, &LeaderboardDisplay::backButtonClicked);
	connect(backButton, &QPushButton::clicked, this, [&]() {
		this->hide();

		});
	layout->addLayout(layoutButton);

	setLayout(layout);
}

LeaderboardDisplay::~LeaderboardDisplay()
{}
