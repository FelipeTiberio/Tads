//Definição e implementação da classe queue, na sua vertente genérica
#ifndef FilaCircular_H
#define FilaCircular_H
#include "listacircular.h"
#include <iostream>
#include <memory>

namespace myTads{

	// Declaracao antecipada da classe
	template <typename T> class queue; 
	// Definicao antecipada do template para o operador de insercao
	template <typename T> std::ostream& operator<<( std::ostream&, queue<T> const & ); 
	
	template <typename T>
	class queue {
	private:
		// Todos os elementos da queue serão armazenados em uma Listacircular
		myTads::list<T> lista;
		// Armazena a quantidade de elementos que estão na fila
		int tamanho;
	public:
		
		queue();
		
		~queue();
		
		bool push(T content);
		
		bool pop();
		
		int size();
		
		bool empty();
		
		T front();
		
		T back();
		
		friend std::ostream& operator<< <T>( std::ostream&, queue<T> const &l);
	};

	//Construtor padrão 
	template <typename T>
	queue<T>::queue():  tamanho(0) {}

	// Destrutor padrão
	template <typename T>
	queue<T>::~queue() 
	{	
		int n = tamanho;
		for(int i = 0; i < n; i++)
			this->pop();
	}

	// Retorna true se a fila está vázia, caso contrário, retorna verdadeiro
	template <typename T>
	bool queue<T>::empty()
	{
		bool r = (tamanho == 0) ? true : false;
		return r; 
	}

	// Coloca um ume elemento na fila, ou seja, coloca o elemento como o último elemento da fila
	template <typename T>
	bool queue<T>::push(T content) {

		if(this->tamanho == 0){
			this->tamanho++;
			return lista.push_front( content);
		} 
			this->tamanho++;
		return lista.push_back( content);
	}

	// Remove o primeiro elemento da fila 
	template <typename T>
	bool queue<T>::pop() {
		if( lista.pop_front() == true){
			this->tamanho--;
			return true;
		}

		return false;
	}

	// Retorna o tamanho da Fila, ou seja, a quantidade de elementos que estão na fila
	template <typename T>
	int queue<T>::size() {
		return this->tamanho;
	}

	//Sobrecarga do operador <<, retorna um std::ostream com todos os elementos da fila
	// em uma linha separados por espaço
	template <typename T>
	std::ostream& operator<< ( std::ostream& o, queue<T> const &l) {
		if(l.tamanho==0)
		{
			o << "**| Fila vázio |** " ;
			return o;
		}
			o << l.lista ;
		return o;
	}

	// Acessa o elemento que está na frente da fila
	template <typename T>
	T queue<T>::front()
	{
		return this->lista.front();
	}

	// Acessa o elemento que está na última possição 
	template <typename T>
	T queue<T>::back()
	{
		return this->lista.back();
	}


}
#endif