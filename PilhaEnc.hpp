// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe Pilha Encadeada utilizando Templates
/*! Classe de implementação da estrutura de dados "Pilha Encadeada"
* \author Leonardo Vailatti Eichstaedt
* \since 11/04/2015
* \version 1.0
*/
#ifndef PILHAENC_HPP
#define PILHAENC_HPP

#include  "Elemento.hpp"
#include "ListaEnc.hpp"
template<typename T>
class PilhaEnc: private ListaEnc<T>{
 public:
    // Método construtor
    PilhaEnc(): ListaEnc<T>() {
    }
    // Método destruidor
    ~PilhaEnc() {
      limparPilha();
    }
    // Adiciona elemento no início(topo) da pilha
    void empilha(const T& dado) {
      ListaEnc<T>::adicionaNoInicio(dado);
    }
    // Retira elemento do início(topo) da pilha
    T desempilha() {
      if (PilhaVazia())
       throw 20;
      return ListaEnc<T>::retiraDoInicio();
    }
    // Retorna a informação contida no elemento no topo da pilha
	 T topo() {
	  if (PilhaVazia()) {
        throw(20);
      }
      T volta = ListaEnc<T>::head->getInfo();
      return volta;
    }
    // Método que apaga todos elementos da pilha
	void limparPilha() {
        ListaEnc<T>::destroiLista();
    }
    // Retorna true se pilha estiver vazia
	bool PilhaVazia() {
	  return ListaEnc<T>::listaVazia();
    }
};

#endif
