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
    // Setează dimensiunea ferestrei la 1280x800
    this->setFixedSize(800, 800);

    // Setează titlul ferestrei și alte caracteristici
    this->setWindowTitle("STARFIRE");
    
    this->setStyleSheet("background-color: red;");

    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
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
    // Dimensiunea fiecărei celule în pixeli
    int cellSize = 40;

    // Încarcă imaginile
    QPixmap blockBlack("resources/images/podea2.jpeg");
    QPixmap blockGreen("resources/images/Wall.jpg");

    // Scalează imaginile pentru a se potrivi celulelor de 40x40 pixeli
    blockBlack = blockBlack.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    
    blockGreen = blockGreen.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    QPixmap vehicul("resources/images/vehicle.png");
    vehicul=vehicul.scaled(cellSize, cellSize, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QPixmap currentBlock;
    // Desenează harta
    for (int y = 0; y < mapMatrix.size(); ++y) {
        for (int x = 0; x < mapMatrix[y].size(); ++x) {
            // Selectează imaginea în funcție de valoarea din matrice
            if (mapMatrix[y][x] == 0)
                 currentBlock = blockBlack;
            else if (mapMatrix[y][x] == 1)
                 currentBlock = blockGreen;
            else if(mapMatrix[y][x]==2)
                currentBlock = vehicul;

            // Desenează imaginea în poziția corespunzătoare
            painter.drawPixmap(x * cellSize, y * cellSize, currentBlock);
        }
    }
}


GameWindow::~GameWindow() {}
