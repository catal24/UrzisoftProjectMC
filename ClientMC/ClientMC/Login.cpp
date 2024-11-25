#include "Login.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

Login::Login(QWidget* parent) : QWidget(parent)
{
	usernameField = new QLineEdit(this);
	usernameField->setPlaceholderText("Username");

	loginButton = new QPushButton("Login", this);

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(usernameField);
	layout->addWidget(loginButton);
	this->setMinimumSize(300, 100);
	setLayout(layout);

	connect(loginButton, &QPushButton::clicked, this, &Login::handleLogin);
}

Login::~Login(){}

void Login::handleLogin()
{
	QString username = usernameField->text();
	//aici vom verifica in baza de date daca exista un cont cu acest username
	if(username.isEmpty())
	{
		QMessageBox::warning(this,"Invalid username", "Enter a valid username");

	}
	else {
		emit loginSuccess();
		QMessageBox::information(this, "Login", "Login successful!");

		//daca nu exista Player cu acest username vom crea unul
		QMessageBox::information(this, "Login", "A new account with your username was created");
	}
	}