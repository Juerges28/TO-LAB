#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

std::mutex listMutex;

struct Node {
    int value;
    std::shared_ptr<Node> next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto newNode = std::make_shared<Node>(value);
        newNode->next = head;
        head = newNode;
        std::cout << "Insertando: " << value << std::endl;
    }

    bool remove(int value) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto current = head;
        std::shared_ptr<Node> previous = nullptr;
        while (current) {
            if (current->value == value) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                std::cout << "Eliminando: " << value << std::endl;
                return true;
            }
            previous = current;
            current = current->next;
        }
        std::cout << "No se eliminó: " << value << std::endl;
        return false;
    }

    bool find(int value) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto current = head;
        while (current) {
            if (current->value == value) {
                std::cout << "Buscado: " << value << std::endl;
                return true;
            }
            current = current->next;
        }
        std::cout << "No encontrado: " << value << std::endl;
        return false;
    }

    bool modify(int oldValue, int increment) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto current = head;
        while (current) {
            if (current->value == oldValue) {
                int newValue = oldValue + increment;
                std::cout << "Modificando " << oldValue << " a " << newValue << std::endl;
                current->value = newValue;
                return true;
            }
            current = current->next;
        }
        std::cout << "No se encontró " << oldValue << std::endl;
        return false;
    }

private:
    std::shared_ptr<Node> head;
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
    std::thread t1(threadRemove, std::ref(list));
    std::thread t2(threadInsert, std::ref(list));
    std::thread t3(threadFind, std::ref(list));
    std::thread t4(threadModify, std::ref(list));

    // Esperar a que los hilos terminen
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
