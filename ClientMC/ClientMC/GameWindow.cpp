#include "GameWindow.h"
#include <QPainter>
#include <QTimer>
#include <cpr/cpr.h>
#include <QJsonDocument>
#include <QJsonArray>
#include <cmath>
#include <QDebug>

GameWindow::GameWindow(QWidget* parent)
    : QWidget(parent)
{
    // Set window size to 800x800
    this->setFixedSize(800, 800);

    // Set window title and properties
    this->setWindowTitle("STARFIRE");
    this->setStyleSheet("background-color: red;");
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowState(Qt::WindowNoState);

    // Timer to update the map every 50ms
    QTimer* mapUpdateTimer = new QTimer(this);
    connect(mapUpdateTimer, &QTimer::timeout, this, [&]() {
        fetchAndSetMap("http://localhost:18080/map");
        update();
        });
    mapUpdateTimer->start(50); // Update every 50ms

    // Game timer for rendering
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
        return;
    }

    // Parse JSON to get the map matrix
    QJsonDocument doc = QJsonDocument::fromJson(mapData.toUtf8());
    if (doc.isArray()) {
        QJsonArray mapArray = doc.array();

        QVector<QVector<int>> newMapMatrix;
        for (const auto& row : mapArray) {
            QJsonArray rowArray = row.toArray();
            QVector<int> mapRow;
            for (const auto& cell : rowArray) {
                mapRow.append(cell.toInt());
            }
            newMapMatrix.append(mapRow);
        }

        // Update the map matrix
        mapMatrix = newMapMatrix;
    }
}

QString fetchMap(const QString& serverUrl) {
    // Make a GET request to the server
    auto response = cpr::Get(cpr::Url{ serverUrl.toStdString() });

    if (response.status_code == 200) {
        // Valid response
        return QString::fromStdString(response.text);
    }
    else {
        // Fetch error
        qWarning() << "Eroare la fetchMap. Status code:" << response.status_code;
        return QString("Eroare la descărcarea hărții.");
    }
}

void GameWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Draw background
    painter.fillRect(this->rect(), Qt::black);

    // Draw the map
    drawMap(painter);
}

void GameWindow::drawMap(QPainter& painter) {
    // Size of each cell in pixels
    int cellSize = 40;

    // Load images
    QPixmap floor("resources/images/podea.jpeg");
    QPixmap blockGreen("resources/images/Wall.jpg");
    QPixmap vehicul("resources/images/vehicle.jpg");
    QPixmap bomb("resources/images/bomba.jpg");
    QPixmap bullet("resources/images/bullet.jpg");

    // Scale images to fit 40x40 pixels
    floor = floor.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    blockGreen = blockGreen.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    vehicul = vehicul.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    bomb = bomb.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    bullet = bullet.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    QPixmap currentBlock;

    // Draw the map based on the matrix
    for (int i = 0; i < mapMatrix.size(); i++) {
        for (int j = 0; j < mapMatrix[i].size(); j++) {
            // Choose the image based on the matrix value
            if (mapMatrix[i][j] == 0)
                currentBlock = floor;
            else if (mapMatrix[i][j] == 1)
                currentBlock = blockGreen;
            else if (mapMatrix[i][j] == 2)
                currentBlock = vehicul;
            else if (mapMatrix[i][j] == 3)
                currentBlock = bullet;
            else if (mapMatrix[j][j] == 4)
                currentBlock = bomb;

            // Draw the image at the corresponding position
            painter.drawPixmap(j * cellSize, i * cellSize, currentBlock);
        }
    }
}

GameWindow::~GameWindow() {}
