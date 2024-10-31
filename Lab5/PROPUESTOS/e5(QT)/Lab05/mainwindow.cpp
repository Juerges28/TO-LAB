#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Pais.h"
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), paises() {
    ui->setupUi(this);

    connect(ui->addPaisButton, &QPushButton::clicked, this, &MainWindow::addPais);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addPais() {
    Pais *pais = new Pais(this);
    ui->paisLayout->addWidget(pais);
    paises.append(pais);
    connect(pais, &Pais::removed, this, &MainWindow::removePais);
    ui->paisLayout->update();
}

void MainWindow::removePais(Pais* pais) {
    ui->paisLayout->removeWidget(pais);
    paises.removeOne(pais);
    pais->deleteLater();
    qDebug() << "Tarea eliminada.";
}
