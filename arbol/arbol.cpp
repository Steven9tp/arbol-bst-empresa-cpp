#include <iostream>
#include <string>

using namespace std;

// Función max manual (sin usar algorithm)
int maxManual(int a, int b) {
    return (a > b) ? a : b;
}

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;
    
    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBST {
private:
    Nodo* raiz;
    
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }
        
        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } 
        else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } 
        else {
            cout << "El codigo ya existe.\n";
        }
        return nodo;
    }
    
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }
    
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }
    
    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }
    
    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }
    
    int altura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        int alturaIzq = altura(nodo->izquierdo);
        int alturaDer = altura(nodo->derecho);
        return 1 + maxManual(alturaIzq, alturaDer);
    }
    
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }
    
    void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl;
    }
    
public:
    ArbolBST() {
        raiz = nullptr;
    }
    
    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
        cout << "Empleado insertado con exito.\n";
    }
    
    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);
        if (resultado != nullptr) {
            cout << "\nEmpleado encontrado:\n";
            mostrarEmpleado(resultado);
        } else {
            cout << "\nEmpleado no encontrado.\n";
        }
    }
    
    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\nRaiz del arbol:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "El arbol esta vacio.\n";
        }
    }
    
    void mostrarInorden() {
        cout << "\nRecorrido Inorden:\n";
        inorden(raiz);
    }
    
    void mostrarPreorden() {
        cout << "\nRecorrido Preorden:\n";
        preorden(raiz);
    }
    
    void mostrarPostorden() {
        cout << "\nRecorrido Postorden:\n";
        postorden(raiz);
    }
    
    void mostrarAltura() {
        cout << "\nAltura del arbol: " << altura(raiz) << endl;
    }
    
    void mostrarNodosHoja() {
        cout << "\nNodos hoja:\n";
        mostrarHojas(raiz);
    }
    
    bool estaVacio() {
        return raiz == nullptr;
    }
};

int main() {
    ArbolBST arbol;
    int opcion;
    
    cout << "========================================\n";
    cout << "   ARBOL BST - ORGANIGRAMA EMPRESARIAL\n";
    cout << "========================================\n";
    
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Insertar empleado\n";
        cout << "2. Buscar empleado por codigo\n";
        cout << "3. Mostrar raiz\n";
        cout << "4. Recorrido inorden\n";
        cout << "5. Recorrido preorden\n";
        cout << "6. Recorrido postorden\n";
        cout << "7. Mostrar altura del arbol\n";
        cout << "8. Mostrar nodos hoja\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                Empleado emp;
                cout << "\n--- INSERTAR EMPLEADO ---\n";
                cout << "Codigo: ";
                cin >> emp.codigo;
                cin.ignore();
                cout << "Nombre: ";
                getline(cin, emp.nombre);
                cout << "Cargo: ";
                getline(cin, emp.cargo);
                arbol.insertarEmpleado(emp);
                break;
            }
            case 2: {
                int codigo;
                cout << "\n--- BUSCAR EMPLEADO ---\n";
                cout << "Ingrese codigo: ";
                cin >> codigo;
                arbol.buscarEmpleado(codigo);
                break;
            }
            case 3:
                arbol.mostrarRaiz();
                break;
            case 4:
                arbol.mostrarInorden();
                break;
            case 5:
                arbol.mostrarPreorden();
                break;
            case 6:
                arbol.mostrarPostorden();
                break;
            case 7:
                arbol.mostrarAltura();
                break;
            case 8:
                arbol.mostrarNodosHoja();
                break;
            case 0:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente de nuevo.\n";
        }
    } while(opcion != 0);
    
    return 0;
}