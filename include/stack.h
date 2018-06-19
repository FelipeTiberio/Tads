//Definição e implementação da classe stack, na sua vertente genérica
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <memory>
#include "listacircular.h"

namespace myTads {

	// Declaracao antecipada da stack
	template <typename T> class stack; 
	// Definicao antecipada do template para o operador de insercao
	template <typename T> std::ostream& operator<< ( std::ostream&, list<T> const &);

	template <typename T>
	class stack{
	private:
		myTads::list<T> pilha;
		//Quantidade de elementos que estão sendo guardados na pilha
		int tamanho;    
	public:
		stack();
		~stack ();
		
		bool empty();
		T top ();
		bool push ( T novo );
		void pop ();
		int size();
		//Sobrecarga do operador <<, retorna um std::ostream com todos os elementos
		// da lista em uma linha separados por espaço - Falta implementar
		friend std::ostream& operator<< <T>( std::ostream&, list<T> const &l);

	};
	//Construtor padrão, que instanciará a pilha com tamanho igual a zero
	template <typename T>
	stack<T>::stack (): tamanho(0){}

	//Destrutor padrão
	template <typename T>
	stack<T>::~stack (){}

	//Método que verifica se a pilha esta vazia ou não
	template <typename T>
	bool stack<T>::empty ()
	{
		return tamanho == 0;
	}

	//Método de empilhamento
	template <typename T>
	bool stack<T>::push ( T novo )
	{
		 this->tamanho++;
		 return pilha.push_back(novo);
	}
	
	//Método de desempilhamento	
	template <typename T>
	void stack<T>::pop ()
	{
		//Verifica se a pilha está vazia. Se sim exibe mensagem de erro, se não, executa o desempilhamento	
		if(empty()) {
			std::cout << std::endl << "Erro: stack vazia!" << std::endl;
		}else{
		this->tamanho--;
		pilha.pop_back();
		}
	
	}

	//Método de acesso ao elemento do topo da pilha
	template <typename T>
	T stack<T>::top ()
	{	
		// Verificação da existência de elementos na pilha. Se pilha vazia exibe mensagem, senão
		// retorna o elemento do topo. 
		if (empty()) {
			std::cerr << "Não há expressões para serem executadas. O programa sera fechado!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return pilha.back();
	}

	// Método de verficação do tamanho da pilha
	template <typename T>
	int stack<T>::size ()
	{
		return tamanho;
	}

}
#endif 