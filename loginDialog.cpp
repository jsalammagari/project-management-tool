#include "LoginDialog.h"
#include "SignupDialog.h"
#include "Database.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);
    signupButton = new QPushButton("Signup", this);
    cancelButton = new QPushButton("Cancel", this);

    QFormLayout *layout = new QFormLayout();
    layout->addRow("Username:", usernameLineEdit);
    layout->addRow("Password:", passwordLineEdit);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(signupButton);
    layout->addRow(buttonLayout);
    layout->addRow(cancelButton);

    setLayout(layout);
    setWindowTitle("Login");

    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::attemptLogin);
    connect(signupButton, &QPushButton::clicked, this, &LoginDialog::openSignupDialog);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

void LoginDialog::openSignupDialog() {
    SignupDialog signupDialog;
    signupDialog.exec();
}

void LoginDialog::attemptLogin() {
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (DatabaseManager::authenticate(username, password)) {
        m_username = username;
        emit loginSuccessful();
        accept();
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}

QString LoginDialog::getUsername() const {
    return m_username;
}
