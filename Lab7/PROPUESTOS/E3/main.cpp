#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Automovil {
public:
    vector<string> componentes;

    void MostrarComponentes() const {
        cout << "Componentes del Automóvil:" << endl;
        for (const auto& componente : componentes) {
            cout << "- " << componente << endl;
        }
    }
};

class IBuilder {
public:
    virtual ~IBuilder() {}
    virtual void ConstruirPuertas(const string& color) = 0;
    virtual void ConstruirLlantas(const string& tipo) = 0;
    virtual void ConstruirMotor(const string& potencia) = 0;
    virtual void ConstruirAsientos(const string& material) = 0;
    virtual void ConstruirEspejos(const string& tipo) = 0;
    virtual unique_ptr<Automovil> ObtenerAutomovil() = 0;
};

class AutomovilBuilder : public IBuilder {
private:
    unique_ptr<Automovil> automovil;

public:
    AutomovilBuilder() {
        Reset();
    }

    void Reset() {
        automovil = make_unique<Automovil>();
    }

    void ConstruirPuertas(const string& color) override {
        automovil->componentes.push_back("Puertas de color " + color);
    }

    void ConstruirLlantas(const string& tipo) override {
        automovil->componentes.push_back("Llantas tipo " + tipo);
    }

    void ConstruirMotor(const string& potencia) override {
        automovil->componentes.push_back("Motor de " + potencia);
    }

    void ConstruirAsientos(const string& material) override {
        automovil->componentes.push_back("Asientos de " + material);
    }

    void ConstruirEspejos(const string& tipo) override {
        automovil->componentes.push_back("Espejos tipo " + tipo);
    }

    unique_ptr<Automovil> ObtenerAutomovil() override {
        unique_ptr<Automovil> resultado = move(automovil);
        Reset();
        return resultado;
    }
};

class Director {
private:
    IBuilder* builder;

public:
    void SetBuilder(IBuilder* builder) {
        this->builder = builder;
    }

    void ConstruirAutomovilBasico() {
        builder->ConstruirPuertas("blanco");
        builder->ConstruirLlantas("estándar");
        builder->ConstruirMotor("1.6L");
    }

    void ConstruirAutomovilDeLujo() {
        builder->ConstruirPuertas("negro brillante");
        builder->ConstruirLlantas("deportivo");
        builder->ConstruirMotor("V8");
        builder->ConstruirAsientos("cuero premium");
        builder->ConstruirEspejos("eléctricos con calefacción");
    }
};

void ClienteCode(Director& director) {
    AutomovilBuilder builderEspecifico;
    director.SetBuilder(&builderEspecifico);

    cout << "Construcción de un Automóvil Básico:\n";
    director.ConstruirAutomovilBasico();
    unique_ptr<Automovil> autoBasico = builderEspecifico.ObtenerAutomovil();
    autoBasico->MostrarComponentes();

    cout << "\nConstrucción de un Automóvil de Lujo:\n";
    director.ConstruirAutomovilDeLujo();
    unique_ptr<Automovil> autoLujo = builderEspecifico.ObtenerAutomovil();
    autoLujo->MostrarComponentes();

    cout << "\nConstrucción de un Automóvil Personalizado:\n";
    builderEspecifico.ConstruirPuertas("rojo");
    builderEspecifico.ConstruirLlantas("todo terreno");
    builderEspecifico.ConstruirMotor("V6");
    builderEspecifico.ConstruirAsientos("tela estándar");
    unique_ptr<Automovil> autoPersonalizado = builderEspecifico.ObtenerAutomovil();
    autoPersonalizado->MostrarComponentes();
}

int main() {
    Director director;
    ClienteCode(director);
    return 0;
}
