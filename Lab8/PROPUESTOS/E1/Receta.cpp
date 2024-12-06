#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Clase base
class Receta {
protected:
    string nombre;
    vector<string> ingredientes;
    string instrucciones;

public:
    virtual void prepararIngredientes() = 0;
    virtual void cocinar() = 0;
    virtual void mostrarDetalles() = 0;
    virtual ~Receta() {}
};

// Cocina italiana
class RecetaItaliana : public Receta {
public:
    RecetaItaliana() {
        nombre = "Pasta Carbonara";
        ingredientes = {"Espagueti", "Huevos", "Queso Pecorino", "Panceta", "Pimienta negra"};
        instrucciones = "1. Cocina el espagueti. 2. Prepara la salsa con huevos y queso. "
                        "3. Fríe la panceta. 4. Combina todo y sirve.";
    }

    void prepararIngredientes() override {
        cout << "Preparando ingredientes para: " << nombre << endl;
    }

    void cocinar() override {
        cout << "Cocinando según las instrucciones: " << endl << instrucciones << endl;
    }

    void mostrarDetalles() override {
        cout << "\nReceta Italiana: " << nombre << endl;
        cout << "Ingredientes: ";
        for (const string &ing : ingredientes) {
            cout << ing << ", ";
        }
        cout << endl;
        cocinar();
    }
};

// Cocina mexicana
class RecetaMexicana : public Receta {
public:
    RecetaMexicana() {
        nombre = "Tacos al Pastor";
        ingredientes = {"Tortillas", "Carne de cerdo", "Piña", "Cilantro", "Cebolla", "Salsa"};
        instrucciones = "1. Cocina la carne marinada. 2. Calienta las tortillas. "
                        "3. Sirve con piña, cilantro y cebolla. 4. Acompaña con salsa.";
    }

    void prepararIngredientes() override {
        cout << "Preparando ingredientes para: " << nombre << endl;
    }

    void cocinar() override {
        cout << "Cocinando según las instrucciones: " << endl << instrucciones << endl;
    }

    void mostrarDetalles() override {
        cout << "\nReceta Mexicana: " << nombre << endl;
        cout << "Ingredientes: ";
        for (const string &ing : ingredientes) {
            cout << ing << ", ";
        }
        cout << endl;
        cocinar();
    }
};

// Cocina japonesa
class RecetaJaponesa : public Receta {
public:
    RecetaJaponesa() {
        nombre = "Sushi de Salmón";
        ingredientes = {"Arroz", "Salmón", "Alga nori", "Vinagre de arroz", "Salsa de soja", "Wasabi"};
        instrucciones = "1. Cocina el arroz y mézclalo con vinagre. 2. Corta el salmón. "
                        "3. Enrolla el sushi con nori. 4. Sirve con salsa de soja y wasabi.";
    }

    void prepararIngredientes() override {
        cout << "Preparando ingredientes para: " << nombre << endl;
    }

    void cocinar() override {
        cout << "Cocinando según las instrucciones: " << endl << instrucciones << endl;
    }

    void mostrarDetalles() override {
        cout << "\nReceta Japonesa: " << nombre << endl;
        cout << "Ingredientes: ";
        for (const string &ing : ingredientes) {
            cout << ing << ", ";
        }
        cout << endl;
        cocinar();
    }
};
