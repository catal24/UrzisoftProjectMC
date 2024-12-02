#pragma once
#include <QWidget>

class MovementInfoDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit MovementInfoDisplay(QWidget* parent = nullptr);
    ~MovementInfoDisplay();
signals:
    void backButtonClicked();
};
