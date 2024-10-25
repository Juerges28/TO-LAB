#include <QCoreApplication>
#include <QDebug>
#include "adulto.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Creación de objetos adulto
    adulto *papa = new adulto;
    adulto *pepe = new adulto(papa);
    adulto *jose = new adulto(papa);

    pepe->setNombre("Pepe");
    jose->setNombre("Jose");

    // Conexión de señales y slots entre las instancias de Comunicacion de los adultos
    QObject::connect(pepe->getComunicacion(), SIGNAL(enviarmensaje(QString)), jose->getComunicacion(), SLOT(escuchar(QString)));
    QObject::connect(jose->getComunicacion(), SIGNAL(enviarmensaje(QString)), pepe->getComunicacion(), SLOT(escuchar(QString)));

    pepe->getComunicacion()->conversar("Buenos días");
    jose->getComunicacion()->conversar("¿Cómo vas?");

    delete papa;

    return a.exec();
}
