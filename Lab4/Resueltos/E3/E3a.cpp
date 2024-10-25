#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Lambda que suma 3 al número dado
    auto s = [](int valor) { return valor + 3; };

    int u = 5; // Ejemplo de número a sumar
    qDebug() << s(u); // Imprime el resultado de sumar 3 a u

    return a.exec();
}
