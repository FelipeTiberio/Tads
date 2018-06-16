#ifndef Pilha_H
#define Pilha_H
#include <iostream>
#include <memory>
#include "listacircular.h"

namespace myTads {

	template <typename T> class stack; // Declaracao antecipada da stack

	template <typename T>
	class stack{
	private:
		myTads::list<T> pilha;
		/**@brief Quantidade de elementos que estão sendo guardados na pilha */
		int tamanho;    
	public:
		stack();
		~stack ();
		/**@brief Retorna verdadeiro se a pilha está vázio, falso caso contrário*/
		bool empty();
		/**@brief Retorna uma referencia para o último elemento da pila */
		T top ();
		/**@brief coloca um elemento no topo da fila  */
		bool push ( T novo );
		/**@brief remove o elemento que está no topo da fila */
		void pop ();
		/**@return retorna a quantidade de elemetos na pilha  r*/
		int size();
		/**@details Sobrecarga do operador <<, @return retorna um std::ostream com todos os elementos da lista em uma linha separados por esparço*/
		friend std::ostream& operator<< <T>( std::ostream&, list<T> const &l);

	};

	template <typename T>
	stack<T>::stack (): tamanho(0){}

	template <typename T>
	stack<T>::~stack ()
	{
		/* Lembra de implementar */
	}

	template <typename T>
	bool stack<T>::empty ()
	{
		return tamanho == 0;
	}

	template <typename T>
	bool stack<T>::push ( T novo )
	{
		 this->tamanho++;
		 return pilha.push_back(novo);
	}
		
	template <typename T>
	void stack<T>::pop ()
	{
		/*TODO Talvez colocar aqui algum tipo de aqui excerção  */
		if(empty()) {
			std::cout << std::endl << "Erro: stack vazia!" << std::endl;
		}else{
		this->tamanho--;
		pilha.pop_back();
		}
	
	}

	template <typename T>
	T stack<T>::top ()
	{	
		/*TODO Colocar uma exceção aqui depois */
		if (empty()) {
			std::cerr << "Acesso invalido a elemento no topo. O programa sera fechado!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return pilha.back();
	}

	template <typename T>
	int stack<T>::size ()
	{
		return tamanho;
	}

}
#endif 