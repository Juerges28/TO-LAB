#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

enum class AccountType {
    AHORRO,
    JOVEN,
    PLUSS,
    EMPRESARIAL,
    TARJETA_CREDITO
};

class Cuenta {
protected:
    string numeroCuenta;
    double saldo;
    AccountType tipo;

public:
    Cuenta(const string& numero, double saldoInicial, AccountType tipoCuenta)
        : numeroCuenta(numero), saldo(saldoInicial), tipo(tipoCuenta) {}

    virtual ~Cuenta() {}

    virtual double calcularInteres() const = 0;

    string getNumeroCuenta() const { return numeroCuenta; }
    double getSaldo() const { return saldo; }
    AccountType getTipo() const { return tipo; }

    void depositar(double monto) { saldo += monto; }
    bool retirar(double monto) {
        if (monto > saldo) return false;
        saldo -= monto;
        return true;
    }
};

class CuentaAhorro : public Cuenta {
public:
    CuentaAhorro(const string& numero, double saldoInicial)
        : Cuenta(numero, saldoInicial, AccountType::AHORRO) {}

    double calcularInteres() const override {
        return saldo * 0.005; // 0.5%
    }
};

class CuentaJoven : public Cuenta {
public:
    CuentaJoven(const string& numero, double saldoInicial)
        : Cuenta(numero, saldoInicial, AccountType::JOVEN) {}

    double calcularInteres() const override {
        return saldo * 0.01; // 1%
    }
};

class CuentaPlus : public Cuenta {
public:
    CuentaPlus(const string& numero, double saldoInicial)
        : Cuenta(numero, saldoInicial, AccountType::PLUSS) {}

    double calcularInteres() const override {
        return saldo * 0.02; // 2%
    }
};

class CuentaEmpresarial : public Cuenta {
public:
    CuentaEmpresarial(const string& numero, double saldoInicial)
        : Cuenta(numero, saldoInicial, AccountType::EMPRESARIAL) {}

    double calcularInteres() const override {
        return saldo * 0.015; // 1.5%
    }
};

class TarjetaCredito : public Cuenta {
public:
    TarjetaCredito(const string& numero, double saldoInicial)
        : Cuenta(numero, saldoInicial, AccountType::TARJETA_CREDITO) {}

    double calcularInteres() const override {
        return saldo * 0.20; // 20%
    }
};

class RepositorioCuentas {
private:
    static unique_ptr<RepositorioCuentas> instancia;
    unordered_map<string, vector<shared_ptr<Cuenta>>> clientesCuentas;

    RepositorioCuentas() {}

public:
    RepositorioCuentas(const RepositorioCuentas&) = delete;
    RepositorioCuentas& operator=(const RepositorioCuentas&) = delete;

    static RepositorioCuentas* getInstancia() {
        if (!instancia) {
            instancia.reset(new RepositorioCuentas());
        }
        return instancia.get();
    }

    void agregarCuenta(const string& clienteID, shared_ptr<Cuenta> cuenta) {
        clientesCuentas[clienteID].push_back(cuenta);
    }

    vector<shared_ptr<Cuenta>> obtenerCuentas(const string& clienteID) {
        if (clientesCuentas.find(clienteID) != clientesCuentas.end()) {
            return clientesCuentas[clienteID];
        }
        return {};
    }
};

unique_ptr<RepositorioCuentas> RepositorioCuentas::instancia = nullptr;

class OperacionFinanciera {
public:
    virtual ~OperacionFinanciera() {}
    virtual void ejecutar() = 0;
};

class PrestamoPersonal : public OperacionFinanciera {
private:
    double monto;
    double tasaInteres;

public:
    PrestamoPersonal(double montoPrestamo, double tasa)
        : monto(montoPrestamo), tasaInteres(tasa) {}

    void ejecutar() override {
        cout << "Ejecutando préstamo personal de " << monto
                  << " con tasa de interés del " << tasaInteres << "%" << endl;
    }
};

class TransferenciaNacional : public OperacionFinanciera {
private:
    double monto;
    double tasaTransferencia;

public:
    TransferenciaNacional(double montoTransferencia, double tasa)
        : monto(montoTransferencia), tasaTransferencia(tasa) {}

    void ejecutar() override {
        cout << "Ejecutando transferencia nacional de " << monto
                  << " con tasa del " << tasaTransferencia << "%" << endl;
    }
};

class CompraTarjetaCredito : public OperacionFinanciera {
private:
    double monto;
    double tasaInteres;

public:
    CompraTarjetaCredito(double montoCompra, double tasa)
        : monto(montoCompra), tasaInteres(tasa) {}

    void ejecutar() override {
        cout << "Ejecutando compra con tarjeta de crédito de " << monto
                  << " con tasa de interés del " << tasaInteres << "%" << endl;
    }
};

class Cliente {
private:
    string clienteID;
    RepositorioCuentas* repositorio;

public:
    Cliente(const string& id) : clienteID(id) {
        repositorio = RepositorioCuentas::getInstancia();
    }

    void agregarCuenta(shared_ptr<Cuenta> cuenta) {
        repositorio->agregarCuenta(clienteID, cuenta);
    }

    void mostrarCuentas() {
        auto cuentas = repositorio->obtenerCuentas(clienteID);
        cout << "Cuentas del cliente " << clienteID << ":" << endl;
        for (const auto& cuenta : cuentas) {
            cout << "- " << cuenta->getNumeroCuenta() << " | Tipo: ";
            switch (cuenta->getTipo()) {
                case AccountType::AHORRO: cout << "Ahorro"; break;
                case AccountType::JOVEN: cout << "Joven"; break;
                case AccountType::PLUSS: cout << "Plus"; break;
                case AccountType::EMPRESARIAL: cout << "Empresarial"; break;
                case AccountType::TARJETA_CREDITO: cout << "Tarjeta de Crédito"; break;
            }
            cout << " | Saldo: " << cuenta->getSaldo() << endl;
        }
    }
};

int main() {
    Cliente cliente1("C001");
    Cliente cliente2("C002");

    auto cuentaAhorro = make_shared<CuentaAhorro>("A001", 1000.0);
    auto tarjetaCredito = make_shared<TarjetaCredito>("TC001", 500.0);
    cliente1.agregarCuenta(cuentaAhorro);
    cliente1.agregarCuenta(tarjetaCredito);

    auto cuentaJoven = make_shared<CuentaJoven>("J001", 1500.0);
    cliente2.agregarCuenta(cuentaJoven);

    cliente1.mostrarCuentas();
    cliente2.mostrarCuentas();

    PrestamoPersonal prestamo(2000.0, 9.0);
    TransferenciaNacional transferencia(300.0, 2.0);
    CompraTarjetaCredito compra(150.0, 18.0);

    prestamo.ejecutar();
    transferencia.ejecutar();
    compra.ejecutar();

    return 0;
}
