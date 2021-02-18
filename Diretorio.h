#ifndef DIRETORIO_H_INCLUDED
#define DIRETORIO_H_INCLUDED

#include <vector>
#include <string>
#include "Balde.h"

class Diretorio {
    int profundidade_global = 0, tamanho_balde = 0;
    std::vector<Balde*> baldes;

    int hash(std::string bin);

public:
    Diretorio(int profundidade, int tamanho_balde);
    void dividir(int id_balde, std::string pseudo_chave);
    void duplicar(int id_balde, std::string pseudo_chave);
    void inserir(std::string elemento, bool is_binary=false);
    bool buscar(std::string elemento);
    std::string toBinary(std::string str);
    void imprimeFatorCarga();

    void imprimir();

};

#endif // DIRETORIO_H_INCLUDED
