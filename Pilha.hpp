// Copyright [2015] <Leonardo Vailatti Eichstaedt>

template<typename T>
class Pilha {
 private:
    T* m_dados;
    int tamanho;
    int topoPilha;

 public:
    Pilha() {}
    Pilha<T>(int t) {
        m_dados = new T[t];
        topoPilha = -1;
        tamanho = t - 1;
    }
	void empilha(T dado) {
	    if (PilhaCheia())
	        throw 20;
	    m_dados[++topoPilha] = dado;
	}
	T desempilha() {
	    if (PilhaVazia())
	        throw 20;
	    return m_dados[topoPilha--];
	}
	T topo() {
	    return m_dados[topoPilha];
	}
    int getPosTopo() {
        if (topoPilha == -1)
            throw 20;
        return topoPilha;
    }
	void limparPilha() {
	    topoPilha = -1;
	}
	bool PilhaVazia() {
	    return topoPilha == -1;
	}
	bool PilhaCheia() {
	    return topoPilha == tamanho;
	}
};
