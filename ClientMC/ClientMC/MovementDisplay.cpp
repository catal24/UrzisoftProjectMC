#include "MovementInfoDisplay.h"
#include <QPushButton>
#include <QVBoxLayout>0
#include <QLabel>

MovementInfoDisplay::MovementInfoDisplay(QWidget* parent)
    : QWidget(parent)
{
    this->setWindowTitle("Movement Info");
    this->setFixedSize(800, 600);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(25);
    layout->setContentsMargins(20,Qt::AlignVCenter,20,20);

    QLabel* up = new QLabel("Press W to move upwards", this);
    up->setFont(QFont("Arial", 15));

    QLabel* left = new QLabel("Press A to move leftwards", this);
    left->setFont(QFont("Arial", 15));

    QLabel* down = new QLabel("Press S to move downwards", this);
    down->setFont(QFont("Arial", 15));

    QLabel* right = new QLabel("Press D to move rightwards", this);
	right->setFont(QFont("Arial", 15));

    QLabel* shoot = new QLabel("Press SPACE to shoot", this);
	shoot->setFont(QFont("Arial", 15));

    layout->addWidget(up, 0, Qt::AlignHCenter);
    layout->addWidget(left, 0, Qt::AlignHCenter);
    layout->addWidget(down, 0, Qt::AlignHCenter);
    layout->addWidget(right, 0, Qt::AlignHCenter);
    layout->addWidget(shoot, 0, Qt::AlignHCenter);
    
    layout->setAlignment(Qt::AlignVCenter);

    QPushButton* backButton = new QPushButton("Back", this);
    QVBoxLayout* layoutButton = new QVBoxLayout(this);
    layoutButton->addStretch();
    layoutButton->addWidget(backButton,0, Qt::AlignRight);

    layout->addLayout(layoutButton);
    this->setLayout(layout);

    // Conecteaza butonul la metoda de inchidere a ferestrei
    connect(backButton, &QPushButton::clicked, this, [&]() {
        this->hide();

        });
}

MovementInfoDisplay::~MovementInfoDisplay()
{}
