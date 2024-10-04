/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPlainTextEdit *projectname;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *startdate;
    QDateEdit *enddate;
    QLabel *label_4;
    QPlainTextEdit *descriptionText;
    QPushButton *createprojectButton;
    QPushButton *editprojectButton;
    QPushButton *deleteprojectButton;
    QPushButton *refreshprojectButton;
    QListWidget *projectList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 101, 20));
        projectname = new QPlainTextEdit(centralwidget);
        projectname->setObjectName("projectname");
        projectname->setGeometry(QRect(150, 10, 351, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 10, 71, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(550, 40, 63, 20));
        startdate = new QDateEdit(centralwidget);
        startdate->setObjectName("startdate");
        startdate->setGeometry(QRect(620, 10, 131, 26));
        enddate = new QDateEdit(centralwidget);
        enddate->setObjectName("enddate");
        enddate->setGeometry(QRect(620, 40, 131, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 50, 91, 20));
        descriptionText = new QPlainTextEdit(centralwidget);
        descriptionText->setObjectName("descriptionText");
        descriptionText->setGeometry(QRect(150, 50, 351, 61));
        createprojectButton = new QPushButton(centralwidget);
        createprojectButton->setObjectName("createprojectButton");
        createprojectButton->setGeometry(QRect(40, 130, 101, 29));
        editprojectButton = new QPushButton(centralwidget);
        editprojectButton->setObjectName("editprojectButton");
        editprojectButton->setGeometry(QRect(160, 130, 101, 29));
        deleteprojectButton = new QPushButton(centralwidget);
        deleteprojectButton->setObjectName("deleteprojectButton");
        deleteprojectButton->setGeometry(QRect(280, 130, 91, 29));
        refreshprojectButton = new QPushButton(centralwidget);
        refreshprojectButton->setObjectName("refreshprojectButton");
        refreshprojectButton->setGeometry(QRect(390, 130, 101, 29));
        projectList = new QListWidget(centralwidget);
        projectList->setObjectName("projectList");
        projectList->setGeometry(QRect(40, 170, 721, 371));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Project Name:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Start date:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "End date:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        createprojectButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        editprojectButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        deleteprojectButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        refreshprojectButton->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
