#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Task.h"
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), tasks() {
    ui->setupUi(this);

    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addTask() {
    Task *task = new Task(this);
    ui->tasksLayout->addWidget(task);
    tasks.append(task);
    connect(task, &Task::removed, this, &MainWindow::removeTask);
    ui->tasksLayout->update();
}

void MainWindow::removeTask(Task* task) {
    ui->tasksLayout->removeWidget(task);
    tasks.removeOne(task);
    task->deleteLater();
    qDebug() << "Tarea eliminada.";
}
