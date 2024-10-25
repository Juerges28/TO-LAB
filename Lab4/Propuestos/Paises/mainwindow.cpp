#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow { background-color: #f7f7f7; }"
                        "QLabel { font-size: 16px; font-weight: bold; color: #333; }"
                        "QListWidget { background-color: #fff; border: 1px solid #ccc; padding: 5px; }"
                        "QListWidget::item { padding: 10px; color: #333; }"
                        "QListWidget::item:hover { background-color: #f0f8ff; color: #000; }"
                        "QPushButton { background-color: #6c63ff; color: white; border-radius: 5px; padding: 10px; }"
                        "QPushButton:hover { background-color: #514dcf; }"
                        "QFrame { background-color: #f0f0f0; border-radius: 8px; padding: 15px; }");

    countryCapital.insert("Alemania", "Berlín");
    countryCapital.insert("Francia", "París");
    countryCapital.insert("Italia", "Roma");
    countryCapital.insert("España", "Madrid");
    countryCapital.insert("Reino Unido", "Londres");
    countryCapital.insert("Portugal", "Lisboa");
    countryCapital.insert("Países Bajos", "Ámsterdam");
    countryCapital.insert("Suecia", "Estocolmo");
    countryCapital.insert("Noruega", "Oslo");
    countryCapital.insert("Suiza", "Berna");
    countryCapital.insert("Argentina", "Buenos Aires");
    countryCapital.insert("Bolivia", "Sucre");
    countryCapital.insert("Brasil", "Brasília");
    countryCapital.insert("Chile", "Santiago");
    countryCapital.insert("Colombia", "Bogotá");
    countryCapital.insert("Ecuador", "Quito");
    countryCapital.insert("Paraguay", "Asunción");
    countryCapital.insert("Perú", "Lima");
    countryCapital.insert("Uruguay", "Montevideo");
    countryCapital.insert("Venezuela", "Caracas");

    countryLanguage.insert("Alemania", "Alemán");
    countryLanguage.insert("Francia", "Francés");
    countryLanguage.insert("Italia", "Italiano");
    countryLanguage.insert("España", "Español");
    countryLanguage.insert("Reino Unido", "Inglés");
    countryLanguage.insert("Portugal", "Portugués");
    countryLanguage.insert("Países Bajos", "Neerlandés");
    countryLanguage.insert("Suecia", "Sueco");
    countryLanguage.insert("Noruega", "Noruego");
    countryLanguage.insert("Suiza", "Alemán, Francés, Italiano");
    countryLanguage.insert("Argentina", "Español");
    countryLanguage.insert("Bolivia", "Español, Quechua, Aymara");
    countryLanguage.insert("Brasil", "Portugués");
    countryLanguage.insert("Chile", "Español");
    countryLanguage.insert("Colombia", "Español");
    countryLanguage.insert("Ecuador", "Español");
    countryLanguage.insert("Paraguay", "Español, Guaraní");
    countryLanguage.insert("Perú", "Español, Quechua, Aymara");
    countryLanguage.insert("Uruguay", "Español");
    countryLanguage.insert("Venezuela", "Español");

    QStringList countries = countryCapital.keys();
    foreach (const QString &country, countries) {
        QListWidgetItem *item = new QListWidgetItem(country);
        ui->listWidget->addItem(item);
    }

    ui->labelCapital->setText("Seleccione un país");
    ui->labelLenguaje->setText("El idioma aparecerá aquí");
    ui->labelCapital->setStyleSheet("color: #333333; font-size: 14px;");
    ui->labelLenguaje->setStyleSheet("color: #333333; font-size: 14px;");

    ui->listWidget->setMinimumHeight(150);
    ui->listWidget->setMinimumWidth(200);
    ui->labelCapital->setMinimumHeight(30);
    ui->labelLenguaje->setMinimumHeight(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString country = item->text();
    QString capital = countryCapital.value(country, "Capital no disponible.");
    QString language = countryLanguage.value(country, "Idioma no disponible.");

    ui->labelCapital->setText("<b>Capital:</b> " + capital);
    ui->labelLenguaje->setText("<b>Idioma:</b> " + language);
}
