#include "mainwindow.h"
#include "database.h"
#include "SignupDialog.h"
#include "LoginDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QWidget { background-color: #ecf0f1;color: #2c3e50;border: none;}"
                    "QLabel#headerLabel { font-size: 18px; font-weight: bold; color: #3498db;}"
                    "QPushButton { background-color: #3498db; color: white; font-weight: bold; border: 1px solid #2980b9; padding: 5px 15px; border-radius: 5px;}"
                    "QPushButton:hover { background-color: #2980b9;}"
                    "QPushButton:pressed { background-color: #1f5c89;}"
                    "QPushButton#dangerButton { background-color: #e74c3c; color: white; border: 1px solid #c0392b;}"
                    "QPushButton#dangerButton:hover { background-color: #c0392b;}"
                    "QPushButton#dangerButton:pressed { background-color: #a5281b;}"
                    "QPlainTextEdit {border: 2px solid #bdc3c7; padding: 1px; background: white; border-radius: 4px; font-size: 14px;}"
                    "QLineEdit {border: 1px solid #bdc3c7; background: white; border-radius: 4px; font-size: 12px;}"
                    "QDateEdit {border: 1px solid #bdc3c7; background: white; border-radius: 2px; font-size: 12px;}"
                    "QPlainTextEdit:hover {border: 2px solid #3498db;}"
                    "QPlainTextEdit:focus { border: 2px solid #2980b9;}"
                    "QListWidget {border: 1px solid #bdc3c7;}"
                    "QListWidget::item:selected { background-color: #ecf0f1; color: #ecf0f1;border: 2px solid #bdc3c7;}"
                    "QListWidget::item:hover { background-color: #ecf0f1; color: #ecf0f1;}"
                    "QListWidget::item { background-color: #ecf0f1; color: #ecf0f1;}"
                    "QToolTip { color: #ecf0f1; background-color: #3498db; border: 1px solid #2980b9; padding: 2px; border-radius: 3px; opacity: 200;}");

    if (!DatabaseManager::initializeDatabase()) {
        qWarning() << "Failed to initialize the database!";
        return -1;
    }
    LoginDialog loginDialog;
    if (loginDialog.exec() == QDialog::Accepted) {
        MainWindow w;
        w.setWindowTitle("Project Management Tool");
        QString username = loginDialog.getUsername();
        w.setUsername(username);
        w.show();
        return a.exec();
    }
    return 0;
}
