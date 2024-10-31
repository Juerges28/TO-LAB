#pragma once

#include <QMainWindow>
#include <QVector>
#include "Pais.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addPais();
    void removePais(Pais* pais);

private:
    Ui::MainWindow *ui;
    QVector<Pais*> paises;
};
