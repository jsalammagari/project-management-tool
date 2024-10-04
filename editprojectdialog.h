#ifndef EDITPROJECTDIALOG_H
#define EDITPROJECTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QDialogButtonBox>

class EditProjectDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditProjectDialog(QWidget *parent = nullptr);

    QString getProjectName() const;
    QString getDescription() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
    QLineEdit *nameEdit;
    QLineEdit *descriptionEdit;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
};

#endif
