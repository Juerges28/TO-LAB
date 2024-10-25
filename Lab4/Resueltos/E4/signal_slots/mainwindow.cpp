#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar el botón al nuevo slot 'addTask'
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;  // Siempre se debe eliminar en el destructor
}

void MainWindow::addTask()
{
    qDebug() << "Slot corresponde al clic en el botón: añadir tarea.";
}
