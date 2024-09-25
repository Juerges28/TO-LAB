#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Producto{
private:
    string id;
    double precio;

public:
    Producto(string id, double precio) : id(id), precio(precio) {}

    string getId() const {
        return id;
    }
    double getPrecio() const {
        return precio;
    }
};

class Billetera{
private:
    double saldo;
    vector<Producto> carrito;
    int prodComprados;

public:
    Billetera(double saldo) : saldo(saldo), prodComprados(0) {}

    void agregarProducto(const Producto& producto){
        carrito.push_back(producto);
        cout << "Producto " << producto.getId() << " agregado al carrito." << endl;
    }
    void comprar(){
        double total = 0;
        for (const auto& producto : carrito) {
            total += producto.getPrecio();
        }
        if (total > saldo) {
            cout << "No hay suficiente dinero para hacer la compra." << endl;
        } else {
            saldo -= total;
            prodComprados += carrito.size();
            cout << "Compra realizada. Total: " << total << ". Saldo restante: " << saldo << endl;
            cout << "Cantidad de productos comprados: " << prodComprados << endl;
            vaciarCarrito();
        }
    }
    double verSaldo() const {
        return saldo;
    }
    void verCarrito() {
        cout << "Hay " << carrito.size() << " productos en el carrito." << endl;
        for (const auto& producto : carrito) {
            cout << "Producto Id: " << producto.getId() << ", precio: " << producto.getPrecio() << endl;
        }
    }
    void vaciarCarrito() {
        carrito.clear();
        cout << "Carrito Vacio." << endl;
    }
    int getProdComprados() const {
        return prodComprados;
    }
};

int main(){
    Billetera billetera(100.0); // Inicializa la billetera con un saldo de 100.0
    Producto producto1("001", 25.0);
    Producto producto2("002", 50.0);
    Producto producto3("003", 30.0);

    billetera.agregarProducto(producto1);
    billetera.agregarProducto(producto2);

    billetera.verCarrito(); // Ver los productos en el carrito
    cout << "Saldo actual: " << billetera.verSaldo() << endl;

    billetera.comprar(); // Compra los productos en el carrito

    cout << "Saldo después de la compra: " << billetera.verSaldo() << endl;
    cout << "Total de productos comprados hasta ahora: " << billetera.getProdComprados() << endl;

    billetera.agregarProducto(producto3);
    billetera.verCarrito(); // Ver los productos en el carrito

    billetera.comprar(); // Intenta comprar otro producto

    cout << "Total de productos comprados al final: " << billetera.getProdComprados() << endl;

    return 0;
}