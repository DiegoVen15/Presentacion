#include <iostream>
using namespace std;

class nodo {

    public:
        nodo(int v, nodo* sig = NULL) {
            valor = v;
            siguiente = sig;
        }

        int valor;
        nodo* siguiente;

        friend class pila;
};

typedef nodo* pnodo;

class stack {

    public:
        stack() : ultimo(NULL) {}
        ~stack();

        void Push(int v);
        int Pop();

    private:
        pnodo ultimo;
};

stack::~stack() {
    while (ultimo)
        Pop();
}

void stack::Push(int v) {
    pnodo nuevo;

    nuevo = new nodo(v, ultimo);
    ultimo = nuevo;
}

int stack::Pop() {

    pnodo nodo; 
    int v;      

    if (!ultimo) return 0; 
    nodo = ultimo;
    ultimo = nodo->siguiente;
    v = nodo->valor;
    delete nodo;
    return v;
}

int main() {

    stack St;

    St.Push(20);
    cout << "Push(20)" << endl;
    St.Push(10);
    cout << "Push(10)" << endl;
    cout << "Pop() = " << St.Pop() << endl;
    St.Push(40);
    cout << "Push(40)" << endl;
    St.Push(30);
    cout << "Push(30)" << endl;
    cout << "Pop() = " << St.Pop() << endl;
    cout << "Pop() = " << St.Pop() << endl;
    St.Push(90);
    cout << "Push(90)" << endl;
    cout << "Pop() = " << St.Pop() << endl;
    cout << "Pop() = " << St.Pop() << endl;

    return 0;
}