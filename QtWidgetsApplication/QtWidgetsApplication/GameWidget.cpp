#include "GameWidget.h"

GameWidget::GameWidget(QWidget* parent)
	:QWidget{parent}, m_game{Game::EASY}
{
    setFocusPolicy(Qt::StrongFocus);  // Permite capturarea evenimentelor de la tastatură

    // Configurează timerul pentru actualizări
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &GameWidget::updateGame);
    m_timer->start(50);  // Actualizare la fiecare 50ms
}

GameWidget::~GameWidget()
{
    delete m_timer;
}

void GameWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);  // Fundal alb

    // Exemplu de desenare: desenează o hartă simplă
    auto map = m_game.randomMap();  // Obține harta din Game
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 1) {
                painter.setBrush(Qt::gray);
                painter.drawRect(j * m_titleSize, i * m_titleSize, m_titleSize, m_titleSize);
            }
        }
    }
}

void GameWidget::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_W: m_game.InputControll(); break;  // Adaptează pentru logica ta
    case Qt::Key_S: m_game.InputControll(); break;
    case Qt::Key_A: m_game.InputControll(); break;
    case Qt::Key_D: m_game.InputControll(); break;
    case Qt::Key_Space: m_game.Shoot(); break;
    default: QWidget::keyPressEvent(event);
    }
    update();  // Re-desenează zona de joc
}

void GameWidget::updateGame() 
{
    m_game.BulletMoving();  // Actualizează logica gloanțelor
    update();  // Re-desenează
}