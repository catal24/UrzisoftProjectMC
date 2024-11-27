#pragma once
#include <QWidget>
#include <QGridLayout>

class LeaderboardDisplay : public QWidget
{
	Q_OBJECT

public:
	explicit LeaderboardDisplay(QWidget* parent = nullptr);
	~LeaderboardDisplay();
private:
	QGridLayout* gridLayout;
};

