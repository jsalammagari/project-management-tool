#include "editprojectdialog.h"

EditProjectDialog::EditProjectDialog(QWidget *parent) : QDialog(parent) {
    nameEdit = new QLineEdit;
    descriptionEdit = new QLineEdit;
    startDateEdit = new QDateEdit(QDate::currentDate());
    endDateEdit = new QDateEdit(QDate::currentDate());

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Project Name"), nameEdit);
    layout->addRow(tr("Description"), descriptionEdit);
    layout->addRow(tr("Start Date"), startDateEdit);
    layout->addRow(tr("End Date"), endDateEdit);
    layout->addWidget(buttonBox);

    setLayout(layout);
}

QString EditProjectDialog::getProjectName() const { return nameEdit->text(); }
QString EditProjectDialog::getDescription() const { return descriptionEdit->text(); }
QDate EditProjectDialog::getStartDate() const { return startDateEdit->date(); }
QDate EditProjectDialog::getEndDate() const { return endDateEdit->date(); }
