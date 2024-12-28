#include "MovementInfoDisplay.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFontDatabase>


void setupLabel(QLabel* label)
{
    label->setStyleSheet(
        "QLabel {"
        "    background-color: #670D68;"  // culoare fundal
        "    color: black;"               // culoare text
        "    font-family: 'Deadknight';"   // fontul folosit
        "    font-size: 25px;"             // dimensiunea fontului
        "}"
    );
}


MovementInfoDisplay::MovementInfoDisplay(QWidget* parent)
    : QWidget(parent)
{
    this->setFixedSize(800, 600);  // setam dimensiunea fixa a ferestrei

    // Adaugam fontul Deadknight
    QFontDatabase::addApplicationFont("resources/fonts/Deadknight.otf");

    // Cream un layout vertical
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(25);  // spatiu intre widget-uri
    layout->setContentsMargins(20, Qt::AlignVCenter, 20, 20);  // marje

    // creem label-uri pentru instructiunile de miscare
    QLabel* up = new QLabel("Press W to move upwards", this);
    setupLabel(up);  // aplicam stilul la label

    QLabel* left = new QLabel("Press A to move leftwards", this);
    setupLabel(left);

    QLabel* down = new QLabel("Press S to move downwards", this);
    setupLabel(down);

    QLabel* right = new QLabel("Press D to move rightwards", this);
    setupLabel(right);

    QLabel* shoot = new QLabel("Press SPACE to shoot", this);
    setupLabel(shoot);

    // Adaugam label-urile in layout si le aliniem la centru pe orizontala
    layout->addWidget(up, 0, Qt::AlignHCenter);
    layout->addWidget(left, 0, Qt::AlignHCenter);
    layout->addWidget(down, 0, Qt::AlignHCenter);
    layout->addWidget(right, 0, Qt::AlignHCenter);
    layout->addWidget(shoot, 0, Qt::AlignHCenter);

    // Aliniem tot layout-ul vertical la centru pe verticala
    layout->setAlignment(Qt::AlignVCenter);

    // Cream un buton "Back" pentru a inchide fereastra
    QPushButton* backButton = new QPushButton("Back", this);
    backButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #670D68;"  // culoare fundal buton
        "}"
    );
    // Cream un layout pentru buton
    QVBoxLayout* layoutButton = new QVBoxLayout(this);
    layoutButton->addStretch();  // adaugam spatiu flexibil
    layoutButton->addWidget(backButton, 0, Qt::AlignRight);  // aliniem butonul la dreapta
    layout->addLayout(layoutButton);  
    this->setLayout(layout);  

    connect(backButton, &QPushButton::clicked, this, &MovementInfoDisplay::backButtonClicked);
}

// Destructorul clasei MovementInfoDisplay
MovementInfoDisplay::~MovementInfoDisplay()
{}
