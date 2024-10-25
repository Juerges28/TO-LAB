#include <iostream>
using namespace std;

class Mamifero{
    public:
        Mamifero() : edad() {cout << "Constructor Mamifero" << endl;}
        //Mamifero() { cout << "Constructor Mamifero" << endl; }
        ~Mamifero() { cout << "Destructor Mamifero" << endl; }
        void Move() const { cout << "Mamifero se mueve" << endl; }
        virtual void Speak() const { cout << "Mamifero habla" << endl; }
    protected:
        int edad;
};

class Dog : public Mamifero{
    public:
        Dog() { cout << "Constructor Dog" << endl; }
        ~Dog() { cout << "Destructor Dog" << endl; }
        void WagTail() { cout << "Dog wag tail" << endl; }
        void Speak() const { cout << "Guau" << endl; }
        void Move() const { cout << "Dog se mueve" << endl; }
};

int main(){
    Mamifero *a = new Dog;
    Dog *p = new Dog;
    a->Move();
    a->Speak();
    p->Move();
    p->WagTail();
    p->Speak();
    delete a;
    delete p;
};