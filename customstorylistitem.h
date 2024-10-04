#ifndef CUSTOMSTORYLISTITEM_H
#define CUSTOMSTORYLISTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVariant>
#include "story.h"

class CustomstoryListItem : public QWidget {
    Q_OBJECT
public:
    explicit CustomstoryListItem(const Story& story, QWidget* parent = nullptr) : QWidget(parent) {
        QHBoxLayout* layout = new QHBoxLayout(this);
        QLabel* label = new QLabel(QString("%1 : %2\nStatus: %3, Hours: %4\nFrom %5 To %6")
                                       .arg(story.getTitle())
                                       .arg(story.getDescription())
                                       .arg(story.getStatus())
                                       .arg(story.getrequiredHours())
                                       .arg(story.getStartdate().toString("MM-dd-yyyy"))
                                       .arg(story.getEnddate().toString("MM-dd-yyyy")), this);
        QPushButton* btndeleteStory = new QPushButton("Delete", this);
        btndeleteStory->setMaximumWidth(70);
        QPushButton* btneditStory = new QPushButton("Edit", this);
        btneditStory->setMaximumWidth(70);

        layout->addWidget(label);
        layout->addWidget(btneditStory);
        layout->addWidget(btndeleteStory);
        setLayout(layout);

        connect(btneditStory, &QPushButton::clicked, this, &CustomstoryListItem::onEditStoryClicked);
        connect(btndeleteStory, &QPushButton::clicked, this, &CustomstoryListItem::onDeleteStoryClicked);
    }

signals:
    void deleteStoryClicked();
    void editStoryClicked();

private slots:
    void onDeleteStoryClicked() {
        emit deleteStoryClicked();
    }
    void onEditStoryClicked() {
        emit editStoryClicked();
    }
};

#endif
