#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "project.h"
#include "editprojectdialog.h"
#include "addstorydialog.h"
#include "CustomListItem.h"
#include "customstorylistitem.h"
#include "database.h"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->createprojectButton, &QPushButton::clicked, this, &MainWindow::createProject);
    connect(ui->editprojectButton, &QPushButton::clicked, this, &MainWindow::editSelectedProject);
    connect(ui->deleteprojectButton, &QPushButton::clicked, this, &MainWindow::deleteSelectedProject);
    connect(ui->refreshprojectButton, &QPushButton::clicked, this, &MainWindow::refreshProjectList);
    connect(ui->projectList, &QListWidget::itemSelectionChanged, this, &MainWindow::onProjectSelected);

    ui->startdate->setDate(QDate::currentDate());
    ui->enddate->setDate(QDate::currentDate());

    refreshProjectList();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupDatabase() {
    if (!DatabaseManager::initializeDatabase()) {
        qDebug() << "Database setup failed";
    }
}

void MainWindow::setUsername(const QString &username) {
    QString displayText = "Logged in as: " + username;
    ui->Username_label->setText(displayText);
}

void MainWindow::createProject() {
    QString projectName = ui->projectname->toPlainText();
    QString description = ui->descriptionText->toPlainText();
    QDate startDate = ui->startdate->date();
    QDate endDate = ui->enddate->date();

    if (!DatabaseManager::addProject(projectName, description, startDate, endDate)) {
        qDebug() << "Failed to add project to the database";
    } else {
        Project newProject(projectName, description, startDate, endDate);
        projects.append(newProject);

        QString itemText = QString("%1 - %2\nStart Date: %3, End Date: %4")
                               .arg(newProject.getName())
                               .arg(newProject.getDescription())
                               .arg(newProject.getStartDate().toString("MM-dd-yyyy"))
                               .arg(newProject.getEndDate().toString("MM-dd-yyyy"));

        QListWidgetItem *item = new QListWidgetItem(itemText);
        CustomListItem* customItemWidget = new CustomListItem(newProject);

        item->setSizeHint(customItemWidget->sizeHint());
        ui->projectList->addItem(item);

        ui->projectList->setItemWidget(item, customItemWidget);
        connect(customItemWidget, &CustomListItem::createStoryClicked, [this, newProject]() {
            this->createStory(newProject);
        });
    }

    ui->projectname->clear();
    ui->descriptionText->clear();

    ui->startdate->setDate(QDate::currentDate());
    ui->enddate->setDate(QDate::currentDate());

    ui->projectname->clearFocus();
    ui->descriptionText->clearFocus();
}

void MainWindow::createStory(const Project& currentProject) {
    int index = ui->projectList->currentRow();
    const Project& selectedProject = projects[index];
    int projectid = DatabaseManager::getProjectId(selectedProject.getName());
    AddStoryDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString title = dialog.getTitle();
        QString description = dialog.getDescription();
        QString status = dialog.getStatus();
        QDate startDate = dialog.getStartDate();
        QDate endDate = dialog.getEndDate();
        int requiredHours = dialog.getRequiredHours();

        Story newStory(title, description, status, requiredHours, startDate, endDate);
        stories.append(newStory);
        if (DatabaseManager::addStoryToDatabase(newStory, projectid)) {
            this->onProjectSelected();
        } else {
            qDebug() << "Failed to add story to the database";
        }
    }
}

void MainWindow::editSelectedProject() {
    QListWidgetItem *currentItem = ui->projectList->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Edit Project", "Please select a project to edit.");
        return;
    }

    EditProjectDialog dialog(this);

    int currentRow = ui->projectList->row(currentItem);
    int projectIndex = ui->projectList->currentRow();
    const Project& selectedProject = projects[projectIndex];
    int projectid = DatabaseManager::getProjectId(selectedProject.getName());
    const Project &currentProject = projects.at(currentRow);
    dialog.nameEdit->setText(currentProject.getName());
    dialog.descriptionEdit->setText(currentProject.getDescription());
    dialog.startDateEdit->setDate(currentProject.getStartDate());
    dialog.endDateEdit->setDate(currentProject.getEndDate());

    if (dialog.exec() == QDialog::Accepted) {
        QString updatedName = dialog.getProjectName();
        QString updatedDescription = dialog.getDescription();
        QString updatedStartDate = dialog.getStartDate().toString("yyyy-MM-dd");
        QString updatedEndDate = dialog.getEndDate().toString("yyyy-MM-dd");

        if (DatabaseManager::editProject(projectid, updatedName, updatedDescription, updatedStartDate, updatedEndDate)) {

            projects[currentRow].setName(dialog.getProjectName());
            projects[currentRow].setDescription(dialog.getDescription());
            projects[currentRow].setStartDate(dialog.getStartDate());
            projects[currentRow].setEndDate(dialog.getEndDate());

            currentItem->setText(projects[currentRow].toString());
        }else{
            qDebug() << "Failed to update project";
        }
        refreshProjectList();
    }

}

void MainWindow::deleteSelectedProject() {
    int currentRow = ui->projectList->currentRow();
    int projectIndex = ui->projectList->currentRow();
    const Project& selectedProject = projects[projectIndex];
    int projectid = DatabaseManager::getProjectId(selectedProject.getName());

    if (currentRow != -1) {
        if (QMessageBox::question(this, "Delete Project", "Do you want to delete this project!!") == QMessageBox::Yes) {
            if (DatabaseManager::deleteProject(projectid)) {
                // Remove the project from the internal list and UI
                ui->projectList->clear();
                projects.removeAt(currentRow);
                ui->projectList->clearSelection();
                refreshProjectList();
            } else {
                qDebug() << "Failed to delete project";
            }
        }
    } else {
        QMessageBox::warning(this, "Delete Project", "Please select a project to delete.");
    }
}

void MainWindow::editSelectedStory() {
    QListWidgetItem *currentItem = ui->storyList->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Edit Story", "Please select a story to edit.");
        return;
    }

    AddStoryDialog dialog(this);

    int currentRow = ui->storyList->row(currentItem);
    int index = ui->storyList->currentRow();
    const Story& selectedStory = stories[index];
    int storyid = DatabaseManager::getStoryId(selectedStory.getTitle());
    const Story &currentStory = stories.at(currentRow);
    dialog.titleEdit->setText(currentStory.getTitle());
    dialog.descriptionEdit->setText(currentStory.getDescription());
    dialog.startDateEdit->setDate(currentStory.getStartdate());
    dialog.endDateEdit->setDate(currentStory.getEnddate());
    dialog.requiredHoursSpinBox->setValue(currentStory.getrequiredHours());
    dialog.statusComboBox->setCurrentText(currentStory.getStatus());

    if (dialog.exec() == QDialog::Accepted) {
        QString updatedTitle = dialog.getTitle();
        QString updatedDescription = dialog.getDescription();
        QDate updatedStartDate = dialog.getStartDate();
        QDate updatedEndDate = dialog.getEndDate();
        QString status = dialog.getStatus();
        int hours = dialog.getRequiredHours();
        Story updatedStory(updatedTitle, updatedDescription, status, hours, updatedStartDate, updatedEndDate);

        if (DatabaseManager::editStory(storyid, updatedStory)) {
            stories[currentRow].setTitle(dialog.getTitle());
            stories[currentRow].setDescription(dialog.getDescription());
            stories[currentRow].setStatus(dialog.getStatus());
            stories[currentRow].setrequiredHours(dialog.getRequiredHours());
            stories[currentRow].setStartdate(dialog.getStartDate());
            stories[currentRow].setEnddate(dialog.getEndDate());

            currentItem->setText(stories[currentRow].toString());
        }else{
            qDebug() << "Failed to update story";
        }
        refreshProjectList();
    }

}

void MainWindow::deleteSelectedStory() {
    int currentRow = ui->storyList->currentRow();
    int index = ui->storyList->currentRow();
    const Story& selectedStory = stories[index];
    int id = DatabaseManager::getStoryId(selectedStory.getTitle());

    if (currentRow != -1) {
        if (QMessageBox::question(this, "Delete Story", "Do you want to delete this story!!") == QMessageBox::Yes) {
            if (DatabaseManager::deleteStory(id)) {
                stories.removeAt(currentRow);
                refreshProjectList();
            } else {
                qDebug() << "Failed to delete story";
            }
        }
    } else {
        QMessageBox::warning(this, "Delete Story", "Please select a story to delete.");
    }
}

void MainWindow::refreshProjectList() {
    ui->projectList->clear();
    projects = DatabaseManager::getProjects();
    for (const auto &project : projects) {
        QString itemText = QString("%1 - %2\nStart Date: %3, End Date: %4")
                               .arg(project.getName())
                               .arg(project.getDescription())
                               .arg(project.getStartDate().toString("MM-dd-yyyy"))
                               .arg(project.getEndDate().toString("MM-dd-yyyy"));

        QListWidgetItem *item = new QListWidgetItem(itemText);
        CustomListItem* customItemWidget = new CustomListItem(project);

        item->setSizeHint(customItemWidget->sizeHint());
        ui->projectList->addItem(item);

        ui->projectList->setItemWidget(item, customItemWidget);
        connect(customItemWidget, &CustomListItem::createStoryClicked, [this, project]() {
            this->createStory(project);
        });

        if (!ui->projectList->count() == 0) {
            ui->projectList->setCurrentRow(0);
            onProjectSelected();
        }
    }
}

void MainWindow::onProjectSelected() {
    ui->storyList->clear();

    if (ui->projectList->currentItem() == nullptr) {
        return;
    }

    int projectIndex = ui->projectList->currentRow();
    const Project& selectedProject = projects[projectIndex];
    int projectid = DatabaseManager::getProjectId(selectedProject.getName());

    stories = DatabaseManager::getStoriesForProject(projectid);

    for (const Story &story : stories) {
        QListWidgetItem *item = new QListWidgetItem();
        CustomstoryListItem* customItemWidget = new CustomstoryListItem(story);

        item->setSizeHint(customItemWidget->sizeHint());
        ui->storyList->addItem(item);

        ui->storyList->setItemWidget(item, customItemWidget);
        connect(customItemWidget, &CustomstoryListItem::editStoryClicked, [this, story]() {
            this->editSelectedStory();
        });
        connect(customItemWidget, &CustomstoryListItem::deleteStoryClicked, [this, story]() {
            this->deleteSelectedStory();
        });
    }
}
