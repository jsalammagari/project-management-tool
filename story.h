#ifndef STORY_H
#define STORY_H

#include <QString>
#include <QDate>

class Story {
public:
    Story(const QString& title, const QString& description, const QString& status, int requiredHours, QDate startdate, QDate enddate)
        : title(title), description(description), status(status), requiredHours(requiredHours), startdate(startdate), enddate(enddate) {}

    QString getTitle() const { return title; }
    void setTitle(const QString &title) { this->title = title; }

    QString getDescription() const { return description; }
    void setDescription(const QString &description) { this->description = description; }

    QString getStatus() const { return status; }
    void setStatus(const QString &status) { this->status = status; }

    QDate getStartdate() const { return startdate; }
    void setStartdate(const QDate &startdate) { this->startdate = startdate; }

    QDate getEnddate() const { return enddate; }
    void setEnddate(const QDate &enddate) { this->enddate = enddate; }

    int getrequiredHours() const { return requiredHours; }
    void setrequiredHours(const int &requiredHours) { this->requiredHours = requiredHours; }

    QString toString() const {
        return QString("%1 - %2\nStatus: %3, - Hours: %4\nStart Date: %5, End Date: %6")
            .arg(title)
            .arg(description)
            .arg(status)
            .arg(requiredHours)
            .arg(startdate.toString("MM-dd-yyyy"))
            .arg(enddate.toString("MM-dd-yyyy"));
    }

private:
    QString title;
    QString description;
    QString status;
    int requiredHours;
    QDate startdate;
    QDate enddate;
};

#endif
