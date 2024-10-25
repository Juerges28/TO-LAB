#include <iostream>
#include <string>
using namespace std;

class infante{
private:
    string nombre;
public:
    infante(const string &nom){
        nombre = nom;
    }
    void gatear(){
        cout << nombre << " esta gateando" << endl;
    }
};

class joven{
private:
    string nombre;
public:
    joven(const string &nom){
        nombre = nom;
    }
    void correr(){
        cout << nombre << " esta corriendo" << endl;
    }
};

class adulto : public infante, public joven{
private:
    string nombre;
public:
    adulto(const string &nom) : infante(nom), joven(nom), nombre(nom) {}
    void caminar(){
        cout << nombre << " esta caminando" << endl;
    }
};

int main(){
    adulto a("Juan");
    joven j("Pedro");
    infante i("Maria");
    a.caminar();
    a.correr();
    a.gatear();
    j.correr();
    i.gatear();
};