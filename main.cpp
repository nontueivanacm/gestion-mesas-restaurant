// Código principal del TP
#include <iostream>
#include "restaurante.h"
using namespace std;

int main() {
    Restaurante r;
    r.cargarMesas();

    int opcion;
    do {
        cout << "\n=== GESTION DE MESAS ===\n";
        cout << "1. Mostrar mesas\n";
        cout << "2. Recibir cliente\n";
        cout << "3. Liberar mesa\n";
        cout << "4. Guardar y salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            r.mostrarMesas();
        } else if (opcion == 2) {
            string nombre;
            cout << "Nombre del cliente: ";
            cin >> nombre;
            r.recibirCliente(nombre);
        } else if (opcion == 3) {
            int num, gan;
            cout << "Número de mesa a liberar: ";
            cin >> num;
            cout << "Ganancia obtenida: $";
            cin >> gan;
            r.liberarMesa(num, gan);
        } else if (opcion == 4) {
            r.guardarMesas();
            cout << "Datos guardados. ¡Hasta luego!\n";
        }
    } while (opcion != 4);

    return 0;
}
