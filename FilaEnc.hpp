// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe Fila Encadeada utilizando Templates
/*! Classe de implementação da estrutura de dados "Fila Encadeada"
* \author Leonardo Vailatti Eichstaedt
* \since 11/04/2015
* \version 1.0
*/
#ifndef FILAENC_HPP
#define FILAENC_HPP

#include  "Elemento.hpp"
#include  "ListaEnc.hpp"

template <typename T>
class FilaEnc: private ListaEnc<T>{
 private:
  Elemento<T>* fim;  /// Ponteiro para ultimo elemento da Fila Encadeada

 public:
  // Método construtor
	FilaEnc<T>(): ListaEnc<T>() {
    fim = NULL;
  }
  // Método destruidor
	~FilaEnc() {
    limparFila();
  }
  // Adiciona elemento no fim da fila
	void inclui(const T& dado) {
    Elemento<T> *novo = new Elemento<T>(dado, NULL);
    if (novo == NULL)
      throw 20;
    if (filaVazia())
      ListaEnc<T>::head = novo;
    else
      fim->setProximo(novo);
    fim = novo;
    ListaEnc<T>::size++;
  }
  // Retira elemento do inicio da fila
	T retira() {
    if (filaVazia())
      throw 20;
    if (ListaEnc<T>::size == 1)
      fim = NULL;
    return ListaEnc<T>::retiraDoInicio();
  }
  // Retorna informacao contida no ultimo elemento da fila
	T ultimo() {
    if (filaVazia())
     throw 20;
    T volta = fim->getInfo();
    return volta;
  }
  // Retorna informacao contida no primeiro elemento da fila
	T primeiro() {
    if (filaVazia())
     throw 20;
    T volta = ListaEnc<T>::head->getInfo();
    return volta;
  }
  // Retorna true se a fila estiver vazia
	bool filaVazia() {
    return ListaEnc<T>::listaVazia();
  }
  // Deleta todos elementos contidoos na fila
	void limparFila() {
    ListaEnc<T>::destroiLista();
  }
};

#endif
