// Implementación de la clase Mesa
#include "mesa.h"

Mesa::Mesa(int n, bool l, int g) {
    numero = n;
    libre = l;
    ganancia = g;
}

void Mesa::mostrar() {
    cout << "Mesa #" << numero
         << " | Estado: " << (libre ? "Libre" : "Ocupada")
         << " | Ganancia: $" << ganancia << endl;
}

void Mesa::ocupar() {
    libre = false;
}

void Mesa::liberar(int gananciaNueva) {
    libre = true;
    ganancia += gananciaNueva;
}

int Mesa::getNumero() const { return numero; }
bool Mesa::estaLibre() const { return libre; }
int Mesa::getGanancia() const { return ganancia; }
void Mesa::setNumero(int n) { numero = n; }
void Mesa::setLibre(bool l) { libre = l; }
void Mesa::setGanancia(int g) { ganancia = g; }
