#include "SignupDialog.h"
#include "Database.h"

SignupDialog::SignupDialog(QWidget *parent) : QDialog(parent) {
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    registerButton = new QPushButton("Register", this);
    cancelButton = new QPushButton("Cancel", this);

    QFormLayout *layout = new QFormLayout();
    layout->addRow("Username:", usernameLineEdit);
    layout->addRow("Password:", passwordLineEdit);
    layout->addWidget(registerButton);
    layout->addWidget(cancelButton);

    setLayout(layout);
    setWindowTitle("Sign Up");

    connect(registerButton, &QPushButton::clicked, this, &SignupDialog::registerUser);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

void SignupDialog::registerUser() {
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (DatabaseManager::addUser(username, password)) {
        QMessageBox::information(this, "Registration Successful", "You are now registered.");
        accept(); // Close the dialog
    } else {
        QMessageBox::warning(this, "Registration Failed", "Unable to register.");
    }
}
