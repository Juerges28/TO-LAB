#include "Pais.h"
#include "ui_Pais.h"
#include "EditPaisDialog.h"
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>

Pais::Pais(QWidget *parent) :
    QWidget(parent), ui(new Ui::Pais), pais("Perú"), capital("Lima") {
    ui->setupUi(this);

    ui->labelPais->setText(pais + " - " + capital);

    connect(ui->removeButton, &QPushButton::clicked, this, [this]() {
        emit removed(this);
    });

    connect(ui->editButton, &QPushButton::clicked, this, &Pais::editPais);

    setMinimumHeight(50);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

Pais::~Pais() {
    delete ui;
}

void Pais::editPais() {
    EditPaisDialog dialog(this);
    dialog.setPaisInfo(pais, capital);
    if (dialog.exec() == QDialog::Accepted) {
        pais = dialog.getPais();
        capital = dialog.getCapital();
        ui->labelPais->setText(pais + " - " + capital);
    }
}
