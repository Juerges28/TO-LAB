#pragma once

#include <QDialog>

namespace Ui {
class EditPaisDialog;
}

class EditPaisDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditPaisDialog(QWidget *parent = nullptr);
    ~EditPaisDialog();

    void setPaisInfo(const QString &pais, const QString &capital);
    QString getPais() const;
    QString getCapital() const;

private:
    Ui::EditPaisDialog *ui;
};
