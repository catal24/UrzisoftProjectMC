#include "LeaderboardDisplay.h"

LeaderboardDisplay::LeaderboardDisplay(QWidget* parent)
    : QWidget(parent)
{
    this->setWindowTitle("Leaderboard");
    this->setFixedSize(800, 600);

    m_table = new QTableWidget(5, 2, this);
    m_table->setHorizontalHeaderLabels(QStringList() << "Name" << "Points");
    m_table->horizontalHeader()->setStretchLastSection(true);
    m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_table->verticalHeader()->setVisible(false);
    m_table->setAlternatingRowColors(true);
    m_table->setStyleSheet(
        "QTableWidget { gridline-color: #5D3FD3; }" // Mov închis pentru grilă
        "QHeaderView::section { background-color: #483D8B; color: #40E0D0; font-weight: bold; }" // Fundal mov închis și text turcoaz
        "QTableWidget::item { selection-background-color: #40E0D0; selection-color: #FFFFFF; }" // Selecție turcoaz
        "QTableWidget { border: 2px solid #483D8B; border-radius: 10px; }"); // Bordură mov închis

    QFont font("Arial", 12, QFont::Bold);
    m_table->setFont(font);

    // Inițializare celule (goale)
    for (int row = 0; row < m_table->rowCount(); ++row) {
        for (int col = 0; col < m_table->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem("");
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            m_table->setItem(row, col, item);
        }
    }

    auto layout = new QVBoxLayout(this);
    layout->addWidget(m_table);
    layout->setContentsMargins(20, 20, 20, 20);

    QPushButton* backButton = new QPushButton("Back", this);
    backButton->setStyleSheet(
        "QPushButton { background-color: #5D3FD3; color: #FFFFFF; font-weight: bold; padding: 10px; border-radius: 5px; }" // Fundal mov și text alb
        "QPushButton:hover { background-color: #40E0D0; color: #000000; }"); // Fundal turcoaz la hover
    layout->addWidget(backButton, 0, Qt::AlignCenter);

    connect(backButton, &QPushButton::clicked, this, &LeaderboardDisplay::backButtonClicked);
    connect(backButton, &QPushButton::clicked, this, [&]() {
        this->hide();
        });

    setLayout(layout);
}

LeaderboardDisplay::~LeaderboardDisplay() {}
