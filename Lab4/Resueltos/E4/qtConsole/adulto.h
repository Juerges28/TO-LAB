#ifndef ADULTO_H
#define ADULTO_H

#include <QObject>
#include <QString>
#include <QDebug>

class adulto : public QObject {
    Q_OBJECT

private:
    QString nombre;

public:
    explicit adulto(QObject *parent = nullptr);

    void setNombre(const QString &nomb);
    QString getNombre() const;

    ~adulto();
};

#endif // ADULTO_H
