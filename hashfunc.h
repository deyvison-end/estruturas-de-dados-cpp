#ifndef PRATICA_06_MISC_H
#define PRATICA_06_MISC_H

#include <iostream>
#include "cpf.h"

using namespace std;

/* Funcao de espalhamento abstrata
 * Deve sempre retornar valor positivo! */
template <class T>
long hash_function(const T &v);
    
// Calcula o hash para chaves do tipo int
template <>
inline long hash_function<int>(const int &v) {
    // TODO
     long hash = static_cast<long>(v);
    if (hash < 0) {
        hash = -hash;
    }
    hash = hash * 31;
    if (hash <= 0) {
        hash = 1;
    }
    return hash;
}

// Calcula o hash para chaves do tipo string
template <>
inline long hash_function<string>(const string &v) {
    // TODO
    long hash = 31;
    for (size_t i = 0; i < v.length(); i++) {
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(v[i]);
    }
    if (hash <= 0) {
        hash = 1;
    }
    return hash;
}

template <>
inline long hash_function<CPF>(const CPF &CPF) {
    // TODO
   string s = CPF.str();
    long hash = 0;
    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            hash = hash * 31 + (c - '0');
        }
    }
    //hash = hash * 2654435761L;
    if (hash <= 0) {
        hash = 1;
    }
    return hash;
}
#endif //PRATICA_06_MISC_H