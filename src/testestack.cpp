#include <iostream>
#include <vector>
#include <stack>
#include "listacircular.h"
#include "pilha.h"
using std::cout;
using std::endl;
using namespace myTads;

int main(int argc, char const *argv[])
{
	
	// Pilha implementada em um deque (default)
	myTads::stack<int> pilha;

	if (pilha.empty())
		cout << "Pilha vazia." << endl;
	// Insere os elementos na pilha
	pilha.push(5); // topo -> [5]
	cout << 5;
	pilha.push(7); // topo -> [7 5]
	cout << 7;
	pilha.push(2); // topo -> [2 7 5]
	cout << 2;
	cout << "Total de elementos: " << pilha.size() << endl;

	// Remove o elemento no topo da pilha
	pilha.pop(); // topo -> [7 5]

	cout << "Elemento no topo da pilha: " << pilha.top() << endl;
	return 0;
}


