#ifndef CUSTOMLISTITEM_H
#define CUSTOMLISTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVariant>
#include "project.h"

class CustomListItem : public QWidget {
    Q_OBJECT
public:
    explicit CustomListItem(const Project& project, QWidget* parent = nullptr) : QWidget(parent) {
        QHBoxLayout* layout = new QHBoxLayout(this);
        QLabel* label = new QLabel(QString("%1 : %2\nFrom %3 To %4").arg(project.name, project.description, project.startDate.toString("MM-dd-yyyy"), project.endDate.toString("MM-dd-yyyy")), this);
        QPushButton* btnCreateStory = new QPushButton("Create Story", this);
        btnCreateStory->setMaximumWidth(100);

        layout->addWidget(label);
        layout->addWidget(btnCreateStory);
        setLayout(layout);

        connect(btnCreateStory, &QPushButton::clicked, this, &CustomListItem::onCreateStoryClicked);
    }

signals:
    void createStoryClicked();

private slots:
    void onCreateStoryClicked() {
        emit createStoryClicked();
    }
};

#endif
