#ifndef  LISTACIRCULAR_H
#define  LISTACIRCULAR_H
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::string;

namespace myTads{
	template <typename T> class list; // Declaracao antecipada da classe
	template <typename T> std::ostream& operator<<( std::ostream&, list<T> const & ); // Definicao antecipada do template para o operador de insercao

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
	// Implementação da classe list
	template <typename T>
	class list
	{
		/**@brief causa é  um ponteiro que ira apontar para o último Node da lista*/
		shared_ptr<Node<T>> cauda;
		/**@breif O atributo tamanho mastra quantos elementos estão atualmente na lista */
		int tamanho;
	public:
		/**@brief Construtor padrão classe list*/
		list();
		/**@brief Destrutor classe list */
		~list();
		/**@brief Insere um elemento no ínicio da lista @return retorna true se não houve erro, caso contrário, retorna false  */
		bool push_front(T content);
		/**@brief Insere um elemento no final da lista @return retorna true se não houve erro, caso contrário retorna false */
		bool push_back(T content);
		/**@brief Insere um elemento em uma posição passada n da lista. */
	 	bool insert(int pos, T content);
	 	/**@brief Remove o elemento que está no íncio da lista.@return retorna true se não houve erro, caso contrário, retorna false*/
		bool pop_front();
		/**@details Remove o lemento que está ao final da lista@return retorna true se não houve erro, caso contrário, retorna false*/
		bool pop_back();
		/**@details Remove o elemento na posição que foi recebida como parêmetro( lembra que o íncide inicia-se em 0).@return retorna true se não houve erro, caso contrário, retorna false*/
		bool erase_at(int pos);
		/**@return retorna se a lista está ou não vázia */
		bool empty();
		/**@return retorna o size de lista, i.e., a quatidade de Node's */
	    int size();
	    /**@return retorna o primeiro elemento da lista, caso vázio retorna nullptr */
	    T front();
	    /**@return retorna o último elemento da lista, caso vázio retorna nullptr  */
	    T back();
		/**@details Sobrecarga do operador <<, @return retorna um std::ostream com todos os elementos da lista em uma linha separados por esparço*/
		friend std::ostream& operator<< <T>( std::ostream&, list<T> const &l);
	};

	template <typename T>
	list<T>::list(): cauda(nullptr), tamanho(0)  {}

	template <typename T>
	list<T>::~list() {
		/*Tenho o hábito de esquecer de  implementar os destrutores, caso eu esqueça me lembrem */
	}

	template <typename T>
	bool list<T>::empty()
	{
		bool r = (this->tamanho == 0) ? true : false;
		return r; 
	}

	template <typename T>
	int list<T>::size() {
		return this->tamanho;
	}

	template <typename T>
	bool list<T>:: push_front(T content) {
		if (this->tamanho == 0) {
			auto  novo = make_shared<Node<T>>(content); //Recebo o novo content e o coloco em novo
			if (!novo) return false; // Se ocorreu algum problema na alocação retorna falso 
			novo->setNext(novo); //Como é circula, e só há elemento então ele é reflexivo, pois é o primeiro e último ao mesmo tempo
			this->cauda = novo; // a cauda apota para o último elemento
			this->tamanho++;
			return true;

		} else {
			auto antigo_primeiro = this->cauda->getNext(); //Antigo_primeiro será aquele que é apontado pelo último
			auto novo_primeiro = make_shared<Node<T>>(content); // novo elemento da fila
			this->cauda->setNext(novo_primeiro); // o último aponta para o novo primeiro 
			this->cauda->getNext()->setNext(antigo_primeiro);// novo primeiro aponta para antigo primeiro
			this->tamanho++;
		}
		return true;
	}

	template <typename T>
	bool list<T>::push_back(T content) {
		
		if(this->tamanho == 0) // Se não há nada na fila
		{
			return  push_front(content);
		}else {

			auto penultimo = this->cauda; // penultimo aponta para o último atualmente na fila
			auto novo_ultimo  = make_shared<Node<T>>(content); // o novo último recebe o novo valor para a lista  
			
			novo_ultimo->setNext(penultimo->getNext()); // o novo último aponta para onde o penultimo apontava, no caso o primeiro 
			penultimo->setNext(novo_ultimo); // o penultimo aponta para o novo último
			this->cauda = novo_ultimo; // cauda aponta para o novo último
			this->tamanho++; // acrescentasse em 1 o tamanho da fila
		}
		return true;
	}

	template <typename T>
	bool list<T>::insert(int pos, T content) {
		if (pos<0) return false;
		if (pos==0)	return  push_front(content);

		auto atual = this->cauda->getNext();
		int posAtual = 0;

		while (atual->getNext() != this->cauda && posAtual < pos-1) {
			atual = atual->getNext();
			posAtual++;
		}
		
		auto novo = make_shared<Node<T>>(content);
		if (!novo) return false;

		novo->setNext(atual->getNext());
		atual->setNext(novo);
		this->tamanho++;
		return true;
	}

	template <typename T>
	bool list<T>::pop_front() {
		if (this->tamanho <= 0) //Será verdadeira quando a fila estiver vázia
		{ 
			return false;
		} 
		else if (this->tamanho == 1) // Será verdadeira quando há apenas um elemento na fila 
		{
			
			this->cauda->setNext(nullptr); // A cauda aponta para o primeiro elemento, assim o primeiro elemento agora aponta para nulo
			this->cauda = nullptr; // A cauda é um ponteiro nullo
			this->tamanho--;
			return true;
		} 
		else
		{
			this->cauda->setNext(this->cauda->getNext()->getNext()); // o novo primeiro será, aquele que é apontado pelo primeiro
			this->tamanho--;
			return true;
		}
	}

	template <typename T>
	bool list<T>::pop_back() {
		if (this->cauda==nullptr ) return false;// Se lista vázia 

		if (this->tamanho == 1 ){  // Se lista com apenas um elmento 
			return pop_front();
		}

		auto atual = this->cauda->getNext();
		while (atual->getNext()->getNext() != this->cauda){ // depois desse larço o atual será o antepenúltimo
			atual = atual->getNext();
		}

		atual->getNext()->setNext(this->cauda->getNext()); // como atual é o antepenúltimo, atual->getNext() será o penúltimo,  penúltimo aponta para o primeiro 
		this->cauda = atual->getNext(); // cauda aponta para o novo penúltimo
		this->tamanho--;
		return true;
	}

	template <typename T>
	bool list<T>::erase_at(int pos) {
		//cout << "tamanho = " << this->tamanho << "\n";
		if (pos < 0) return false; 
		if (pos == 0)	return pop_front();
		if (pos == this->tamanho -1 ) return pop_back();
		if (pos > this->tamanho  ) return false ;

		auto atual = this->cauda->getNext();
		int posAtual = 0;
		while (atual->getNext()->getNext() != this->cauda && posAtual < (pos-1)) {
			atual = atual->getNext();
			posAtual++;
		}

		atual->setNext(atual->getNext()->getNext());
		this->tamanho--;

		return true;
	}

	template <typename T>
	std::ostream& operator<< ( std::ostream& o, list<T> const &l) {
		auto atual = l.cauda->getNext();
		int  i =0;
		while ( i != l.tamanho) {
			o << atual->getValor() << " ";
			atual = atual->getNext();
			i++;
		}
		return o;
	}

	template <typename T>
	T list<T>::front()
	{
		/**@TODO Colocar aqui uma exceção */
		if (this->tamanho <= 0) 
		{ 
			cout << "ERRO lista Vázio, O programa será finalizado \n";
			exit(1);
		} 
		else
		{
			return this->cauda->getNext()->getValor();
		}
	}

	template <typename T>
	T list<T>::back()
	{
		/**@TODO Colocar aqui uma exceção */
		if (this->tamanho <= 0) 
			{ 
				cout << "ERRO lista Vázio, O programa será finalizado \n";
				exit(1);
			} 
			else
			{
				return this->cauda->getValor();
			}

	}

}

#endif