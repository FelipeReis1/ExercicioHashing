#include <bitset>
#include <cmath>
#include <iostream>
#include <utility>
#include "Diretorio.h"

int numRegistros = 0;
int id = 0;

int Diretorio::hash(std::string bin) {
    int key = 0;
    for(int i = 0; i < profundidade_global; i++){
        int pos_valor = bin[i]-48;
        key += pos_valor*(int)std::pow(2,i);
    }
    return key;
}

Diretorio::Diretorio(int profundidade, int tamanho_balde) {
    this->profundidade_global = profundidade;
    this->tamanho_balde = tamanho_balde;

    for(int i = 0; i < 1<<profundidade_global; i++){
        baldes.push_back(new Balde(profundidade, tamanho_balde));
    }
}

void Diretorio::dividir(int id_balde, std::string pseudo_chave) {
    int profundidade_local = baldes[id_balde]->aumentarProfundidade();
    int indice_par = id_balde^(1<<(this->profundidade_global-1));

    baldes[indice_par] = new Balde(profundidade_local, tamanho_balde);

    std::vector<std::string> pseudo_chaves = baldes[id_balde]->copiar();

    for(auto& bin: pseudo_chaves){
        int id = hash(bin);

        if(id != id_balde){
            baldes[indice_par]->inserir(bin);
            baldes[id_balde]->remover(bin);
        }
    }

    inserir(pseudo_chave, true);
}

void Diretorio::duplicar(int id_balde, std::string pseudo_chave) {
    int old_size = std::pow(2, this->profundidade_global);

    for(int i = 0; i < old_size; i++){
        baldes.push_back(baldes[i]);
    }
    this->profundidade_global++;

    dividir(id_balde, pseudo_chave);
}

void Diretorio::inserir(std::string elemento, bool is_binary) {
    std::string pseudo_chave = (is_binary)?elemento:toBinary(std::move(elemento));
    int id_balde = hash(pseudo_chave);

    Balde* balde = baldes[id_balde];
    if(!balde->cheio()){
        balde->inserir(pseudo_chave);
        numRegistros++;
    }else if(balde->cheio() && balde->getProfundidade() < profundidade_global){
        dividir(id_balde, pseudo_chave);
    }else{
        duplicar(id_balde, pseudo_chave);
    }
}

bool Diretorio::buscar(std::string elemento) {
    std::string pseudo_chave = toBinary(std::move(elemento));
    int id_balde = hash(pseudo_chave);
    return baldes[id_balde]->buscar(pseudo_chave);
}

std::string Diretorio::toBinary(std::string str) {
    std::string binary;
    for (std::size_t i = 0; i < str.size(); ++i)
    {
        std::bitset<8> b(str.c_str()[i]);
        binary+= b.to_string();
    }
    return binary;
}

void Diretorio::imprimir() {

    for(auto balde: baldes){
        std::cout << "Balde " << id << std::endl;
        std::cout << "Profundidade balde: " << balde->getProfundidade() << std::endl;
        std::cout << std::endl;
        balde->imprimir();
        std::cout << std::endl;
        id++;
    }
}

void Diretorio::imprimeFatorCarga(){
    std::cout << "Fator de Carga: " << numRegistros << "/" << id * this->tamanho_balde << " = " << (double) numRegistros/ (double)(id*this->tamanho_balde);
}
