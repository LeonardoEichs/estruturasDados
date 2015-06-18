// Copyright [2015] <Leonardo Vailatti Eichstaedt>

template <typename T>
class Fila {
 private:
    T* m_dados;
    int tamanho;
    int ultimoFila;

 public:
	Fila() {}
	Fila<T>(int tam) {
	    m_dados = new T[tam];
	    ultimoFila = -1;
	    tamanho = tam - 1;
	}
	void inclui(T dado) {
	    if (filaCheia())
	        throw 20;
	    m_dados[++ultimoFila] = dado;
	}
	T retira() {
    T auxiliar;
	   if (filaVazia())
	        throw 20;
	   auxiliar = m_dados[0];
	   ultimoFila--;
	   for (int i = 1 ; i < ultimoFila; i++) {
	        m_dados[i - 1] = m_dados[i];
	   }
	   return auxiliar;
	}
	T ultimo() {
	    if (filaVazia())
	        throw 20;
	    return m_dados[ultimoFila];
	}
	int getUltimo() {
	    if (filaVazia())
	        throw 20;
	    return ultimoFila;
	}
	bool filaCheia() {
	    return ultimoFila == tamanho;
	}
	bool filaVazia() {
	    return ultimoFila == -1;
	}
	void inicializaFila() {
	    ultimoFila = -1;
	}
};
