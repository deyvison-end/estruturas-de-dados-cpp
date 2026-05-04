#ifndef PRATICA_06_CPF_H
#define PRATICA_06_CPF_H

#include <iostream>

using namespace std;

struct CPF {
    string valor;
    CPF(const char * s) : valor(s) {
        if (valor.empty()) throw runtime_error("CPF vazio!");
    }
    bool operator== (const CPF& cpf) const {
        return valor == cpf.valor;
    }
    
     string str() const {
        return valor;
    }
};

inline ostream &operator<< (ostream &out, const CPF& cpf) {
    return out << cpf.valor;
}
#endif //PRATICA_06_CPF_H
