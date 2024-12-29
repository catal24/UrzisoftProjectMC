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
        "QTableWidget { gridline-color: #D3D3D3; }"
        "QHeaderView::section { background-color: #2E8B57; color: white; font-weight: bold; }"
        "QTableWidget::item { selection-background-color: #ADD8E6; }"
        "QTableWidget { border: 2px solid #8FBC8F; border-radius: 10px; }");

    QFont font("Arial", 12, QFont::Bold);
    m_table->setFont(font);

    m_table->setItem(0, 0, new QTableWidgetItem(""));
    m_table->setItem(0, 1, new QTableWidgetItem(""));
    m_table->setItem(1, 0, new QTableWidgetItem(""));
    m_table->setItem(1, 1, new QTableWidgetItem(""));
    m_table->setItem(1, 1, new QTableWidgetItem(""));
    m_table->setItem(2, 0, new QTableWidgetItem(""));
    m_table->setItem(2, 1, new QTableWidgetItem(""));
    m_table->setItem(3, 0, new QTableWidgetItem(""));
    m_table->setItem(3, 1, new QTableWidgetItem(""));
    m_table->setItem(4, 0, new QTableWidgetItem(""));
    m_table->setItem(4, 1, new QTableWidgetItem(""));

    for (int row = 0; row < m_table->rowCount(); ++row) {
        for (int col = 0; col < m_table->columnCount(); ++col) {
            QTableWidgetItem* item = m_table->item(row, col);
            if (item) {
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
        }
    }

    auto layout = new QVBoxLayout(this);
    layout->addWidget(m_table);
    layout->setContentsMargins(20, 20, 20, 20);

    QPushButton* backButton = new QPushButton("Back", this);
    backButton->setStyleSheet("QPushButton { background-color: #2E8B57; color: white; font-weight: bold; padding: 10px; }");
    layout->addWidget(backButton, 0, Qt::AlignCenter);

    connect(backButton, &QPushButton::clicked, this, &LeaderboardDisplay::backButtonClicked);
    connect(backButton, &QPushButton::clicked, this, [&]() {
        this->hide();
        });

    setLayout(layout);
}

LeaderboardDisplay::~LeaderboardDisplay() {}
