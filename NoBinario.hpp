// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe NoBinario utilizando Templates
/*! Classe de implementação da estrutura de dados "Árvore Binária"
* \author Leonardo Vailatti Eichstaedt
* \since 17/04/2015
* \version 1.0
*/

#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

template <typename T>
class NoBinario {
 protected:
    T* dado;  /// Dado contido no nó
    NoBinario<T>* esquerda;  /// Nó da esquerda
    NoBinario<T>* direita;  /// Nó da direita
    std::vector<NoBinario<T>* > elementos;  //!< Elementos acessados durante
                                            // o percurso realizado

 public:
    // Método construtor
    NoBinario<T>(const T& info) : dado(new T(info)) {
		  esquerda = NULL;
		  direita = NULL;
		  elementos.clear();
	  }
    // Método destrutor
    virtual ~NoBinario() {
      if (esquerda != NULL)
        esquerda->~NoBinario();
      if (direita != NULL)
        direita->~NoBinario();
      delete dado;
    }
    // Método que retorna dado
    T* getDado() {
      return dado;
    }
    // Método que retorna vetor "elementos"
    std::vector< NoBinario<T>* > getElementos() {
      return elementos;
    }
    // Método que retorna nó da esquerda
    NoBinario<T>* getEsquerda() {
      return esquerda;
    }
    // Método que retorna nó da direita
    NoBinario<T>* getDireita() {
      return direita;
    }
    // Método que busca dado passado no parâmetro
    T* busca(const T& dado, NoBinario<T>* arv) {
      while (arv != NULL) {
        if (*arv->getDado() != dado) {
          if (*arv->getDado() < dado)
            arv = arv->getDireita();
          else
            arv = arv->getEsquerda();
        } else {
        return arv->getDado();
        }
      }
      throw 20;
    }
    // Método que insere um novo nó na árvore
    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
     if (dado < *arv->getDado()) {
       if (arv->getEsquerda() == NULL) {
         arv->esquerda = new NoBinario<T>(dado);
         return arv->getEsquerda();
       } else {
         inserir(dado, arv->getEsquerda());
       }
     } else {
       if (arv->getDireita() == NULL) {
         arv->direita = new NoBinario<T>(dado);
         return arv->getDireita();
       } else {
         inserir(dado, arv->getDireita());
       }
     }
     return NULL;
    }
    // Método que remove da árvore o dado passado como parâmetro
    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado) {
      NoBinario<T> *tmp, *filho;
      if (arv == NULL) {
        return arv;
      } else {
          if (dado < *arv->getDado()) {
            arv->esquerda = remover(arv->getEsquerda(), dado);
            return arv;
          } else {
            if (dado > *arv->getDado()) {
              arv->direita = remover(arv->getDireita(), dado);
              return arv;
            } else {
              if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
                tmp = minimo(arv->getDireita());
                arv->dado = tmp->getDado();
                arv->direita = remover(arv->getDireita(), *arv->getDado());
                return arv;
              } else {
                tmp = arv;
                if (arv->getDireita() != NULL) {
                  filho = arv->getDireita();
                  return filho;
                } else {
                  if (arv->getEsquerda() != NULL) {
                    filho = arv->getEsquerda();
                    return filho;
                  } else {
                    delete arv;
                    return NULL;
                  }
                }
              }
            }
          }
      }
    }
    // Método que retorna menor valor da árvore
    NoBinario<T>* minimo(NoBinario<T>* nodo) {
      while (nodo->getEsquerda() != NULL) {
        nodo = nodo->getEsquerda();
      }
      return nodo;
    }
    // Método de percorrimento que visita a raíz antes das subárvores
    void preOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        elementos.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
      }
    }
    // Visita primeiro a subárvore esquerda, a raíz e depois a subárvore direita
    void emOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        emOrdem(nodo->getEsquerda());
        elementos.push_back(nodo);
        emOrdem(nodo->getDireita());
      }
    }
    // Método de percorrimento que visita a raíz depois das subárvores
    void posOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos.push_back(nodo);
      }
    }
};

#endif /* NO_BINARIO_HPP */
