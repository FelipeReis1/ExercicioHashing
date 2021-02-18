#include <iostream>
#include "Balde.h"

Balde::Balde(int profundidade, int capacidade) {
    this->profundidade = profundidade;
    this->capacidade = capacidade;
}

bool Balde::inserir(std::string& pseudo_chave) {
    if(this->cheio()) return false;

    if(buscar(pseudo_chave)){
        return true;
    }
    valores.push_back(pseudo_chave);
    return true;
}

bool Balde::buscar(std::string& pseudo_chave) {
    for(auto & valor : valores){
        if(valor == pseudo_chave) return true;
    }
    return false;
}

bool Balde::cheio() {
    return valores.size() == capacidade;
}

int Balde::getProfundidade() const {
    return profundidade;
}

int Balde::aumentarProfundidade() {
    profundidade++;
    return profundidade;
}

bool Balde::remover(std::string pseudo_chave) {
    auto it = valores.begin();
    for(; it != valores.end(); it++){
        if((*it) == pseudo_chave){
            break;
        }
    }
    if(it == valores.end()){
        return false;
    }
    valores.erase(it);

    return true;
}

std::vector<std::string> Balde::copiar(){
    return valores;
}

void Balde::imprimir() {
    for(const auto& chave: valores){
        std::cout << chave << std::endl;
    }
}
