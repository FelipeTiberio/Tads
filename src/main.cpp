#include <iostream>
#include <random>
#include <vector>
#include "listacircular.h"
#include <memory>
#include <fstream>
#include <sstream>
#include "node.h"

using std::shared_ptr; using std::vector;
using std::make_shared; using std::endl;
using std::cout; using std::string; using std::ifstream;
using namespace myTads;


int dispen(std::string palavra){
	int cont = 0;

	for(unsigned int i =0 ; i < palavra.size(); i++)
	{
		cont+= (int)(palavra.at(i));
	}
	return cont % 53;
}


int main(int argc, char const *argv[])
{
	
	std::ifstream arquivo("arq/file.txt");
	if(!arquivo)
	{
		cout << "Erro na leitura do arquivo \n";
		exit(1);
	}

	std::vector<shared_ptr<Node<string>>> tabela;
	tabela.resize(53,nullptr);
	std::string line;
	std::string palavra_aux;

	int pos = 0;

	while(getline(arquivo, line)) // condicional está lendo o arquivo 
	{
		std::stringstream  str(line);
		std::getline(str, palavra_aux, ' ');
		pos = dispen(palavra_aux);
		bool existe{false};

		if(tabela[pos]==nullptr) // verifica se na possição já existe um valor
		{
			tabela[pos] = make_shared<Node<string>>(palavra_aux);
			continue;
		}
		
		else if(tabela[pos] != nullptr){ // verifica se já existe a palavra na linha da tabela 
			int atual = pos;

			do{ // percorre toda a linha da tabela 
				if(tabela[atual]->getValor()==palavra_aux){ // se palavra está na linha 
					tabela[atual++]->plus();
					existe = true;
				}

			}while(tabela[pos]->getNext() != nullptr);
		}
		else if(existe == false){ // caso não exista a palavra na tabela, cria um novo node e a coloca
			tabela[pos]->setNext(make_shared<Node<string>>(palavra_aux));
		}
	}


	return 0;
}