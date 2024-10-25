#include "adulto.h"

adulto::adulto(QObject *parent) : QObject(parent) {
}

void adulto::setNombre(const QString &nomb) {
    nombre = nomb;
}

QString adulto::getNombre() const {
    return nombre;
}

adulto::~adulto() {
    qDebug() << "..objeto destruido...";
}
