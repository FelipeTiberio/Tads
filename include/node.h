#ifndef NODE_H
#define NODE_H
#include <memory>
using std::shared_ptr;


namespace myTads{

	template <typename T> class Node; // Declaracao antecipada da classe
	template <typename T> // Definicao antecipada do template para o operador de insercao
	std::ostream& operator<<( std::ostream&, Node<T> const & );

	//Implementação dos Node
	template <typename T>
	class Node
	{
	private:
		/**@details elemento genérico que será usando com um Node para um conteiner */
		T valor;
		/**@details  ponteiro que apontará para o próximo elemento no conteiner  */
		shared_ptr<Node<T>> proximo;
	public:
		/**@brief  Construtor padrão para a classe Node*/
		Node();
		/**@brief Contrutor parametrizado para a classe Node,@param recebe com parâmetro um elemento genérico do tipo T */
		Node(T content);
		/**@brief Destrutor Classe Node*/
		~Node();
		/**@details Contrutor parametrizado para a classe Node,@param recebe com parâmetro um elemento genérico do tipo T, e um ponteiro para um objeto do tipo Node */
		Node(T num, shared_ptr<Node> nextPtr);
		/**@return Retorna o valor armazenado em um Node */
		T getValor();
		/**@return Retorna um ponteiro para o elemento posterio ao objeto que o chamou */
		shared_ptr<Node<T>> getNext();
		/**@brief Setter para quem o Node está apontando */
		void setNext(shared_ptr<Node<T>> nextPtr);
		/**@brief Sobrecagar do operador <<*/
		friend std::ostream& operator<< <T>(std::ostream &o, Node<T> const &n);
	};

	template <typename T>
	Node<T>::Node() : valor(), proximo(nullptr) {}

	template <typename T>
	Node<T>::Node(T content) : valor(content), proximo(nullptr) {}

	template <typename T>
	Node<T>::~Node() {
		//cout << "Node(" << valor << ") removido." << endl;
	}

	template <typename T>
	Node<T>::Node(T content, shared_ptr<Node<T>> nextPtr) : valor(content), proximo(nextPtr) {}

	template <typename T>
	T Node<T>::getValor() {
		return valor;
	}

	template <typename T>
	shared_ptr<Node<T>> Node<T>::getNext() {
		return proximo;
	}

	template <typename T>
	void Node<T>::setNext(shared_ptr<Node<T>> nextPtr) {
		proximo = nextPtr;
	}

	template <typename T>
	std::ostream& operator<< (std::ostream &o, Node<T> const &n) {
		o << n.valor;
		return o;
	}

}
#endif