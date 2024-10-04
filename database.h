#ifndef DATABASE_H
#define DATABASE_H
#include <QList>
#include "project.h"
#include <QString>
#include <QDate>
#include <QSqlDatabase>

class DatabaseManager {
public:
    static bool initializeDatabase();
    static bool addUser(const QString &username, const QString &password);
    static bool authenticate(const QString &username, const QString &password);
    static bool addProject(const QString &name, const QString &description, const QDate &startDate, const QDate &endDate);
    static int getProjectId(const QString &projectName);
    static int getStoryId(const QString &storyName);
    static QList<Project> getProjects();
    static bool editProject(int projectId, const QString &name, const QString &description, const QString &startDate, const QString &endDate);
    static bool deleteProject(int projectId);
    static bool addStoryToDatabase(const Story &story, int projectId);
    static QList<Story> getStoriesForProject(int projectId);
    static bool editStory(int storyId, const Story &updatedStory);
    static bool deleteStory(int storyId);

private:
    static QSqlDatabase db;
};

#endif
