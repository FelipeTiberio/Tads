#include <iostream>
#include <vector>
#include <stack>
#include "listacircular.h"
#include "queue.h"
#include "stack.h"
#include <string>
using std::cout;
using std::endl;
using namespace myTads;

int main(int argc, char const *argv[])
{
	/*
	{
		cout << "Teste da pilha \n\n";
		// Pilha implementada em um deque (default)
		myTads::stack<int> pilha;

		if (pilha.empty())
			cout << "Pilha vazia." << endl;
		// Insere os elementos na pilha
		pilha.push(5); // topo -> [5]
		cout << 5 << "\n";
		pilha.push(7); // topo -> [7 5]
		cout << 7 << "\n";
		pilha.push(2); // topo -> [2 7 5]
		cout << 2 << "\n";
		cout << "Total de elementos: " << pilha.size() << endl;

		// Remove o elemento no topo da pilha
		pilha.pop(); // topo -> [7 5]

		cout << "Elemento no topo da pilha: " << pilha.top() << endl;
	}
	
	{
		cout << "Teste da fila \n\n";
		// Fila implementada em um deque (default)
		queue<string> fila;

		// Fila implementada em uma lista
		// Nota: usar espaco entre "> >"
		//       para diferenciar de ">>" !!
		
		queue<string> fila_lista; 

		if (fila.empty())
			cout << "Fila vazia." << endl;

		// Insere os elementos na fila
		fila.push("Roberto"); // front -> [Roberto] <- back
		fila.push("Antonio"); // front -> [Roberto Antonio] <- back
		fila.push("Maria"); // front -> [Roberto Antonio Maria] <- back
		fila.push("Paulo"); // front -> [Roberto Antonio Maria Paulo] <- back

		cout << "Total de elementos: " << fila.size() << endl;
		cout << fila << endl;
		// Remove o elemento no topo da fila
		//fila.pop(); // front -> [Antonio Maria Paulo] <- back
		cout << "Primeiro da fila: " << fila.front() << endl; // Antonio
		cout << "Ultimo da fila: " << fila.back() << endl; // Paulo
	}
	*/
	{
				// Instancia uma lista de string
		cout << "teste da lista \n\n";
		list<string> nomes;
		nomes.push_back("Paulo"); // [Paulo]
		nomes.push_back("Joao");  // [Paulo Joao]
		nomes.push_back("Aline"); // [Paulo Joao Aline]
		nomes.push_back("Mauricio"); // [Paulo Joao Aline Mauricio]

		cout << nomes << endl;

		for(int i = 0 ; i < 4 ; i++ ){
			cout << i << endl;
			nomes.pop_front();
		}
		cout << "888" << endl;

		//nomes.push_back("Paulo"); // [Paulo]
		//nomes.push_back("Joao");  // [Paulo Joao]
		//nomes.push_back("Aline"); // [Paulo Joao Aline]
		//nomes.push_back("Mauricio"); // [Paulo Joao Aline Mauricio]

			//cout << nomes << endl;


	}
	

	std::cout << "Fim do programa \n";
	return 0;
}


