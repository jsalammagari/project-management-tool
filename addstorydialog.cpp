#include "AddStoryDialog.h"

AddStoryDialog::AddStoryDialog(QWidget *parent) : QDialog(parent) {
    titleEdit = new QLineEdit(this);
    descriptionEdit = new QLineEdit(this);
    statusComboBox = new QComboBox(this);
    startDateEdit = new QDateEdit(QDate::currentDate(), this);
    endDateEdit = new QDateEdit(QDate::currentDate(), this);
    requiredHoursSpinBox = new QSpinBox(this);

    statusComboBox->addItems({"Planned", "In Progress", "Completed"});
    requiredHoursSpinBox->setRange(1, 1000);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Title", titleEdit);
    formLayout->addRow("Description", descriptionEdit);
    formLayout->addRow("Status", statusComboBox);
    formLayout->addRow("Start Date", startDateEdit);
    formLayout->addRow("End Date", endDateEdit);
    formLayout->addRow("Required Hours", requiredHoursSpinBox);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

QString AddStoryDialog::getTitle() const { return titleEdit->text(); }
QString AddStoryDialog::getDescription() const { return descriptionEdit->text(); }
QString AddStoryDialog::getStatus() const { return statusComboBox->currentText(); }
QDate AddStoryDialog::getStartDate() const { return startDateEdit->date(); }
QDate AddStoryDialog::getEndDate() const { return endDateEdit->date(); }
int AddStoryDialog::getRequiredHours() const { return requiredHoursSpinBox->value(); }
