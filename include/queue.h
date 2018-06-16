#ifndef FilaCircular_H
#define FilaCircular_H
#include "listacircular.h"
#include <iostream>
#include <memory>

namespace myTads{

	template <typename T> class queue; // Declaracao antecipada da classe
	template <typename T> std::ostream& operator<<( std::ostream&, queue<T> const & ); // Definicao antecipada do template para o operador de insercao
	// --
	template <typename T>
	class queue {
	private:
		/**@details Todos os elementos da queue serão armazenados em uma Listacircular */
		myTads::list<T> lista;
		/**@brief  Armazena a quantidade de elementos que estão na fila*/
		int tamanho;
	public:
		/**@brief Constrotor padrão para a classe queue */
		queue();
		/**@brief Destruntor para a classe queue */
		~queue();
		/**@brief Coloca um ume elemento na fila, ou seja, coloca o elemento como o último elemento da fila */
		bool push(T content);
		/**@brief Remove o primeiro elemento da fila */
		bool pop();
		/**@breif Retorna o tamanho da Fila, ou seje, a quantidade de elementos que estão na fila */
		int size();
		/**@return retorna true se a fila está vázia, caso contrário, retorna verdadeiro */
		bool empty();
		/**@return acessa o elemento que está na frente da fila*/
		T front();
		/**@return acessa o elemento que está na última possição */
		T back();
		/**@details Sobrecarga do operador <<, @return retorna um std::ostream com todos os elementos da fila em uma linha separados por esparço*/
		friend std::ostream& operator<< <T>( std::ostream&, queue<T> const &l);
	};

	/*Construtor*/
	template <typename T>
	queue<T>::queue():  tamanho(0) {}

	template <typename T>
	queue<T>::~queue() {
		/**@TODO  Lembra de alterar o destrutor */
		}

	template <typename T>
	bool queue<T>::empty()
	{
		bool r = (tamanho == 0) ? true : false;
		return r; 
	}

	template <typename T>
	bool queue<T>::push(T content) {

		if(this->tamanho == 0){
			this->tamanho++;
			return lista.push_front( content);
		} 
			this->tamanho++;
		return lista.push_back( content);
	}

	template <typename T>
	bool queue<T>::pop() {
		if( lista.pop_front() == true){
			this->tamanho--;
			return true;
		}

		return false;
	}

	template <typename T>
	int queue<T>::size() {
		return this->tamanho;
	}

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

	template <typename T>
	T queue<T>::front()
	{
		return this->lista.front();
	}

	template <typename T>
	T queue<T>::back()
	{
		return this->lista.back();
	}


}
#endif