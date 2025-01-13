#include "GameWindow.h"
#include <QPainter>
#include <QTimer>
#include <cpr/cpr.h>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

GameWindow::GameWindow(QWidget* parent)
    : QWidget(parent)
{
    // Setează dimensiunea și titlul ferestrei
    this->showFullScreen();
    this->setWindowTitle("STARFIRE");
    this->setStyleSheet("background-color: black;");
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint);
    this->setWindowState(Qt::WindowNoState);

    // Fetch map la inițializare
    fetchAndSetMap("http://localhost:18080/map");

    // Timer pentru actualizare
    QTimer* gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, [&]() {
        update();
        });
    gameTimer->start(16); // ~60 FPS
}

void GameWindow::fetchAndSetMap(const QString& serverUrl) {
    QString mapData = fetchMap(serverUrl);
    if (mapData.contains("Eroare")) {
        qWarning() << "Nu s-a putut încărca harta.";
    }
    else {
        // Parsăm JSON-ul pentru a obține matricea
        QJsonDocument doc = QJsonDocument::fromJson(mapData.toUtf8());
        if (doc.isArray()) {
            QJsonArray mapArray = doc.array();
            for (const auto& row : mapArray) {
                QJsonArray rowArray = row.toArray();
                QVector<int> mapRow;
                for (const auto& cell : rowArray) {
                    mapRow.append(cell.toInt());
                }
                mapMatrix.append(mapRow);
            }
        }
    }
}

QString fetchMap(const QString& serverUrl) {
    // Realizează cererea GET către server
    auto response = cpr::Get(cpr::Url{ serverUrl.toStdString() });

    if (response.status_code == 200) {
        // Răspuns valid
        return QString::fromStdString(response.text);
    }
    else {
        // Eroare la fetch
        qWarning() << "Eroare la fetchMap. Status code:" << response.status_code;
        return QString("Eroare la descărcarea hărții.");
    }
}

void GameWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Desenează fundalul
    painter.fillRect(this->rect(), Qt::black);

    // Desenează matricea hărții
    drawMap(painter);
}

void GameWindow::drawMap(QPainter& painter) {
    int cellSize = 30; // Dimensiunea fiecărei celule din matrice
    for (int y = 0; y < mapMatrix.size(); ++y) {
        for (int x = 0; x < mapMatrix[y].size(); ++x) {
            QColor color = (mapMatrix[y][x] == 1) ? Qt::green : Qt::black;
            painter.fillRect(x * cellSize, y * cellSize, cellSize, cellSize, color);
        }
    }
}

GameWindow::~GameWindow() {}
