#include "Login.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>


Login::Login(QWidget* parent) : QWidget(parent)
{
    m_usernameField = new QLineEdit(this);
    m_usernameField->setPlaceholderText("Username");  // adaugam text

    
    m_loginButton = new QPushButton("Login", this);// cream buton de login

    // cream layout pentru widgeturi
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_usernameField);  // camp pentru username
    layout->addWidget(m_loginButton);    // adaugam buton login
    this->setMinimumSize(300, 100);      // dimensiunea ferestrei
    setLayout(layout);                   // aplicam layout

    // conectam semnalul de click pe buton la slotul handleLogin
    connect(m_loginButton, &QPushButton::clicked, this, &Login::handleLogin);
}


Login::~Login() {}

//ce facem la click
void Login::handleLogin()
{
    QString username = m_usernameField->text();

    // Definim regex-ul: cel puțin 5 caractere
    QRegularExpression regex(R"(^.{5,}$)");

    // Verificăm dacă username-ul se potrivește cu regex-ul
    if (!regex.match(username).hasMatch()) {
        QMessageBox::warning(this, "Invalid username", "Username must be at least 5 characters long.");
        return;
    }

    // Dacă este valid, emitem semnalul de login
    emit loginSuccess();
    QMessageBox::information(this, "Login", "Login successful!");
}

