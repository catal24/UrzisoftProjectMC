#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QBoxLayout>

class LeaderboardDisplay : public QWidget
{
	Q_OBJECT

public:
	explicit LeaderboardDisplay(QWidget* parent = nullptr);
	~LeaderboardDisplay();
private:
	QTableWidget* m_table;
};

