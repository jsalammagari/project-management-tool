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
    QListWidget *storyList;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *Username_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1166, 803);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 101, 20));
        projectname = new QPlainTextEdit(centralwidget);
        projectname->setObjectName("projectname");
        projectname->setGeometry(QRect(150, 10, 431, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(600, 10, 71, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(820, 10, 63, 20));
        startdate = new QDateEdit(centralwidget);
        startdate->setObjectName("startdate");
        startdate->setGeometry(QRect(670, 10, 131, 26));
        enddate = new QDateEdit(centralwidget);
        enddate->setObjectName("enddate");
        enddate->setGeometry(QRect(880, 10, 131, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 50, 91, 20));
        descriptionText = new QPlainTextEdit(centralwidget);
        descriptionText->setObjectName("descriptionText");
        descriptionText->setGeometry(QRect(150, 50, 431, 61));
        createprojectButton = new QPushButton(centralwidget);
        createprojectButton->setObjectName("createprojectButton");
        createprojectButton->setGeometry(QRect(600, 50, 101, 29));
        editprojectButton = new QPushButton(centralwidget);
        editprojectButton->setObjectName("editprojectButton");
        editprojectButton->setGeometry(QRect(720, 50, 101, 29));
        deleteprojectButton = new QPushButton(centralwidget);
        deleteprojectButton->setObjectName("deleteprojectButton");
        deleteprojectButton->setGeometry(QRect(840, 50, 91, 29));
        refreshprojectButton = new QPushButton(centralwidget);
        refreshprojectButton->setObjectName("refreshprojectButton");
        refreshprojectButton->setGeometry(QRect(950, 50, 101, 29));
        refreshprojectButton->setFlat(false);
        projectList = new QListWidget(centralwidget);
        projectList->setObjectName("projectList");
        projectList->setGeometry(QRect(40, 140, 541, 601));
        storyList = new QListWidget(centralwidget);
        storyList->setObjectName("storyList");
        storyList->setGeometry(QRect(600, 140, 541, 601));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 110, 81, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(600, 110, 71, 31));
        label_6->setFont(font);
        Username_label = new QLabel(centralwidget);
        Username_label->setObjectName("Username_label");
        Username_label->setGeometry(QRect(1020, 0, 121, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1166, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        refreshprojectButton->setDefault(false);


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
        label_5->setText(QCoreApplication::translate("MainWindow", "Projects", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Stories", nullptr));
        Username_label->setText(QCoreApplication::translate("MainWindow", "Logged in as:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
