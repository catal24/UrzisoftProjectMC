#pragma once
#include <QWidget>
#include <QTimer>
#include "Game.h"
class GameWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget* parent = nullptr);
	~GameWidget();

protected:
	void paintEvent(QPaintEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;

private:
	Game m_game;
	QTimer* m_timer; //timer pt actualizari
	int m_titleSize = 20; //dim celulelor pe ecran

private slots:
	void updateGame();
};

