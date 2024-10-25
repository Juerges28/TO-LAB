#ifndef ADULTO_H
#define ADULTO_H

#include <QObject>
#include <QDebug>
#include "comunicacion.h"  // Incluimos la clase Comunicacion

class adulto : public QObject
{
    Q_OBJECT
public:
    explicit adulto(QObject *parent = nullptr);
    ~adulto();

    void setNombre(const QString &nomb);
    QString getNombre() const;

    Comunicacion* getComunicacion() const;

private:
    QString nombre;
    Comunicacion* comunicacion;  // Cada adulto tiene su objeto Comunicacion
};

#endif // ADULTO_H
