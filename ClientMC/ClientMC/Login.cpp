#include "Login.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

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

    // verificam daca username e gol
    if (username.isEmpty())
    {
        
        QMessageBox::warning(this, "Invalid username", "Enter a valid username");
    }
    else {
        emit loginSuccess();
        // afisam un mesaj ca logarea a fost realizata cu succes
        QMessageBox::information(this, "Login", "Login successful!");
    }
}
