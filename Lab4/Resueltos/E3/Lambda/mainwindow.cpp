#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sumButton, &QPushButton::clicked, this, &MainWindow::sumaNumero);
    connect(ui->vectorButton, &QPushButton::clicked, this, &MainWindow::recorrerVector);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sumaNumero()
{
    // Lambda que suma 3 al número dado
    auto s = [](int valor) { return valor + 3; };

    int u = 5; // Ejemplo de número a sumar
    int resultado = s(u);
    qDebug() << s(u);

    ui->sumLabel->setText("Resultado de la suma: " + QString::number(resultado));
}

void MainWindow::recorrerVector()
{
    std::vector<int> v {5, 2, 3, 7, 1, 0, 14, 20};

    QString resultado; // Usaremos esta variable para almacenar la salida
    // Lambda que concatena los elementos del vector en una cadena
    std::for_each(v.begin(), v.end(), [&resultado](int valor) {
        resultado += QString::number(valor) + " ";
        qDebug() << "Valor del vector:" << valor;
    });

    ui->vectorLabel->setText("Elementos del vector: " + resultado);
}
