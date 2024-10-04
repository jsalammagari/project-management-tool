#ifndef ADDSTORYDIALOG_H
#define ADDSTORYDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QVBoxLayout>

class AddStoryDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddStoryDialog(QWidget *parent = nullptr);
    QString getTitle() const;
    QString getDescription() const;
    QString getStatus() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
    int getRequiredHours() const;
    QLineEdit *titleEdit;
    QLineEdit *descriptionEdit;
    QComboBox *statusComboBox;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QSpinBox *requiredHoursSpinBox;
};

#endif
