// Copyright [2015] <Leonardo Vailatti Eichstaedt>
#ifndef NO_AVL_HPP
#define NO_AVL_HPP
#include <vector>
#include <cstdio>

template <typename T>
class NoAVL {
 private:
    int height;  //!< Representa a altura do nó AVL
    T* dado;
    NoAVL<T>* esquerda;
    NoAVL<T>* direita;
    std::vector<NoAVL<T>* > elementos;

 public:
    explicit NoAVL(const T& info) : dado(new T(info)) {
      esquerda = NULL;
      direita = NULL;
      height = 0;
      elementos.clear();
    }
    virtual ~NoAVL() {
      if (esquerda != NULL)
        esquerda->~NoAVL();
      if (direita != NULL)
        direita->~NoAVL();
      delete dado;
    }
    int altura(NoAVL<T>* nodo) {
      if (nodo == NULL)
        return -1;
      else
        return nodo->getAltura();
    }
    int getAltura() {
      return height;
    }
    std::vector<NoAVL<T>* > getElementos() {
      return elementos;
    }
    NoAVL<T>* getEsquerda() {
      return esquerda;
    }
    NoAVL<T>* getDireita() {
      return direita;
    }
    int maX(int value1, int value2) {
	    return ((value1 > value2) ? value1 : value2);
    }
    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv) {
      NoAVL<T>* aux;
      if (dado < *arv->getDado()) {
        if (arv->getEsquerda() == NULL) {
          NoAVL<T>* novo = new NoAVL<T>(dado);
          if (novo == NULL)
            throw 20;
          arv->esquerda = novo;
        }
        else {
          aux = arv->inserir(dado, arv->getEsquerda());
          arv = verificarBalanceamento(arv, dado);
          if (arv->getDado() != aux->getDado()) {
            arv->esquerda = aux;
          }
        }
      }
      else {
        if (dado == *arv->getDado())
          throw 20;
        if (arv->getDireita() == NULL) {
          NoAVL<T>* novo = new NoAVL<T>(dado);
          if (novo == NULL)
            throw 20;
          arv->direita = novo;
        }
        else {
          aux = arv->inserir(dado, arv->getDireita());
          arv = verificarBalanceamento(arv, dado);
          if (arv->getDado() != aux->getDado()) {
            arv->direita = aux;
          }
        }
      }
      atualizarAltura(arv);
      return arv;
    }
    void atualizarAltura(NoAVL<T>* arv) {
      int m,n,d;
      m = altura(arv->getEsquerda());
      n = altura(arv->getDireita());
      d = maX(m,n);
      arv->height = d + 1;
    }
    NoAVL<T>* verificarBalanceamento(NoAVL<T>* arv, const T& dado) {
      if (dado < *arv->getDado()) {
        if (arv->altura(arv->getEsquerda()) - arv->altura(arv->getDireita()) == 2) {
          if (dado < *(arv->getEsquerda())->getDado()) {
            return simp_roda_esq(arv);
          }
          else {
            return dup_roda_esq(arv);
          }
        }
      }
      else {
        if (arv->altura(arv->getDireita()) - arv->altura(arv->getEsquerda()) == 2) {
          if (dado > *(arv->getDireita())->getDado()) {
            return simp_roda_dir(arv);
          }
          else {
            return dup_roda_dir(arv);
          }
        }
      }
      return arv;
    }
    NoAVL<T>* simp_roda_esq(NoAVL<T>* k2) {
      NoAVL<T>* k1;
      k1 = k2->getEsquerda();
      k2->esquerda = k1->getDireita();
      k1->direita = k2;

      k2->height = maX(altura(k2->getEsquerda()), altura(k2->getDireita())) + 1;
      k1->height = maX(altura(k1->getEsquerda()), k2->getAltura()) + 1;

      return k1;
    }
    NoAVL<T>* simp_roda_dir(NoAVL<T>* k2) {
      NoAVL<T>* k1;
      k1 = k2->getDireita();
      k2->direita = k1->getEsquerda();
      k1->esquerda = k2;

      k2->height = maX(altura(k2->getDireita()), altura(k2->getEsquerda()))+1;
	    k1->height = maX(altura(k1->getDireita()), k2->height)+1;

      return k1;
    }
    NoAVL<T>* dup_roda_esq(NoAVL<T>* k3) {
      k3->esquerda = simp_roda_dir(k3->getEsquerda());
      return (simp_roda_esq(k3));
    }
    NoAVL<T>* dup_roda_dir(NoAVL<T>* k3) {
      k3->direita = simp_roda_esq(k3->getDireita());
      return (simp_roda_dir(k3));
    }
    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado) {
      NoAVL<T> *aux, *filho;
      if (arv == NULL) {
        return arv;
      }
      else {
        if (dado < *arv->getDado()) {
          arv->esquerda = remover(arv->getEsquerda(), dado);
          arv = verificarBalanceamento(arv, *(maximo(arv))->getDado());
          atualizarAltura(arv);
          return arv;
        }
        else {
          if (dado > *arv->getDado()) {
            arv->direita = remover(arv->getDireita(), dado);
            arv->verificarBalanceamento(arv, *(minimo(arv))->getDado());
            atualizarAltura(arv);
            return arv;
          }
          else {
            if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
              aux = minimo(arv->getDireita());
              arv->dado = new T(*(aux->dado));
              arv->direita = remover(arv->getDireita(), *arv->getDado());
              arv = verificarBalanceamento(arv, *(minimo(arv))->getDado());
              atualizarAltura(arv);
              return arv;
            }
            else {
              if (arv->getDireita() != NULL) {
                filho = arv->getDireita();
                return filho;
              }
              else {
                if (arv->getEsquerda() != NULL) {
                  filho = arv->getEsquerda();
                  return filho;
                }
                else {
                  arv->~NoAVL();
                  return NULL;
                }
              }
            }
          }
        }
      }
    }
    NoAVL<T>* minimo(NoAVL<T>* nodo) {
    	while (nodo->getEsquerda() != NULL) {
	    	nodo = nodo->getEsquerda();
    	}
    	return nodo;
    }
    NoAVL<T>* maximo(NoAVL<T>* nodo) {
      while (nodo->getDireita() != NULL) {
	    	nodo = nodo->getDireita();
    	}
    	return nodo;
    }
    T* getDado() {
      return dado;
    }
    T* busca(const T& dado, NoAVL<T>* arv) {
      while (arv != NULL && *arv->getDado() != dado) {
	    	if (*arv->getDado() < dado)
	    		arv = arv->getDireita();
	    	else
	    		arv = arv->getEsquerda();
    	}
    	if (arv != NULL) {
    	    if (*arv->getDado() == dado)
    	        return arv->getDado();
    	}
    	throw 20;
    }
    void preOrdem(NoAVL<T>* nodo) {
      if (nodo != NULL) {
        elementos.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
      }
    }
    void emOrdem(NoAVL<T>* nodo) {
      if (nodo != NULL) {
        emOrdem(nodo->getEsquerda());
        elementos.push_back(nodo);
        emOrdem(nodo->getDireita());
      }
    }
    void posOrdem(NoAVL<T>* nodo) {
      if (nodo != NULL) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos.push_back(nodo);
      }
    }
};

#endif /* NO_AVL_HPP */
