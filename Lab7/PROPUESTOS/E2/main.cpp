#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory> 
#include <functional>

using namespace std;

class CuentaBase {
protected:
    string titular;
    double saldo;

public:
    CuentaBase(const string& titular, double saldoInicial)
        : titular(titular), saldo(saldoInicial) {}

    virtual ~CuentaBase() {}

    virtual string ObtenerTipoCuenta() const = 0;

    virtual double CalcularInteres() const = 0;

    virtual void ConsultarEstadoCuenta() const {
        cout << "Titular: " << titular << "\n"
             << "Saldo: " << saldo << "\n"
             << "Tipo de Cuenta: " << ObtenerTipoCuenta() << endl;
    }

    virtual void Operar(double monto) {
        saldo += monto;
        cout << "Operación realizada. Nuevo saldo: " << saldo << endl;
    }
};

class CuentaAhorro : public CuentaBase {
public:
    CuentaAhorro(const string& titular, double saldoInicial)
        : CuentaBase(titular, saldoInicial) {}

    string ObtenerTipoCuenta() const override {
        return "Ahorro";
    }

    double CalcularInteres() const override {
        return saldo * 0.0045;
    }
};

class CuentaJoven : public CuentaBase {
public:
    CuentaJoven(const string& titular, double saldoInicial)
        : CuentaBase(titular, saldoInicial) {}

    string ObtenerTipoCuenta() const override {
        return "Joven";
    }

    double CalcularInteres() const override {
        return saldo * 0.015;
    }
};

class CuentaPluss : public CuentaBase {
public:
    CuentaPluss(const string& titular, double saldoInicial)
        : CuentaBase(titular, saldoInicial) {}

    string ObtenerTipoCuenta() const override {
        return "Pluss";
    }

    double CalcularInteres() const override {
        return saldo * 0.0075; 
    }
};

class TarjetaCredito : public CuentaBase {
public:
    TarjetaCredito(const string& titular, double saldoInicial)
        : CuentaBase(titular, saldoInicial) {}

    string ObtenerTipoCuenta() const override {
        return "Tarjeta de Crédito";
    }

    double CalcularInteres() const override {
        return saldo * 0.20; 
    }
};

class Cliente {
private:
    string nombre;
    vector<unique_ptr<CuentaBase>> cuentas;

public:
    Cliente(const string& nombre) : nombre(nombre) {}

    void AgregarCuenta(unique_ptr<CuentaBase> cuenta) {
        cuentas.push_back(move(cuenta));
    }

    void ConsultarEstadoGlobal() const {
        cout << "Estado de cuentas para: " << nombre << endl;
        for (const auto& cuenta : cuentas) {
            cuenta->ConsultarEstadoCuenta();
            cout << "Interés calculado: " << cuenta->CalcularInteres() << "\n"
                 << "--------------------------------------" << endl;
        }
    }

    void ConsultarEstadoPorTipo(const string& tipo) const {
        cout << "Estado de cuentas tipo: " << tipo << " para " << nombre << endl;
        for (const auto& cuenta : cuentas) {
            if (cuenta->ObtenerTipoCuenta() == tipo) {
                cuenta->ConsultarEstadoCuenta();
                cout << "Interés calculado: " << cuenta->CalcularInteres() << "\n"
                     << "--------------------------------------" << endl;
            }
        }
    }

    void LiquidarCuenta(const string& tipo) {
        for (auto& cuenta : cuentas) {
            if (cuenta->ObtenerTipoCuenta() == tipo) {
                cuenta->Operar(-cuenta->CalcularInteres());
                cout << "Cuenta de tipo " << tipo << " liquidada.\n";
                return;
            }
        }
        cout << "No se encontró cuenta del tipo " << tipo << endl;
    }
};

int main() {
    Cliente cliente1("Juan Perez");

    cliente1.AgregarCuenta(make_unique<CuentaAhorro>("Juan Perez", 5000.0));
    cliente1.AgregarCuenta(make_unique<CuentaJoven>("Juan Perez", 1500.0));
    cliente1.AgregarCuenta(make_unique<CuentaPluss>("Juan Perez", 8000.0));
    cliente1.AgregarCuenta(make_unique<TarjetaCredito>("Juan Perez", -2000.0));

    cout << "Consultar estado global:\n";
    cliente1.ConsultarEstadoGlobal();

    cout << "\nConsultar estado por tipo (Ahorro):\n";
    cliente1.ConsultarEstadoPorTipo("Ahorro");

    cout << "\nLiquidar cuenta tipo Joven:\n";
    cliente1.LiquidarCuenta("Joven");

    cout << "\nEstado global después de liquidar:\n";
    cliente1.ConsultarEstadoGlobal();

    return 0;
}
