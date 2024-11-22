#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

mutex listMutex;

struct Node {
    int value;
    shared_ptr<Node> next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        lock_guard<mutex> lock(listMutex);
        auto newNode = make_shared<Node>(value);
        newNode->next = head;
        head = newNode;
        cout << "Insertando: " << value << endl;
    }

    bool remove(int value) {
        lock_guard<mutex> lock(listMutex);
        auto current = head;
        shared_ptr<Node> previous = nullptr;
        while (current) {
            if (current->value == value) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                cout << "Eliminando: " << value << endl;
                return true;
            }
            previous = current;
            current = current->next;
        }
        cout << "No se eliminó: " << value << endl;
        return false;
    }

    bool find(int value) {
        lock_guard<mutex> lock(listMutex);
        auto current = head;
        while (current) {
            if (current->value == value) {
                cout << "Buscado: " << value << endl;
                return true;
            }
            current = current->next;
        }
        cout << "No encontrado: " << value << endl;
        return false;
    }

    bool modify(int oldValue, int increment) {
        lock_guard<mutex> lock(listMutex);
        auto current = head;
        while (current) {
            if (current->value == oldValue) {
                int newValue = oldValue + increment;
                cout << "Modificando " << oldValue << " a " << newValue << endl;
                current->value = newValue;
                return true;
            }
            current = current->next;
        }
        cout << "No se encontró " << oldValue << endl;
        return false;
    }

private:
    shared_ptr<Node> head;
};

// Función para realizar eliminaciones aleatorias
void threadRemove(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        list.remove(num);
    }
}

// Función para realizar inserciones aleatorias
void threadInsert(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        list.insert(num);
    }
}

// Función para realizar búsquedas aleatorias
void threadFind(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        list.find(num);
    }
}

// Función para realizar modificaciones aleatorias
void threadModify(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int oldValue = rand() % 100;
        int increment = rand() % 10 + 1;
        list.modify(oldValue, increment);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    LinkedList list;

    // Crear y lanzar hilos
    thread t1(threadRemove, ref(list));
    thread t2(threadInsert, ref(list));
    thread t3(threadFind, ref(list));
    thread t4(threadModify, ref(list));

    // Esperar a que los hilos terminen
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
