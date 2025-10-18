// Declaración de la clase Mesa
#ifndef MESA_H
#define MESA_H

#include <iostream>
using namespace std;

class Mesa {
private:
    int numero;
    bool libre;
    int ganancia;

public:
    Mesa(int n = 0, bool l = true, int g = 0);
    void mostrar();
    void ocupar();
    void liberar(int gananciaNueva);
    int getNumero() const;
    bool estaLibre() const;
    int getGanancia() const;
    void setNumero(int n);
    void setLibre(bool l);
    void setGanancia(int g);
};

#endif
