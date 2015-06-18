// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe Lista Circular utilizando Templates
/*! Classe de implementação da estrutura de dados "Lista Circular Simples"
* \author Leonardo Vailatti Eichstaedt
* \since 19/04/2015
* \version 1.0
*/

#ifndef LISTACIRC_HPP
#define LISTACIRC_HPP

#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>
class ListaCirc : private ListaEnc<T> {
 private:
    Elemento<T> *sentinela;

 public:
  // metodo construtor
	ListaCirc<T>() {
    sentinela = NULL;
    sentinela = new Elemento<T>(0, sentinela);
    ListaEnc<T>::head = sentinela;
    ListaEnc<T>::size = 1;
  }
  // destrutor
	~ListaCirc() {
    destroiLista();
  }
  // metodo adiciona elemento no inicio
	void adicionaNoInicio(const T& dado) {
    ListaEnc<T>::adicionaNaPosicao(dado, 1);
  }
  // metodo retira elemento do inicio
	T retiraDoInicio() {
    return ListaEnc<T>::retiraDaPosicao(1);
  }
  // metodo elimina elemento do inicio
	void eliminaDoInicio() {
    ListaEnc<T>::retiraDaPosicao(1);
  }
  // metodo adiciona elemento na posicao passada como argumento
	void adicionaNaPosicao(const T& dado, int pos) {
    ListaEnc<T>::adicionaNaPosicao(dado, pos + 1);
  }
  // metodo retorna posicao do elemento que contem dado passado como argumento
	int posicao(const T& dado) const {
    Elemento<T> *auxiliar = ListaEnc<T>::head;
    for (int i = 0; i < ListaEnc<T>::size - 1; i++) {
      auxiliar = auxiliar->getProximo();
      if (auxiliar->getInfo() == dado)
        return i;
    }
    throw 20;
  }
  // metodo retorna posicao de memoria do elemento que contem dado
	T* posicaoMem(const T& dado) const {
    Elemento<T> *auxiliar = ListaEnc<T>::head;
    for (int i = 0; i < ListaEnc<T>::size - 1; i++) {
      auxiliar = auxiliar->getProximo();
      if (auxiliar->getInfo() == dado)
        return &auxiliar->getInfo();
    }
    throw 20;
  }
  // retorna true se lista contem elemento com dado passado como parametro
	bool contem(const T& dado) {
    Elemento<T> *auxiliar = ListaEnc<T>::head;
    for (int i = 0; i < ListaEnc<T>::size - 1; i++) {
      auxiliar = auxiliar->getProximo();
      if (auxiliar->getInfo() == dado)
       return true;
    }
    return false;
  }
  // retira elemento que ocupa posicao passada como argumento
	T retiraDaPosicao(int pos) {
    return ListaEnc<T>::retiraDaPosicao(pos + 1);
  }
  // adiciona elemento no final da lista
	void adiciona(const T& dado) {
    ListaEnc<T>::adicionaNaPosicao(dado, ListaEnc<T>::size);
  }
  // retira elemento do final da lista
	T retira() {
    if (listaVazia())
      throw 20;
    return ListaEnc<T>::retiraDaPosicao(ListaEnc<T>::size - 1);
  }
  // retira elemento que contem dado passado como argumento
	T retiraEspecifico(const T& dado) {
    return ListaEnc<T>::retiraEspecifico(dado);
  }
  // mostra dado contido no elemento que ocupa posicao especificada
	T mostra(int pos) {
    Elemento<T> *atual;
    T* dado;
    pos++;
    if (pos <= 0 || pos >= ListaEnc<T>::size)
      throw(20);
    atual = ListaEnc<T>::head;
    for (int i = 0; i < pos; i++) {
      atual = atual->getProximo();
    }
    dado = atual->getInfo();
    return dado;
  }
  // adiciona elemento baseado em ordem
	void adicionaEmOrdem(const T& data) {
    if (listaVazia())
		  adicionaNoInicio(data);
	Elemento<T>* auxiliar;
	int pos;
	auxiliar = ListaEnc<T>::head;
	pos = 1;
	auxiliar = auxiliar->getProximo();
	while (auxiliar->getProximo() != ListaEnc<T>::head
           && maior(data, auxiliar->getInfo())) {
     auxiliar = auxiliar->getProximo();
		pos++;
	}
	if (maior(data, auxiliar->getInfo()))
		adiciona(data);
	adicionaNaPosicao(data, pos);
  }
  // retorna ultima posicao da lista
	int verUltimo() {
    return ListaEnc<T>::size - 1;
  }
  // retorna true se lista estiver vazia
	bool listaVazia() const {
    return ListaEnc<T>::size <= 1;
  }
  // retorna true se dado1 == dado2
	bool igual(T dado1, T dado2) {
    return ListaEnc<T>::igual(dado1, dado2);
  }
  // retorna true se dado1 > dado2
	bool maior(T dado1, T dado2) {
    return ListaEnc<T>::maior(dado1, dado2);
  }
  // retorna true se dado1 < dado2
	bool menor(T dado1, T dado2) {
    return ListaEnc<T>::menor(dado1, dado2);
  }
  // metodo destroi lista
	void destroiLista() {
    ListaEnc<T>::destroiLista();
  }
};

#endif
