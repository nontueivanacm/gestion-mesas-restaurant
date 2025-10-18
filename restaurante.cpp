
#include "restaurante.h"
#include <fstream>

void Restaurante::cargarMesas() {
    mesas.clear();
    ifstream arch(archivoMesas, ios::binary);
    if (!arch) return;
    Mesa m;
    while (arch.read((char*)&m, sizeof(Mesa))) {
        mesas.push_back(m);
    }
    arch.close();
}

void Restaurante::guardarMesas() {
    ofstream arch(archivoMesas, ios::binary | ios::trunc);
    for (auto &m : mesas)
        arch.write((char*)&m, sizeof(Mesa));
    arch.close();
}

void Restaurante::mostrarMesas() {
    for (auto &m : mesas)
        m.mostrar();
}

void Restaurante::recibirCliente(string nombre) {
    for (auto &m : mesas) {
        if (m.estaLibre()) {
            cout << "Cliente " << nombre << " asignado a mesa #" << m.getNumero() << endl;
            m.ocupar();
            return;
        }
    }
    colaEspera.push(nombre);
    cout << "Todas las mesas están ocupadas. " << nombre << " entra en la cola de espera." << endl;
}

void Restaurante::liberarMesa(int numero, int ganancia) {
    for (auto &m : mesas) {
        if (m.getNumero() == numero && !m.estaLibre()) {
            m.liberar(ganancia);
            cout << "Mesa #" << numero << " liberada. Ganancia actual: $" << m.getGanancia() << endl;
            if (!colaEspera.empty()) {
                string prox = colaEspera.front();
                colaEspera.pop();
                cout << prox << " toma la mesa #" << numero << endl;
                m.ocupar();
            }
            return;
        }
    }
    cout << "Mesa no encontrada o ya libre." << endl;
}
