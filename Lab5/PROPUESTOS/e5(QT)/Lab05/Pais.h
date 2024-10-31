#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Pais; }
QT_END_NAMESPACE

class Pais : public QWidget {
    Q_OBJECT

public:
    explicit Pais(QWidget *parent = nullptr);
    ~Pais();

signals:
    void removed(Pais* pais);

private slots:
    void editPais();

private:
    Ui::Pais *ui;
    QString pais;
    QString capital;
};
