#include "MovementInfoDisplay.h"
#include <QPushButton>
#include <QVBoxLayout>0
#include <QLabel>
#include <QFontDatabase>
void setupLabel(QLabel* label)
{
    label->setStyleSheet(
        "QLabel {"
        "    background-color: #670D68;"
        "    color: black;"
        "    font-family: 'Deadknight';"
        "    font-size: 25px;"
        "}"
    );
}

MovementInfoDisplay::MovementInfoDisplay(QWidget* parent)
    : QWidget(parent)
{
    this->setFixedSize(800, 600);

    QFontDatabase::addApplicationFont("resources/fonts/Deadknight.otf");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(25);
    layout->setContentsMargins(20,Qt::AlignVCenter,20,20);

    QLabel* up = new QLabel("Press W to move upwards", this);
    setupLabel(up);

    QLabel* left = new QLabel("Press A to move leftwards", this);
    setupLabel(left);

    QLabel* down = new QLabel("Press S to move downwards", this);
	setupLabel(down);

    QLabel* right = new QLabel("Press D to move rightwards", this);
	setupLabel(right);

    QLabel* shoot = new QLabel("Press SPACE to shoot", this);
	setupLabel(shoot);

    layout->addWidget(up, 0, Qt::AlignHCenter);
    layout->addWidget(left, 0, Qt::AlignHCenter);
    layout->addWidget(down, 0, Qt::AlignHCenter);
    layout->addWidget(right, 0, Qt::AlignHCenter);
    layout->addWidget(shoot, 0, Qt::AlignHCenter);
    
    layout->setAlignment(Qt::AlignVCenter);

    QPushButton* backButton = new QPushButton("Back", this);
    backButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #670D68;"
        "}"
    );
    QVBoxLayout* layoutButton = new QVBoxLayout(this);
    layoutButton->addStretch();
    layoutButton->addWidget(backButton,0, Qt::AlignRight);

    layout->addLayout(layoutButton);
    this->setLayout(layout);

    // Conecteaza butonul la metoda de inchidere a ferestrei
    connect(backButton, &QPushButton::clicked, this, &MovementInfoDisplay::backButtonClicked);
}

MovementInfoDisplay::~MovementInfoDisplay()
{}
