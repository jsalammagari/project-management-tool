#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

QSqlDatabase DatabaseManager::db = QSqlDatabase();

bool DatabaseManager::initializeDatabase() {
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dataDir);
    QString dbPath = dataDir + "/project_management.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qWarning() << "Database error: " << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS projects (id INTEGER PRIMARY KEY AUTOINCREMENT,name TEXT NOT NULL,description TEXT,start_date DATE,end_date DATE)");
    query.exec("CREATE TABLE IF NOT EXISTS stories (id INTEGER PRIMARY KEY AUTOINCREMENT, project_id INTEGER, title TEXT NOT NULL, description TEXT,status TEXT,required_hours INTEGER, start_date DATE,end_date DATE, FOREIGN KEY (project_id) REFERENCES projects(id));");
    query.exec("CREATE TABLE users (id INTEGER PRIMARY KEY, username TEXT NOT NULL UNIQUE, password TEXT NOT NULL);");

    qDebug() << "Database stored at:" << dbPath;
    return true;
}

bool DatabaseManager::addUser(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password); // Consider hashing the password

    if (!query.exec()) {
        qDebug() << "Failed to execute query";
        return false;
    }
    return true;
}

bool DatabaseManager::authenticate(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (!query.exec()) {
        qDebug() << "Failed to execute query";
        return false;
    }

    if (query.next()) {
        QString storedPassword = query.value(0).toString();
        if (storedPassword == password) {
            qDebug() << "login true";
            return true;
        }
    }
    return false;
}

bool DatabaseManager::addProject(const QString &name, const QString &description, const QDate &startDate, const QDate &endDate) {
    QSqlQuery query;
    query.prepare("INSERT INTO projects (name, description, start_date, end_date) VALUES (:name, :description, :start_date, :end_date)");
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);

    if (!query.exec()) {
        qWarning() << "Failed to insert project: " << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::addStoryToDatabase(const Story &story, int projectId) {
    QSqlQuery query;
    query.prepare("INSERT INTO stories (project_id, title, description, status, required_hours, start_date, end_date) "
                  "VALUES (:project_id, :title, :description, :status, :required_hours, :start_date, :end_date)");
    query.bindValue(":project_id", projectId);
    query.bindValue(":title", story.getTitle());
    query.bindValue(":description", story.getDescription());
    query.bindValue(":status", story.getStatus());
    query.bindValue(":required_hours", story.getrequiredHours());
    query.bindValue(":start_date", story.getStartdate());
    query.bindValue(":end_date", story.getEnddate());

    if (!query.exec()) {
        qWarning() << "Failed to insert story: " << query.lastError().text();
        return false;
    }

    return true;
}

int DatabaseManager::getProjectId(const QString &projectName) {
    QSqlQuery query;
    query.prepare("SELECT id FROM projects WHERE name = :name");
    query.bindValue(":name", projectName);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}

QList<Project> DatabaseManager::getProjects() {
    QList<Project> projects;
    QSqlQuery query("SELECT name, description, start_date, end_date FROM projects");

    while (query.next()) {
        QString name = query.value(0).toString();
        QString description = query.value(1).toString();
        QDate startDate = QDate::fromString(query.value(2).toString(), "yyyy-MM-dd");
        QDate endDate = QDate::fromString(query.value(3).toString(), "yyyy-MM-dd");
        projects.append(Project(name, description, startDate, endDate));
    }

    return projects;
}

bool DatabaseManager::editProject(int projectId, const QString &name, const QString &description, const QString &startDate, const QString &endDate) {
    QSqlQuery query;
    query.prepare("UPDATE projects SET name = :name, description = :description, start_date = :start_date, end_date = :end_date "
                  "WHERE id = :id");
    query.bindValue(":id", projectId);
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);

    if (!query.exec()) {
        qWarning() << "Failed to update project: " << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::deleteProject(int projectId) {
    QSqlQuery query;
    query.prepare("DELETE FROM projects WHERE id = :id");
    query.bindValue(":id", projectId);

    if (!query.exec()) {
        qWarning() << "Failed to delete project: " << query.lastError().text();
        return false;
    }

    return true;
}


bool DatabaseManager::editStory(int storyId, const Story &updatedStory) {
    QSqlQuery query;
    query.prepare("UPDATE stories SET title = :title, description = :description, status = :status, required_hours = :required_hours, start_date = :start_date, end_date = :end_date "
                  "WHERE id = :id");
    query.bindValue(":id", storyId);
    query.bindValue(":title", updatedStory.getTitle());
    query.bindValue(":description", updatedStory.getDescription());
    query.bindValue(":status", updatedStory.getStatus());
    query.bindValue(":required_hours", updatedStory.getrequiredHours());
    query.bindValue(":start_date", updatedStory.getStartdate());
    query.bindValue(":end_date", updatedStory.getEnddate());

    if (!query.exec()) {
        qWarning() << "Failed to update story: " << query.lastError().text();
        return false;
    }

    return true;
}

int DatabaseManager::getStoryId(const QString &storyName) {
    QSqlQuery query;
    query.prepare("SELECT id FROM stories WHERE title = :title");
    query.bindValue(":title", storyName);

    if (query.exec()&& query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}

bool DatabaseManager::deleteStory(int storyId) {
    QSqlQuery query;
    query.prepare("DELETE FROM stories WHERE id = :id");
    query.bindValue(":id", storyId);

    if (!query.exec()) {
        qWarning() << "Failed to delete story: " << query.lastError().text();
        return false;
    }

    return true;
}

QList<Story> DatabaseManager::getStoriesForProject(int projectId) {
    QList<Story> stories;
    QSqlQuery query;
    query.prepare("SELECT title, description, status, required_hours, start_date, end_date FROM stories WHERE project_id = :project_id");
    query.bindValue(":project_id", projectId);

    if (query.exec()) {
        while (query.next()) {
            QString title = query.value(0).toString();
            QString description = query.value(1).toString();
            QString status = query.value(2).toString();
            int requiredHours = query.value(3).toInt();
            QDate startDate = QDate::fromString(query.value(4).toString(), "yyyy-MM-dd");
            QDate endDate = QDate::fromString(query.value(5).toString(), "yyyy-MM-dd");
            stories.append(Story(title, description, status, requiredHours, startDate, endDate));
        }
    } else {
        qWarning() << "Error fetching stories: " << query.lastError().text();
    }

    return stories;
}
