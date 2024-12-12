#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;

class Planta {
protected:
    string nombre;
    string descripcion;

public:
    Planta(const string& nombre, const string& descripcion)
        : nombre(nombre), descripcion(descripcion) {}
    virtual ~Planta() {}

    virtual Planta* clonar() const = 0;

    string getNombre() const { return nombre; }
    string getDescripcion() const { return descripcion; }
};

class Trepadora : public Planta {
public:
    Trepadora(const string& nombre, const string& descripcion)
        : Planta(nombre, descripcion) {}

    Planta* clonar() const override {
        return new Trepadora(*this);
    }
};

class ArbolNormal : public Planta {
public:
    ArbolNormal(const string& nombre, const string& descripcion)
        : Planta(nombre, descripcion) {}

    Planta* clonar() const override {
        return new ArbolNormal(*this);
    }
};

class Ornamental : public Planta {
public:
    Ornamental(const string& nombre, const string& descripcion)
        : Planta(nombre, descripcion) {}

    Planta* clonar() const override {
        return new Ornamental(*this);
    }
};

class Bonsai : public Planta {
public:
    Bonsai(const string& nombre, const string& descripcion)
        : Planta(nombre, descripcion) {}

    Planta* clonar() const override {
        return new Bonsai(*this);
    }
};

class Vivero {
private:
    unordered_map<string, unique_ptr<Planta>> prototipos;

public:
    void registrarPrototipo(const string& tipo, Planta* planta) {
        prototipos[tipo] = unique_ptr<Planta>(planta);
    }

    Planta* crearPlanta(const string& tipo) const {
        if (prototipos.find(tipo) != prototipos.end()) {
            return prototipos.at(tipo)->clonar();
        }
        return nullptr;
    }
};

int main() {
    Vivero vivero;

    // Registrar prototipos
    vivero.registrarPrototipo("Trepadora", new Trepadora("Trepadora Genérica", "Descripción Trepadora"));
    vivero.registrarPrototipo("ArbolNormal", new ArbolNormal("Árbol Genérico", "Descripción Árbol"));
    vivero.registrarPrototipo("Ornamental", new Ornamental("Ornamental Genérica", "Descripción Ornamental"));
    vivero.registrarPrototipo("Bonsai", new Bonsai("Bonsái Genérico", "Descripción Bonsái"));

    // Crear plantas a partir de prototipos
    auto planta1 = unique_ptr<Planta>(vivero.crearPlanta("Trepadora"));
    auto planta2 = unique_ptr<Planta>(vivero.crearPlanta("Bonsai"));

    cout << planta1->getNombre() << ": " << planta1->getDescripcion() << endl;
    cout << planta2->getNombre() << ": " << planta2->getDescripcion() << endl;

    return 0;
}
