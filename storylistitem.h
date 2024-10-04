#ifndef STORYLISTITEM_H
#define STORYLISTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class StoryListItem : public QWidget {
    Q_OBJECT

public:
    explicit StoryListItem(int storyId, const QString &title, const QString &description, QWidget *parent = nullptr);

signals:
    void deleteStory(int storyId);

private slots:
    void onDeleteButtonClicked();

private:
    int storyId;
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QPushButton *deleteButton;
};

#endif
