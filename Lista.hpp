// Copyright [2015] <Leonardo Vailatti Eichstaedt>

//! Classe Lista utilizando Templates
/*! Classe de implementação da estrutura de dados "Lista" usando Templates
* \author Leonardo Vailatti Eichstaedt
* \since 24/03/2015
* \version 1.0
*/

template<typename T>
class Lista {
 private:
    T *dados;  /// Array que armazena dados
    int ultimo;  /// Inteiro que armazena posição do ultimo elemento da Lista
    int tamanho;  /// Inteiro que armazena o tamanho da Lista
    int pos;  /// Inteiro usado para percorrer a Lista
    T auxiliar;  /// Variável usada para armazenar valores para retorno

 public:
  // Método construtor padrão
	Lista() {
  }
  // Construtor com paramêtro "tam" representando tamanho da Lista
	explicit Lista<T>(int tam) {
    dados = new T[tam];
    ultimo = -1;
    tamanho = tam;
  }
  // Adiciona dado no final da Lista
	void adiciona(T dado) {
    if (listaCheia())
      throw 20;
    dados[++ultimo] = dado;
  }
  // Adiciona dado no início da Lista
	void adicionaNoInicio(T dado) {
    if (listaCheia())
      throw 20;
    ultimo++;
    pos = ultimo;
    while (pos > 0) {
      dados[pos] = dados[pos -1];
      pos--;
    }
    dados[0] = dado;
  }
  // Adiciona dado na posicao fornecida pelo argumento
	void adicionaNaPosicao(T dado, int posicao) {
    if (listaCheia())
      throw 20;
    if (posicao > ultimo+1 || posicao < 0)
      throw 20;
    ultimo++;
    pos = ultimo;
    while (pos > posicao) {
      dados[pos] = dados[pos - 1];
      pos--;
    }
    dados[posicao] = dado;
  }
  // Adiciona dado na posição definida pela comparação de grandeza
	void adicionaEmOrdem(T dado) {
    if (listaCheia())
      throw 20;
    pos = 0;
    while (pos <= ultimo && (dado > dados[pos])) {
      pos++;
    }
    adicionaNaPosicao(dado, pos);
  }
  // Retira último elemento da Lista
	T retira() {
    if (listaVazia())
      throw 20;
    return dados[ultimo--];
  }
  // Retira elemento do início da Lista
	T retiraDoInicio() {
    if (listaVazia())
      throw 20;
    ultimo--;
    auxiliar = dados[0];
    pos = 0;
    while (pos <= ultimo) {
      dados[pos] = dados[pos + 1];
      pos++;
    }
    return auxiliar;
  }
  // Retira elemento na posicao fornecida pelo argumento
	T retiraDaPosicao(int posicao) {
    if (posicao > ultimo || posicao < 0)
      throw 20;
    ultimo--;
    auxiliar = dados[posicao];
    pos = posicao;
    while (pos <= ultimo) {
      dados[pos] = dados[pos + 1];
      pos++;
    }
    return auxiliar;
  }
  // Retira elemento especificado pelo argumento
	T retiraEspecifico(T dado) {
    if (listaVazia())
      throw 20;
    pos = posicao(dado);
    if (pos < 0)
      throw 20;
    return retiraDaPosicao(pos);
  }
  // Retorna a posição do dado especificado no argumento
	int posicao(T dado) {
    pos = 0;
    while (pos <= ultimo && !(igual(dado, dados[pos]))) {
      pos++;
    }
    if (pos > ultimo)
      throw 20;
    return pos;
  }
  // Retorna true se o dado especificado estiver na lista
	bool contem(T dado) {
    pos = 0;
    while (pos <= ultimo && !(igual(dado, dados[pos]))) {
      pos++;
    }
    if (pos > ultimo)
      return false;
    return true;
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
  // Retorna true se a lista estiver cheia
	bool listaCheia() {
    return ultimo == tamanho - 1;
  }
  // Retorna true se a lista estiver vazia
	bool listaVazia() {
    return ultimo == -1;
  }
  // Método para destruir lista
	void destroiLista() {
    ultimo = -1;
  }
};
