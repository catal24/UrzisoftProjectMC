#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QBoxLayout>
#include <QPushButton>

class LeaderboardDisplay : public QWidget
{
	Q_OBJECT

public:
	explicit LeaderboardDisplay(QWidget* parent = nullptr);
	~LeaderboardDisplay();
signals:
	void backButtonClicked();
private:
	QTableWidget* m_table;
};

