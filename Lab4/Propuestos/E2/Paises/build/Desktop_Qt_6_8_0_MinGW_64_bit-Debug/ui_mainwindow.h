/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayoutRight;
    QListWidget *listWidget;
    QLabel *labelCapital;
    QLabel *labelLenguaje;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(619, 403);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #333333;"));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayoutRight = new QVBoxLayout();
        verticalLayoutRight->setObjectName("verticalLayoutRight");
        verticalLayoutRight->setSizeConstraint(QLayout::SizeConstraint::SetMinAndMaxSize);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(150, 200));

        verticalLayoutRight->addWidget(listWidget);

        labelCapital = new QLabel(centralwidget);
        labelCapital->setObjectName("labelCapital");
        labelCapital->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #333333;"));
        labelCapital->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutRight->addWidget(labelCapital);

        labelLenguaje = new QLabel(centralwidget);
        labelLenguaje->setObjectName("labelLenguaje");
        labelLenguaje->setEnabled(true);
        labelLenguaje->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #333333;"));
        labelLenguaje->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutRight->addWidget(labelLenguaje);


        horizontalLayout->addLayout(verticalLayoutRight);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Informaci\303\263n de Pa\303\255ses", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Informaci\303\263n de Pa\303\255ses", nullptr));
        labelCapital->setText(QCoreApplication::translate("MainWindow", "Seleccione un pa\303\255s", nullptr));
        labelLenguaje->setText(QCoreApplication::translate("MainWindow", "El idioma aparecer\303\241 aqu\303\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
