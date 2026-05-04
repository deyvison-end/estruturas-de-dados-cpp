#ifndef PRATICA_06_FULL_HASHTABLE_H
#define PRATICA_06_FULL_HASHTABLE_H

#include <vector>
#include "hashtable.h"
#include "linkedlist.h"

using namespace std;

/* Tabela de Espalhamento como vector de listas encadeadas.
 * As listas lidam com colisoes  */
template<class T_key, class T_value>
class full_hashtable : hashtable <T_key, T_value> {
private:
	vector<linkedlist<pair<T_key, T_value>>> table;

	T_value not_found;

public:
	explicit full_hashtable(int cap, T_value not_found) : hashtable<T_key, T_value>(cap), table(cap), not_found(not_found) {
	}

	~full_hashtable() override = default;

	// Se um valor com essa chave jC! existir, substituir
	void insert(T_key key, T_value value) override {
		int idx = this->get_idx(key);

		// TODO; use a funC'C#o search_list(idx, key) abaixo
		int pos = search_list(idx, key);
		if (pos != -1) {
			// chave jC! existe b substituir valor
			auto it = table[idx].begin();
			for (int i = 0; i < pos; i++)
				++it;

			(*it).second = value;
		} else {
			// chave nova b inserir no inC-cio da lista
			table[idx].add(make_pair(key, value));
			this->size++;
		}
	}

	void remove(T_key key) override {
		int idx = this->get_idx(key);

		int pos = search_list(idx, key);
		if (pos != -1) {
			table[idx].remove(pos);   // remove pelo C-ndice
			this->size--;
		}
	}
	// TODO; use a funC'C#o search_list(idx, key) abaixo

	T_value search(T_key key) override {
		int idx = this->get_idx(key);

		// TODO; use a funC'C#o search_list(idx, key) abaixo
		int pos = search_list(idx, key);
		if (pos != -1) {
			auto it = table[idx].begin();
			for (int i = 0; i < pos; i++)
				++it;

			return (*it).second;
		}

		return not_found;
	}

	void show() override {
		int i = 0;
		for (auto &list : table) {
			cout << i++ << ": ";
			for (auto &[key, value] : list)
				cout << "(" << key << ": " << value << ") ";
			cout << endl;
		}
	}

	virtual T_value operator [] (const T_key &key) {
		return search(key);
	}

private:
	int search_list(int idx, T_key key) {
		int i = 0;
		for (auto &[k, _] : table[idx]) {
			if (k == key) return i;
			i++;
		}
		return -1;
	}
};

#endif //PRATICA_06_FULL_HASHTABLE_H
