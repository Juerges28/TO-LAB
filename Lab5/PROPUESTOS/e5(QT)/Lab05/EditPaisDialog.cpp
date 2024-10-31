#include "EditPaisDialog.h"
#include "ui_EditPaisDialog.h"

EditPaisDialog::EditPaisDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::EditPaisDialog) {
    ui->setupUi(this);

    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelarButton, &QPushButton::clicked, this, &QDialog::reject);
}

EditPaisDialog::~EditPaisDialog() {
    delete ui;
}

void EditPaisDialog::setPaisInfo(const QString &pais, const QString &capital) {
    ui->paisLineEdit->setText(pais);
    ui->capitalLineEdit->setText(capital);
}

QString EditPaisDialog::getPais() const {
    return ui->paisLineEdit->text();
}

QString EditPaisDialog::getCapital() const {
    return ui->capitalLineEdit->text();
}
