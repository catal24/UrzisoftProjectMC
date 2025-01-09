#include "ClientMC.h"
#include "GameWindow.h"
#include <QPushButton>
#include "MovementInfoDisplay.h"
#include "LeaderboardDisplay.h"
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QFontDatabase>

// Functie pentru a configura butoanele cu imagini
void setupButtonWithImage(QPushButton* button, int x, int y, int width, int height, const std::string& imagePath)
{
    button->setGeometry(x, y, width, height);  // Setam geometria butonului (pozitia si dimensiunea)
    button->setStyleSheet(
        "QPushButton {"
        "   border-radius: 25px;"  // Raza colturilor butonului
        "   background: transparent;"  // Fundal transparent
        "    background-image: url(" + QString::fromStdString(imagePath) + "); "  // Setam imaginea de fundal
        "    background-repeat: no-repeat;"  // Nu repetam imaginea
        "    background-position: center;"  // Pozitionam imaginea la centru
        "}"
    );
}

// Constructorul clasei ClientMC (Main Menu)
ClientMC::ClientMC(QWidget* parent)
    : QMainWindow(parent)
{
    // Setam fundalul ferestrei principale cu o imagine
    this->setStyleSheet("QMainWindow {"
        "   background-image: url(resources/images/wallpaper.jpg);"// path to wallpaper
        "   background-repeat: no-repeat;"
        "   background-position: center;"
        "   background-size: cover;"// resize wallpaper 
        "}");

    this->setWindowTitle("Menu");  //titlul ferestrei
    this->setFixedSize(800, 600);  // Setam dimensiunea fixa a ferestrei
    QFontDatabase::addApplicationFont("resources/fonts/Deadknight.otf");  //adaugam fontul Deadknight

    //creem butoanele din meniul principal
    m_infoButton = new QPushButton(this);
    setupButtonWithImage(m_infoButton, 25, 25, 50, 50, "resources/images/infoButton.png");

    m_leaderboardButton = new QPushButton(this);
    setupButtonWithImage(m_leaderboardButton, 25, 80, 50, 50, "resources/images/rankButton.png");

    m_findGame = new QPushButton("Find Game", this);  //butonul pentru a cauta jocuri
    m_findGame->setGeometry(325, 300, 150, 50);  //setam pozitia si dimensiunea butonului
    m_findGame->setStyleSheet(
        "QPushButton {"
        "    background-color: #3498db;"  //culoarea de fundal
        "    color: white;"  //culoarea textului
        "    border: 2px solid #2980b9;"  //bordura butonului
        "    border-radius: 10px;"  //colturile rotunjite
        "    font-size: 16px;"  //dimensiunea fontului
        "    font-family: 'Deadknight';"  //fontul utilizat
        "    padding: 10px;"  //adaugam spatiu in interiorul butonului
        "}"
        "QPushButton:hover {"
        "    background-color: #2980b9;"  //culoarea butonului la hover
        "}"
        "QPushButton:pressed {"
        "    background-color: #1c5985;"  //culoarea butonului cand este apasat
        "}"
    );

    m_mapSelector = new QPushButton(this);
    setupButtonWithImage(m_mapSelector, 725, 25, 50, 50, "resources/images/mapSelector.png");

    m_upgrade = new QPushButton(this);
    setupButtonWithImage(m_upgrade, 725, 80, 50, 50, "resources/images/upgrade.png");

    // Conectam butonul 'Find Game' pentru a afisa un mesaj in consola
    connect(m_findGame, &QPushButton::clicked, this, [&]() {
        qDebug() << "Find Game button clicked!";
        this->hide();  

        GameWindow* gameWindow = new GameWindow();  
        gameWindow->show();  
        });

    
    connect(m_infoButton, &QPushButton::clicked, this, [&]() {
        MovementInfoDisplay* infoWindow = new MovementInfoDisplay(this);
        infoWindow->setAttribute(Qt::WA_DeleteOnClose);  // Setam fereastra sa fie stearsa la inchidere
        infoWindow->show();  // Afisam fereastra
        toggleBButtons(false);  // Ascundem butoanele din meniul principal

        
        connect(infoWindow, &MovementInfoDisplay::backButtonClicked, this, [=]() {
            infoWindow->close();  // Inchidem fereastra info
            toggleBButtons(true);  // Afisam butoanele din nou
            });
        });

    
    connect(m_leaderboardButton, &QPushButton::clicked, this, [&]() {
        LeaderboardDisplay* leaderboardWindow = new LeaderboardDisplay(this);
        leaderboardWindow->setAttribute(Qt::WA_DeleteOnClose);  // Setam fereastra sa fie stearsa la inchidere
        leaderboardWindow->show();  // Afisam fereastra
        toggleBButtons(false);  // Ascundem butoanele din meniul principal

        
        connect(leaderboardWindow, &LeaderboardDisplay::backButtonClicked, this, [=]() {
            leaderboardWindow->close();  // Inchidem fereastra leaderboard
            toggleBButtons(true);  // Afisam butoanele din nou
            });
        });
}

ClientMC::~ClientMC() {}

void ClientMC::closeEvent(QCloseEvent* event)
{
    QCoreApplication::quit();  // Inchidem aplicatia la inchiderea ferestrei
    event->accept();  
}

//functie pentru a ascunde sau afisa butoanele din meniul principal
void ClientMC::toggleBButtons(bool visible)
{
    m_findGame->setVisible(visible);
    m_infoButton->setVisible(visible);
    m_leaderboardButton->setVisible(visible);
    m_upgrade->setVisible(visible);
    m_mapSelector->setVisible(visible);
}
