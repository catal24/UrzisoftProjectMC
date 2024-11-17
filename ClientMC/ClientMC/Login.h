#pragma once

#include <QWidget>

class QLineEdit;
class QPushButton;

class Login : public QWidget
{
	Q_OBJECT
public:
	Login(QWidget* parent = nullptr);
	~Login();

signals:
	void loginSuccess();

private slots:
	void handleLogin();

private:
    QLineEdit* usernameField;
    QPushButton* loginButton;
};


