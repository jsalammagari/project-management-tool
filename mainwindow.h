#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "project.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setUsername(const QString &username);
    ~MainWindow();

private slots:
    void createProject();
    void createStory(const Project& project);
    void refreshProjectList();
    void editSelectedProject();
    void editSelectedStory();
    void deleteSelectedProject();
    void deleteSelectedStory();
    void onProjectSelected();
    void setupDatabase();

private:
    Ui::MainWindow *ui;

    QList<Project> projects;
    QList<Story> stories;
    QLabel *usernameLabel;
};
#endif
