#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>

class SignupDialog : public QDialog {
    Q_OBJECT

public:
    explicit SignupDialog(QWidget *parent = nullptr);

private slots:
    void registerUser();

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *registerButton;
    QPushButton *cancelButton;
};

#endif
