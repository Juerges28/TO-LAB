#include <iostream>
#include <memory>

using namespace std;

class Vehiculo {
public:
    string tipo;
    string motor;
    int ruedas;
    int capacidadPasajeros;
    int cargaMax;

    void mostrarCaracteristas(){
        cout << "Caracteristicas del vehiculo:" << endl;
        cout << "tipo: " << tipo << endl;
        cout << "motor: " << motor << endl;
        cout << "ruedas: " << ruedas << endl;
        cout << "capacidad de pasajeros: " << capacidadPasajeros << endl;
        cout << "carga maxima: " << cargaMax << endl;
        cout << "=====================================" << endl;
    }
};

class BuilderVehiculo {
public:
    virtual void definirTipo() = 0;
    virtual void instalarMotor() = 0;
    virtual void instalarRuedas() = 0;
    virtual void definirCapacidad() = 0;
    virtual void definirCargaMax()=0;
    virtual unique_ptr<Vehiculo> obtenerVehiculo() = 0;
};

class BuilderAutomovil : public BuilderVehiculo {
private:
    unique_ptr<Vehiculo> vehiculo;
public:
    BuilderAutomovil(){
        vehiculo = make_unique<Vehiculo>();
    }
    void definirTipo() override {
        vehiculo->tipo = "Automovil";
    }
    void instalarMotor() override {
        vehiculo->motor = "gasolinero";
    }
    void instalarRuedas() override {
        vehiculo->ruedas = 4;
    }
    void definirCapacidad() override {
        vehiculo->capacidadPasajeros = 5;
    }
    void definirCargaMax() override {
        vehiculo->cargaMax = 300;
    }
    unique_ptr<Vehiculo> obtenerVehiculo() {
        return move(vehiculo);
    }
};

class BuilderMoto : public BuilderVehiculo {
private:
    unique_ptr<Vehiculo> vehiculo;
public:
    BuilderMoto(){
        vehiculo = make_unique<Vehiculo>();
    }
    void definirTipo() override {
        vehiculo->tipo = "Moto";
    }
    void instalarMotor() override {
        vehiculo->motor = "gasolinero";
    }
    void instalarRuedas() override {
        vehiculo->ruedas = 2;
    }
    void definirCapacidad() override {
        vehiculo->capacidadPasajeros = 2;
    }
    void definirCargaMax() override {
        vehiculo->cargaMax = 50;
    }
    unique_ptr<Vehiculo> obtenerVehiculo() {
        return move(vehiculo);
    }
};

class BuilderCamion : public BuilderVehiculo {
private:
    unique_ptr<Vehiculo> vehiculo;
public:
    BuilderCamion(){
        vehiculo = make_unique<Vehiculo>();
    }
    void definirTipo() override {
        vehiculo->tipo = "Camion";
    }
    void instalarMotor() override {
        vehiculo->motor = "petrolero";
    }
    void instalarRuedas() override {
        vehiculo->ruedas = 8;
    }
    void definirCapacidad() override {
        vehiculo->capacidadPasajeros = 3;
    }
    void definirCargaMax() override {
        vehiculo->cargaMax = 5000;
    }
    unique_ptr<Vehiculo> obtenerVehiculo() {
        return move(vehiculo);
    }
};

class Director {
private:
    BuilderVehiculo* builder;
public:
    void setBuilder(BuilderVehiculo* nuevoBuilder){
        builder = nuevoBuilder;
    }

    unique_ptr<Vehiculo> construirVehiculo() {
        builder->definirTipo();
        builder->instalarMotor();
        builder->instalarRuedas();
        builder->definirCapacidad();
        builder->definirCargaMax();
        return builder->obtenerVehiculo();
    }
};

int main(){
    Director director;
    BuilderAutomovil builderAutomovil;
    director.setBuilder(&builderAutomovil);
    auto automovil = director.construirVehiculo();
    automovil->mostrarCaracteristas();

    BuilderMoto builderMoto;
    director.setBuilder(&builderMoto);
    auto moto = director.construirVehiculo();
    moto->mostrarCaracteristas();

}