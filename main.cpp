#include <iostream>
#include <random>


#include "Diretorio.h"

int main() {

    int tamanhoBalde;

   std::vector<std::string> insercao = {
            "zt78cyh6j2k25mk",
            "xgbjkup31cju35f",
            "affrqmme1uyd10n",
            "p0pi45zfl014tj7",
            "mngo8yw0mmu88oj",
            "pg2ryoqvk1ewq79",
            "3vlfcskwk7fjn3j",
            "0ivrmz084mu0d4w",
            "5w8qa6cjrgmcwh1",
            "04rysij756u66ti",
            "xa1t26asd91c5sk",
            "rv5a215bkwtmfms",
            "quro2m7zw2g5la",
            "kwh8sjd9r9bfxrm",
            "ubpu2vzmsn5e29e",
            "72omvzwp5hpvhkq"
    };

     std::vector<std::string> insercao2 = {
            "aaaacyh6j2k25mk",
            "aaaakup31cju35f",
            "aaaaqmme1uyd10n",
            "aaaa45zfl014tj7",
            "aaaa8yw0mmu88oj",
            "aaaayoqvk1ewq79",
            "aaaacskwk7fjn3j",
            "aaaamz084mu0d4w",
            "aaaaa6cjrgmcwh1",
            "aaaasij756u66ti",
            "aaaa26asd91c5sk",
            "aaaa215bkwtmfms",
            "aaaa2m7zw2g5lan",
            "aaaasjd9r9bfxrm",
            "aaaa2vzmsn5e29e",
            "aaaavzwp5hpvhkq"
    };






    std::cout << "Digite o tamanho do balde" << std::endl;
    std::cin >> tamanhoBalde;
    tamanhoBalde = tamanhoBalde;
    Diretorio dir(0, tamanhoBalde);


    for(auto str: insercao){
        std::cout << str << std::endl;
        dir.inserir(str);
    }



   dir.imprimir();
   dir.imprimeFatorCarga();

}


