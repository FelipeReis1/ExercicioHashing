#ifndef BALDE_H_INCLUDED
#define BALDE_H_INCLUDED

#include <string>
#include <vector>

class Balde {
    int profundidade, capacidade;
    std::vector<std::string> valores;
public:
    int getProfundidade() const;

public:
    Balde(int profundidade, int capacidade);
    bool inserir(std::string& elemento);
    bool buscar(std::string& elemento);
    bool remover(std::string bin);
    std::vector<std::string> copiar();
    void imprimir();

    int aumentarProfundidade();
    bool cheio();
};


#endif // BALDE_H_INCLUDED
