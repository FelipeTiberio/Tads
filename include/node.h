//Definição e implementação da classe node, na sua vertente genérica
#ifndef NODE_H
#define NODE_H
#include <memory>

namespace myTads{

	// Declaracao antecipada da classe
	template <typename T> class Node; 
	// Definicao antecipada do template para o operador de insercao
	template <typename T> std::ostream& operator<<( std::ostream&, Node<T> const & );

	template <typename T>
	class Node
	{
	private:
		// Elemento genérico que será usando com um Node para um conteiner
		T valor;
		// Ponteiro que apontará para o próximo elemento no conteiner 
		std::shared_ptr<Node<T>> proximo;
	public:
		
		Node();		
		Node(T content);		
		~Node();		
		Node(T num, std::shared_ptr<Node> nextPtr);		
		T getValor();		
		std::shared_ptr<Node<T>> getNext();		
		void setNext(std::shared_ptr<Node<T>> nextPtr);		
		friend std::ostream& operator<< <T>(std::ostream &o, Node<T> const &n);
	};

	// Construtor padrão para a classe Node 
	template <typename T>
	Node<T>::Node() : valor(), proximo(nullptr) {}

	// Contrutor parametrizado para a classe Node,recebe com parâmetro um elemento genérico do tipo T 
	template <typename T>
	Node<T>::Node(T content) : valor(content), proximo(nullptr) {}

	// Destrutor Classe Node
	template <typename T>
	Node<T>::~Node() {
		//cout << "Node(" << valor << ") removido." << endl;
	}

	// Construtor parametrizado para a classe Node,recebe com parâmetro um elemento genérico do tipo T
	// e um ponteiro para um objeto do tipo Node
	template <typename T>
	Node<T>::Node(T content, std::shared_ptr<Node<T>> nextPtr) : valor(content), proximo(nextPtr) {}

	// Retorna o valor armazenado em um Node
	template <typename T>
	T Node<T>::getValor() {
		return valor;
	}

	// Retorna um ponteiro para o elemento posterio ao objeto que o chamou 
	template <typename T>
	std::shared_ptr<Node<T>> Node<T>::getNext() {
		return proximo;
	}

	// Setter para quem o Node está apontando
	template <typename T>
	void Node<T>::setNext(std::shared_ptr<Node<T>> nextPtr) {
		proximo = nextPtr;
	}

	// Sobrecarga do operador <<
	template <typename T>
	std::ostream& operator<< (std::ostream &o, Node<T> const &n) {
		o << n.valor;
		return o;
	}

}
#endif