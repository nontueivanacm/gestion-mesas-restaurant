// Declaración de la clase Restaurante
#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <vector>
#include <queue>
#include "mesa.h"
using namespace std;

class Restaurante {
private:
    vector<Mesa> mesas;
    queue<string> colaEspera;
    string archivoMesas = "mesas.dat";

public:
    void cargarMesas();
    void guardarMesas();
    void mostrarMesas();
    void recibirCliente(string nombre);
    void liberarMesa(int numero, int ganancia);
};

#endif
