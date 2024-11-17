#include "Login.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

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

}