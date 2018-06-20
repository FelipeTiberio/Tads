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

	if(arquivo)
	{
		std::vector<shared_ptr<Node<string>>> tabela;
		tabela.resize(53,nullptr);

		std::string palavra_aux;
		int pos = 0;

		int conta = 1;

		while(!arquivo.eof()) // condicional está lendo o arquivo 
		{
		
			getline(arquivo, palavra_aux, ' ');
			pos = dispen(palavra_aux);
			bool existe{false};
			cout << "Iterações " << conta << endl;
			conta +=1;

			if(tabela[pos]==nullptr) // verifica se na possição já existe um valor
			{
				if(palavra_aux.at(0) != '\n')
				tabela[pos] = make_shared<Node<string>>(palavra_aux);
				continue;
			}

			if(tabela[pos] != nullptr){ // verifica se já existe a palavra na linha da tabela 
				int atual = pos;

				do{ // percorre toda a linha da tabela 
					if(tabela[atual]->getValor() == palavra_aux ){ // se palavra está na linha 
						tabela[atual++]->plus();
						existe = true;
					}

				}while(tabela[atual]->getNext() != nullptr);
			}
			cout << "antes do if\n";
			if(existe == false){ // caso não exista a palavra na tabela, cria um novo node e a coloca
				tabela[pos]->setNext(make_shared<Node<string>>(palavra_aux));
				cout << "entrei aqui\n";
			}
		}
		cout << " Valores na Tabela\n";
		for(int i = 0; i < 53 ; i++ ){

			if(tabela[i] != nullptr){
				cout << "["<< i << "] " << tabela[i]->getValor() << "=" << tabela[i]->getRepeticoes() ;
				while(tabela[i]->getNext() != nullptr){
					cout << " | " << tabela[i]->getValor() << " | ";
				}
				cout << endl;
			}
			
		}
		
	}else{
		cout << "Erro na leitura do arquivo \n";
		exit(1);
	}



	return 0;
}