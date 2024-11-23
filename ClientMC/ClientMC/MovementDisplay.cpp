#include "MovementInfoDisplay.h"
#include <QPushButton>

MovementInfoDisplay::MovementInfoDisplay(QWidget* parent)
    : QWidget(parent)
{
    this->setWindowTitle("Movement Info");


    QPushButton* closeButton = new QPushButton("Back", this);

    // Conectează butonul la metoda de închidere a ferestrei
    connect(closeButton, &QPushButton::clicked, this, &MovementInfoDisplay::close);
}

MovementInfoDisplay::~MovementInfoDisplay()
{}
