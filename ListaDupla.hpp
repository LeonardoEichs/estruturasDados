// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe Lista Duplamente Encadeada utilizando Templates
/*! Classe de implementação da estrutura de dados "Lista Duplamente Encadeada"
* \author Leonardo Vailatti Eichstaedt
* \since 13/04/2015
* \version 1.0
*/
#include  "ElementoDuplo.hpp"

template<typename T>
class ListaDupla {
 protected:
  ElementoDuplo<T>* head;  /// Ponteiro para primeiro elemento da lista
  int size;  /// Inteiro que armazena tamanho da lista

 public:
  // metodo construtor
	ListaDupla() {
    head = NULL;
    size = 0;
  }
  // metodo destrutor
	~ListaDupla() {
    destroiListaDuplo();
  }
  // adiciona elemento no inicio da lista
	void adicionaNoInicioDuplo(const T& dado) {
    ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, head, NULL);
    if (novo == NULL)
      throw 20;
    head = novo;
    if (novo->getProximo() != NULL)
      (novo->getProximo())->setAnterior(novo);
    size++;
  }
  // retira elemento do inicio da fila e retorna o valor contido
	T retiraDoInicioDuplo() {
    ElementoDuplo<T> *saiu;
    T volta;
    if (listaVazia())
      throw 20;
    saiu = head;
    volta = saiu->getInfo();
    head = saiu->getProximo();
    if (head != NULL)
      head->setAnterior(NULL);
    size--;
    delete saiu;
    return volta;
  }
  // elimina o elemento do inicio da lista
	void eliminaDoInicioDuplo() {
    ElementoDuplo<T> *saiu;
    if (listaVazia())
      throw 20;
    saiu = head;
    head = saiu->getProximo();
    if (head != NULL)
      head->setAnterior(NULL);
    size--;
    delete saiu;
  }
  // adiciona elemento na posicao passada pelo argumento
	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
    ElementoDuplo<T> *novo, *anterior;
    if (pos > size || pos < 0)
      throw 20;
    if (pos == 0) {
      adicionaNoInicioDuplo(dado);
      return;
    }
    novo = new ElementoDuplo<T>(dado, NULL, NULL);
    if (novo == NULL)
      throw 20;
    anterior = head;
    for (int i = 0; i < pos-1; i++)
      anterior = anterior->getProximo();
    novo->setProximo(anterior->getProximo());
    if (novo->getProximo() != NULL)
      novo->getProximo()->setAnterior(novo);
    anterior->setProximo(novo);
    novo->setAnterior(anterior);
    size++;
  }
  // retorna posicao do dado na lista
	int posicaoDuplo(const T& dado) const {
    ElementoDuplo<T> *auxiliar = head;
    for (int i = 0; i < size; i++) {
      if (auxiliar->getInfo() == dado)
        return i;
      auxiliar = auxiliar->getProximo();
    }
    throw 20;
  }
  // retorna posicao de memoria do elemento na lista
	T* posicaoMemDuplo(const T& dado) const {
    ElementoDuplo<T> *auxiliar;
    if (listaVazia())
      throw 20;
    auxiliar = head;
    for (int i = 0; i < size; i++) {
      if (auxiliar->getInfo() == dado)
       return &auxiliar->getInfo();
      auxiliar = auxiliar->getProximo();
    }
    throw 20;
  }
  // retorna true se o dado passado no argumento esta contido na lista
	bool contemDuplo(const T& dado) {
    ElementoDuplo<T> *auxiliar;
    if (listaVazia())
      throw 20;
    auxiliar = head;
    for (int i = 0; i < size; i++) {
      if (auxiliar->getInfo() == dado)
       return true;
      auxiliar = auxiliar->getProximo();
    }
    return false;
  }
  // retira elemento que ocupa a posicao equivalente ao argumento passado
	T retiraDaPosicaoDuplo(int pos) {
    ElementoDuplo<T> *anterior, *eliminar;
    T volta;
    if (pos >= size || pos < 0)
      throw 20;
    if (pos == 0)
      return retiraDoInicioDuplo();
    anterior = head;
    for (int i = 0; i < pos-1; i++)
      anterior = anterior->getProximo();
    eliminar = anterior->getProximo();
    volta = eliminar->getInfo();
    anterior->setProximo(eliminar->getProximo());
    if (eliminar->getProximo() != NULL)
      (eliminar->getProximo())->setAnterior(anterior);
    size--;
    delete eliminar;
    return volta;
  }
  // adiciona elemento no final da lista
	void adicionaDuplo(const T& dado) {
    adicionaNaPosicaoDuplo(dado, size);
  }
  // retira elemento no fim da fila
	T retiraDuplo() {
    if (listaVazia())
     throw 20;
    return retiraDaPosicaoDuplo(size - 1);
  }
  // retira da lista o elemento que conten dado passado no argumento
	T retiraEspecificoDuplo(const T& dado) {
    if (contemDuplo(dado)) {
      int pos = posicaoDuplo(dado);
      return retiraDaPosicaoDuplo(pos);
    }
    throw 20;
  }
  // mostra a informacao contida no elemento que ocupa posicao passada
  // como argumento
	T mostra(int pos) {
	if (pos >= size || pos < 0) {
	 throw 20;
	}
  if (pos == 0) {
    return head->getInfo();
  }
  ElementoDuplo<T> *auxiliar = head;
  for (int i = 0; i < pos; i++) {
    auxiliar = auxiliar->getProximo();
  }
  return auxiliar->getInfo();
  }
  // adiciona dado na posição definida pela comparação de grandeza
	void adicionaEmOrdem(const T& data) {
    int pos;
    if (listaVazia())
      adicionaNoInicioDuplo(data);
    ElementoDuplo<T> *atual;
    atual = head;
    pos = 0;
    while (atual->getProximo() != NULL && maior(data, atual->getInfo())) {
      atual = atual->getProximo();
      pos++;
    }
    if (maior(data, atual->getInfo()))
      adicionaDuplo(data);
    adicionaNaPosicaoDuplo(data, pos);
  }
  // retorna inteiro que corresponde a posicao do ultimo elemento da lista
	int verUltimo() {
    return size - 1;
  }
  // retorna true se a lista estiver vazia
	bool listaVazia() const {
    return head == NULL;
  }
  // retorna true se dados do argumento sao iguais
	bool igual(T dado1, T dado2) {
    return dado1 == dado2;
  }
  // retorna true se dado1 for maior que dado2
	bool maior(T dado1, T dado2) {
    return dado1 > dado2;
  }
  // retorna true se dado1 for menor que dado2
	bool menor(T dado1, T dado2) {
    return dado1 < dado2;
  }
  // metodo que destroi todos os elementos da lista
	void destroiListaDuplo() {
    ElementoDuplo<T> *atual;
     if (listaVazia()) {
       delete head;
     }
     atual = head;
     while (atual != NULL) {
       atual = atual->getProximo();
       eliminaDoInicioDuplo();
     }
  }
};
