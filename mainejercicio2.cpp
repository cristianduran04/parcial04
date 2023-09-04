#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class ListaCircular {
private:
    Nodo* primero;

public:
    ListaCircular() {
        primero = nullptr;
    }

    void agregar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!primero) {
            primero = nuevo;
            primero->siguiente = primero;
        } else {
            Nodo* actual = primero;
            while (actual->siguiente != primero) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
            nuevo->siguiente = primero;
        }
    }

    void actualizar(int valorViejo, int valorNuevo) {
        Nodo* actual = primero;
        bool encontrado = false;
        if (actual) {
            do {
                if (actual->dato == valorViejo) {
                    actual->dato = valorNuevo;
                    encontrado = true;
                }
                actual = actual->siguiente;
            } while (actual != primero);
        }
        if (encontrado) {
            std::cout << "Elemento actualizado: " << valorViejo << " -> " << valorNuevo << std::endl;
        } else {
            std::cout << "Elemento no encontrado: " << valorViejo << std::endl;
        }
    }

    void mostrar() {
        Nodo* actual = primero;
        if (actual) {
            do {
                std::cout << actual->dato << " -> ";
                actual = actual->siguiente;
            } while (actual != primero);
        } else {
            std::cout << "La lista está vacía" << std::endl;
        }
    }
};

int main() {
    ListaCircular lista;

    while (true) {
        std::cout << "\n1. Agregar elemento" << std::endl;
        std::cout << "2. Actualizar elemento" << std::endl;
        std::cout << "3. Mostrar lista" << std::endl;
        std::cout << "4. Salir" << std::endl;

        int opcion;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            int elemento;
            std::cout << "Ingrese un elemento: ";
            std::cin >> elemento;
            lista.agregar(elemento);
        } else if (opcion == 2) {
            int valorViejo, valorNuevo;
            std::cout << "Ingrese el valor viejo: ";
            std::cin >> valorViejo;
            std::cout << "Ingrese el valor nuevo: ";
            std::cin >> valorNuevo;
            lista.actualizar(valorViejo, valorNuevo);
        } else if (opcion == 3) {
            std::cout << "\nLista Circular:" << std::endl;
            lista.mostrar();
        } else if (opcion == 4) {
            break;
        } else {
            std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}

