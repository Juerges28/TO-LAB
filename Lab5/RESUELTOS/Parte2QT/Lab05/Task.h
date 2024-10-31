#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Task; }
QT_END_NAMESPACE

class Task : public QWidget {
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

signals:
    void removed(Task* task);

private:
    Ui::Task *ui;
};
