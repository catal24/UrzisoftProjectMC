#pragma once
#include <QWidget>
#include <QString>
#include <QVector>

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = nullptr);
    ~GameWindow();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<QVector<int>> mapMatrix; // Matricea hărții

    void fetchAndSetMap(const QString& serverUrl); // Funcție pentru fetch și setarea matricei
    void drawMap(QPainter& painter); // Funcție pentru desenarea hărții
};

QString fetchMap(const QString& serverUrl); // Declarația funcției
