#include <iostream>

// --- ESTRUCTURAS DE DATOS MANUALES ---

// Nodo para la Lista de Adyacencia Dinámica
struct NodoArista {
    int destino;
    NodoArista* siguiente;
};

// Nodo para la cola FIFO (BFS) y pila LIFO (DFS iterativo si se requiere)
struct NodoLista {
    int valor;
    NodoLista* siguiente;
};

class ColaManual {
private:
    NodoLista* frente;
    NodoLista* fin;
public:
    ColaManual() : frente(nullptr), fin(nullptr) {}
    ~ColaManual() {
        while (!vacia()) desencolar();
    }
    bool vacia() { return frente == nullptr; }
    void encolar(int v) {
        NodoLista* nuevo = new NodoLista{v, nullptr};
        if (vacia()) {
            frente = fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }
    int desencolar() {
        if (vacia()) return -1;
        NodoLista* temp = frente;
        int val = temp->valor;
        frente = frente->siguiente;
        if (frente == nullptr) fin = nullptr;
        delete temp;
        return val;
    }
};

// --- CLASE GRAFO ---
class GrafoManual {
private:
    int numVertices;
    NodoArista** listaAdyacencia;

    void insertarOrdenado(int origen, int destino) {
        NodoArista* nuevo = new NodoArista{destino, nullptr};
        if (listaAdyacencia[origen] == nullptr || listaAdyacencia[origen]->destino > destino) {
            nuevo->siguiente = listaAdyacencia[origen];
            listaAdyacencia[origen] = nuevo;
        } else {
            NodoArista* actual = listaAdyacencia[origen];
            while (actual->siguiente != nullptr && actual->siguiente->destino < destino) {
                actual = actual->siguiente;
            }
            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
        }
    }

    void dfsRecursivo(int nodo, bool* visitados) {
        visitados[nodo] = true;
        std::cout << nodo << " ";

        NodoArista* temp = listaAdyacencia[nodo];
        while (temp != nullptr) {
            if (!visitados[temp->destino]) {
                dfsRecursivo(temp->destino, visitados);
            }
            temp = temp->siguiente;
        }
    }

public:
    GrafoManual(int vertices) {
        numVertices = vertices + 1; // Para indexación basada en 1
        listaAdyacencia = new NodoArista*[numVertices];
        for (int i = 0; i < numVertices; i++) listaAdyacencia[i] = nullptr;
    }

    ~GrafoManual() {
        for (int i = 0; i < numVertices; i++) {
            NodoArista* actual = listaAdyacencia[i];
            while (actual != nullptr) {
                NodoArista* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        }
        delete[] listaAdyacencia;
    }

    void agregarArista(int u, int v) {
        insertarOrdenado(u, v);
        insertarOrdenado(v, u); // No dirigido
    }

    void imprimirListaAdyacencia() {
        for (int i = 1; i < numVertices; i++) {
            std::cout << "Nodo " << i << ": [";
            NodoArista* temp = listaAdyacencia[i];
            while (temp != nullptr) {
                std::cout << temp->destino;
                if (temp->siguiente != nullptr) std::cout << ",";
                temp = temp->siguiente;
            }
            std::cout << "]\n";
        }
    }

    void ejecutarBFS(int inicio) {
        bool* visitados = new bool[numVertices]{false};
        ColaManual cola;

        visitados[inicio] = true;
        cola.encolar(inicio);

        std::cout << "BFS: ";
        while (!cola.vacia()) {
            int actual = cola.desencolar();
            std::cout << actual << " ";

            NodoArista* temp = listaAdyacencia[actual];
            while (temp != nullptr) {
                if (!visitados[temp->destino]) {
                    visitados[temp->destino] = true;
                    cola.encolar(temp->destino);
                }
                temp = temp->siguiente;
            }
        }
        std::cout << "\n";
        delete[] visitados;
    }

    void ejecutarDFS(int inicio) {
        bool* visitados = new bool[numVertices]{false};
        std::cout << "DFS: ";
        dfsRecursivo(inicio, visitados);
        std::cout << "\n";
        delete[] visitados;
    }
};

int main() {
    std::cout << "=== EJECUCION GRAFO: EJERCICIO 16 (C++ PURO) ===\n\n";

    GrafoManual g(9);
    g.agregarArista(1, 2);
    g.agregarArista(1, 3);
    g.agregarArista(2, 4);
    g.agregarArista(2, 5);
    g.agregarArista(3, 6);
    g.agregarArista(5, 7);
    g.agregarArista(6, 7);
    g.agregarArista(7, 8);
    g.agregarArista(8, 9);

    std::cout << "--- LISTA DE ADYACENCIA ---\n";
    g.imprimirListaAdyacencia();
    std::cout << "\n";

    g.ejecutarBFS(1);
    g.ejecutarDFS(1);

    return 0;
}