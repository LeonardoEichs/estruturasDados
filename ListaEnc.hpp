// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe Lista Encadeada utilizando Templates
/*! Classe de implementação da estrutura de dados "Lista Encadeada Simples"
* \author Leonardo Vailatti Eichstaedt
* \since 03/04/2015
* \version 1.0
*/
#include  "Elemento.hpp"

template<typename T>
class ListaEnc {
 public:
    // Método construtor
    ListaEnc() {
     size = 0;
     head = NULL;
    }
    // Destrutor
    ~ListaEnc() {
     destroiLista();
    }
    // Inicio
    // Método que adiciona elemento no início da Lista
    void adicionaNoInicio(const T& dado) {
     Elemento<T> *novo = new Elemento<T>(dado, head);
     if (novo == NULL)
      throw 20;
     head = novo;
     size++;
    }
    // Método que retira elemento da Lista
    T retiraDoInicio() {
     Elemento<T> *saiu;
     if (listaVazia())
      throw 20;
     saiu = head;
     T volta = saiu->getInfo();
     head = saiu->getProximo();
     size--;
     delete saiu;
     return volta;
    }
    // Elimina o primeiro elemento da Lista e sua respectiva informação
    void eliminaDoInicio() {
     Elemento<T> *saiu;
     if (listaVazia())
      throw 20;
     saiu = head;
     head = saiu->getProximo();
     size--;
     // delete saiu->getInfo();
     delete saiu;
    }
    // Posicao
    // Adiciona elemento na posicao especificada no parâmetro
    void adicionaNaPosicao(const T& dado, int pos) {
     Elemento<T> *anterior;
     if (pos > size || pos < 0)
      throw 20;
     if (pos == 0) {
      adicionaNoInicio(dado);
      return;
     }
     Elemento<T> *novo = new Elemento<T>(dado, NULL);
     if (novo == NULL)
      throw 20;
     anterior = head;
     for (int i = 0; i < pos - 1; i++)
      anterior = anterior->getProximo();
     novo->setProximo(anterior->getProximo());
     anterior->setProximo(novo);
     size++;
    }
    // Retorna a posicao do dado fornecido como paramêtro
    int posicao(const T& dado) const {
     Elemento<T> *auxiliar = head;
     for (int i = 0; i < size; i++) {
       if (auxiliar->getInfo() == dado)
         return i;
       auxiliar = auxiliar->getProximo();
     }
     throw 20;
    }
    // Retorna o valor de memoria da posicao do dado fornecido como paramêtro
    T* posicaoMem(const T& dado) const {
     Elemento<T> *auxiliar = head;
     for (int i = 0; i < size; i++) {
       if (auxiliar->getInfo() == dado)
        return &auxiliar->getInfo();
       auxiliar = auxiliar->getProximo();
     }
     throw 20;
    }
    // Retorna booleano true caso o dado procurado esteja na lista
    bool contem(const T& dado) {
      Elemento<T> *auxiliar = head;
      for (int i = 0; i < size; i++) {
        if (auxiliar->getInfo() == dado)
         return true;
        auxiliar = auxiliar->getProximo();
      }
      return false;
    }
    // Retira da lista o elemento que ocupa a posicao passada como paramêtro
    T retiraDaPosicao(int pos) {
     Elemento<T> *anterior, *eliminar;
     T volta;
     if (pos >= size)
      throw 20;
     if (pos == 0)
      return retiraDoInicio();
     anterior = head;
     for (int i = 0; i < pos - 1; i++)
      anterior = anterior->getProximo();
     eliminar = anterior->getProximo();
     volta = eliminar->getInfo();
     anterior->setProximo(eliminar->getProximo());
     size--;
     delete eliminar;
     return volta;
    }
    // Adiciona dado no fim da lista
    void adiciona(const T& dado) {
     adicionaNaPosicao(dado, size);
    }
    // Retira elemento do fim da lista
    T retira() {
     if (listaVazia())
      throw 20;
     return retiraDaPosicao(size - 1);
    }
    // Especifico
    // Retira da lista dado especificado no paramêtro
    T retiraEspecifico(const T& dado) {
     Elemento<T> *atual, *anterior;
     atual = head;
     anterior = head;
     for (int i =0; i < size - 1; i++) {
       if (atual->getInfo() == dado) {
         T volta = atual->getInfo();
         anterior->setProximo(atual->getProximo());
         delete atual;
         return volta;
       }
       anterior = atual;
       atual = atual->getProximo();
     }
     throw 20;
    }
    // Adiciona dado na posição definida pela comparação de grandeza
    void adicionaEmOrdem(const T& data) {
     Elemento<T> *atual;
     int pos = 0;
     if (listaVazia())
      return adicionaNoInicio(data);
     atual = head;
     while (atual->getProximo() != NULL && maior(data, atual->getInfo())) {
       atual = atual->getProximo();
       pos++;
     }
     if (maior(data, atual->getInfo()))
      adicionaNaPosicao(data, pos + 1);
     adicionaNaPosicao(data, pos);
    }
    // Retorna booleano true caso a lista esteja vazia
    bool listaVazia() {
     return size == 0;
    }
    // Retorna true se dados do argumento são iguais
    bool igual(T dado1, T dado2) {
     return dado1 == dado2;
    }
    // Retorna true se dado1 for maior que dado2
    bool maior(T dado1, T dado2) {
     return dado1 > dado2;
    }
    // Retorna true se dado1 for menor que dado2
    bool menor(T dado1, T dado2) {
     return dado1 < dado2;
    }
    // Método para destruir lista
    void destroiLista() {
     Elemento<T> *atual;
      if (listaVazia()) {
        delete head;
        return;
      }
      atual = head;
      while (atual != NULL) {
        atual = atual->getProximo();
        eliminaDoInicio();
      }
    }

 protected:
     Elemento<T>* head;  /// Ponteiro para primeiro elemento da Lista Encadeada
     int size;  /// Inteiro que armazeno o tamanho da Lista Encadeada
};
