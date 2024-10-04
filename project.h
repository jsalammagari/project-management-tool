#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include "story.h"

class Project {
public:
    Project(const QString &name, const QString &description, const QDate &startDate, const QDate &endDate)
        : id(-1), name(name), description(description), startDate(startDate), endDate(endDate) {}

    int getId() const { return id; }
    QString getName() const { return name; }
    QString getDescription() const { return description; }
    QDate getStartDate() const { return startDate; }
    QDate getEndDate() const { return endDate; }

    void setName(const QString &name) { this->name = name; }
    void setDescription(const QString &description) { this->description = description; }
    void setStartDate(const QDate &startDate) { this->startDate = startDate; }
    void setEndDate(const QDate &endDate) { this->endDate = endDate; }

    int id;
    QString name;
    QString description;
    QDate startDate;
    QDate endDate;
    QList<Story> stories;

    QString toString() const {
        return QString("%1 - %2\nStart Date: %3, End Date: %4")
            .arg(name)
            .arg(description)
            .arg(startDate.toString("MM-dd-yyyy"))
            .arg(endDate.toString("MM-dd-yyyy"));
    }

    QList<Story> getStories() const {
        return stories;
    }

    void addStory(Story &story) {
        stories.append(story);
    }

};

Q_DECLARE_METATYPE(Project)

#endif
