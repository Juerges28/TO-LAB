#include "adulto.h"

adulto::adulto(QObject *parent) : QObject(parent) {
    comunicacion = new Comunicacion(this);  // Creamos un objeto Comunicacion
}

void adulto::setNombre(const QString &nomb) {
    nombre = nomb;
}

QString adulto::getNombre() const {
    return nombre;
}

Comunicacion* adulto::getComunicacion() const {
    return comunicacion;
}

adulto::~adulto() {
    delete comunicacion;  // Destruimos el objeto Comunicacion cuando el adulto se destruye
    qDebug() << nombre << "..objeto adulto destruido...";
}
