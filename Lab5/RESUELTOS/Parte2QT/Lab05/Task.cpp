#include "Task.h"
#include "ui_Task.h"

Task::Task(QWidget *parent) :
    QWidget(parent), ui(new Ui::Task) {
    ui->setupUi(this);

    connect(ui->removeButton, &QPushButton::clicked, this, [this]() {
        emit removed(this);
    });

    setMinimumHeight(50);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

Task::~Task() {
    delete ui;
}
