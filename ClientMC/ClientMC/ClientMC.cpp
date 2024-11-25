#include "ClientMC.h"
#include <QPushButton>
#include "MovementInfoDisplay.h"
ClientMC::ClientMC(QWidget *parent)
    : QMainWindow(parent)
{

	this->setWindowTitle("Menu");
	this->setFixedSize(800, 600);

    infoButton = new QPushButton("INFO",this);
	infoButton->setGeometry(25, 25, 50, 50);

	connect(infoButton, &QPushButton::clicked, this, [&]() {
		MovementInfoDisplay* infoWindow = new MovementInfoDisplay(this);  // Creează instanța ferestrei
		infoWindow->setAttribute(Qt::WA_DeleteOnClose);
		infoWindow->show();  // Deschide fereastra
		infoButton->hide();
		});
	
}

ClientMC::~ClientMC()
{}
