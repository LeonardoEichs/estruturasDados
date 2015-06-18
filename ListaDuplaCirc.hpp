// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe Lista Duplamente Circular utilizando Templates
/*! Classe de implementação da estrutura de dados "Lista Duplamente Circular"
* \author Leonardo Vailatti Eichstaedt
* \since 19/04/2015
* \version 1.0
*/

#ifndef LISTADUPLACIRC_HPP
#define LISTADUPLACIRC_HPP

#include "ElementoDuplo.hpp"
#include "ListaDupla.hpp"

template <typename T>

class ListaDuplaCirc : private ListaDupla<T> {
 private:
    ElementoDuplo<T> *sentinela;  /// nodo sentinela

 public:
  // metodo construtor
	ListaDuplaCirc() {
	 sentinela = NULL;
    sentinela = new ElementoDuplo<T>(0, sentinela, sentinela);
    ListaDupla<T>::head = sentinela;
	 ListaDupla<T>::size = 1;
	}

  // destrutor
	~ListaDuplaCirc() {
	  destroiListaDuplo();
	}

  // metodo adiciona um elemento no inicio
	void adicionaNoInicioDuplo(const T& dado) {
	  ListaDupla<T>::adicionaNaPosicaoDuplo(dado, 1);
	}

  // metodo retira elemento do inicio
	T retiraDoInicioDuplo() {
	  return ListaDupla<T>::retiraDaPosicaoDuplo(1);
	}

  // metodo elimina elemento do inicio
	void eliminaDoInicioDuplo() {
	  ListaDupla<T>::retiraDaPosicaoDuplo(1);
	}

  // metodo adiciona um elemento na posicao passada como argumento
	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
	  ListaDupla<T>::adicionaNaPosicaoDuplo(dado, pos + 1);
	}

  // metodo retorna a posicao de um elemento que possui o dado procurado
	int posicaoDuplo(const T& dado) const {
	  ElementoDuplo<T>* auxiliar;
		auxiliar = ListaDupla<T>::head;
		for (int i = 0; i < ListaDupla<T>::size - 1; i++) {
			auxiliar = auxiliar->getProximo();
			if (auxiliar->getInfo() == dado)
				return i;
		}
		throw(20);
	}

  // metodo retorna posicao de memoria de um dado procurado
	T* posicaoMemDuplo(const T& dado) const {
    ElementoDuplo<T>* auxiliar;
    auxiliar = ListaDupla<T>::head;
    for (int i = 0; i < ListaDupla<T>::size - 1; i++) {
      auxiliar = auxiliar->getProximo();
      if (auxiliar->getInfo() == dado)
        return &auxiliar->getInfo();
    }
    throw(20);
	}

  // retorna true se a lista contem dado procurado
	bool contemDuplo(const T& dado) {
	    ElementoDuplo<T> *auxiliar;
      auxiliar = ListaDupla<T>::head;
      for (int i = 0; i < ListaDupla<T>::size - 1; i++) {
        auxiliar = auxiliar->getProximo();
      if (auxiliar->getInfo() == dado)
        return true;
      }
      return false;
	}

  // metodo retira elemento que ocupa posicao passada como argumento
	T retiraDaPosicaoDuplo(int pos) {
	    return ListaDupla<T>::retiraDaPosicaoDuplo(pos + 1);
	}

  // adiciona elemento no fim da lista
	void adicionaDuplo(const T& dado) {
	    ListaDupla<T>::adicionaNaPosicaoDuplo(dado, ListaDupla<T>::size);
	}

  // retira elemento que ocupa o fim da lista
	T retiraDuplo() {
	    if (listaVazia())
	      throw(20);
	    return ListaDupla<T>::retiraDaPosicaoDuplo(ListaDupla<T>::size-1);
	}

  // retira o elemento que contem o dado passado como argumento
	T retiraEspecificoDuplo(const T& dado) {
	    return ListaDupla<T>::retiraEspecificoDuplo(dado);
	}

  // mostra o dado que ocupa a posicao passada como argumento
	T mostra(int pos) {
	    ElementoDuplo<T> *atual;
	    T* dado;
	    pos++;
	    if (pos <= 0 || pos >= ListaDupla<T>::size)
	        throw(20);
	    atual = ListaDupla<T>::head;
	    for (int i = 0; i < pos; i++) {
	        atual = atual->getProximo();
	    }
	    dado = atual->getInfo();
	    return dado;
	}

  // metodo adiciona elemento baseado em uma ordem
	void adicionaEmOrdem(const T& data) {
	  if (listaVazia())
		  adicionaNoInicioDuplo(data);
		ElementoDuplo<T>* auxiliar;
		int pos;
		auxiliar = ListaDupla<T>::head;
		pos = 1;
		auxiliar = auxiliar->getProximo();
		while (auxiliar->getProximo() != ListaDupla<T>::head
           && maior(data, auxiliar->getInfo())) {
      auxiliar = auxiliar->getProximo();
			pos++;
		}
		if (maior(data, auxiliar->getInfo()))
			adicionaDuplo(data);
		adicionaNaPosicaoDuplo(data, pos);
	}

  // retorna posicao do ultimo elemento
	int verUltimo() {
	  return ListaDupla<T>::size-1;
	}

  // retorna true se lista estiver vazia
	bool listaVazia() const {
	  return ListaDupla<T>::size <= 1;
	}

  // retorna true se dado1 == dado2
	bool igual(T dado1, T dado2) {
	  return ListaDupla<T>::igual(dado1, dado2);
	}

	// retorna true se dado1 > dado2
	bool maior(T dado1, T dado2) {
	  return ListaDupla<T>::maior(dado1, dado2);
	}

  // retorna true se dado1 < dado2
	bool menor(T dado1, T dado2) {
	  return ListaDupla<T>::menor(dado1, dado2);
	}

  // metodo destroi lista
	void destroiListaDuplo() {
	  ListaDupla<T>::destroiListaDuplo();
	}
};

#endif
