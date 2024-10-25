#include <QCoreApplication>
#include <QDebug>
#include "adulto.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    adulto *papa = new adulto;
    adulto *hijo1 = new adulto(papa);
    adulto *hijo2 = new adulto(papa);

    hijo1->setNombre("manuel");
    hijo2->setNombre("Jose");

    qDebug() << "Nombre del hijo 1:" << hijo1->getNombre();
    qDebug() << "Nombre del hijo 2:" << hijo2->getNombre();

    delete papa; // Destruye también a los hijos

    return a.exec();
}
