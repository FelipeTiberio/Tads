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
		std::vector<shared_ptr<list<string>>> tabela;
		tabela.resize(53,nullptr);

		bool existe_lista = false; // verifica se já existe uma lista em uma posição do vector
		std::string palavra_aux;
		int pos = 0;
	
		while(!arquivo.eof()) // condicional está lendo o arquivo 
		{
			getline(arquivo, palavra_aux, ' ');
			pos = dispen(palavra_aux);

			if(tabela[pos]==nullptr) // verifica se na possição já existe um valor, se não criar a tabela com o valor 
			{
				if(palavra_aux.at(0) != '\n')
					tabela[pos] = make_shared<list<string>>(palavra_aux);
				continue;
			}else if(tabela[pos] != nullptr)// verifica se já existe a palavra na linha da tabela, se sim aumenta o contador 
			{ 
				int n  = tabela[pos]->size();
				auto atual = tabela[pos];
				existe_lista = true;

				for(int i = 0; i < n; i++ )// percorre toda linha procurando por palavras repitidas 
				{ 
					//cout  << atual->return_at(i) << " = " << palavra_aux << " valor = " << (atual->return_at(i) == palavra_aux) << endl ;
					if(atual->return_at(i) == palavra_aux)
					{
						atual->plus_at(i);
						continue;
					}
				}			
			}else if((existe_lista == true)) // caso já se tenha instanciando uma lista ẽ na linha a palavra não exista 
			{
				cout << " entrei aqui " << palavra_aux << endl;
				auto atual = tabela[pos];
				atual->push_back(palavra_aux);
			}
		
		}

		cout << " Valores na Tabela\n";
		for(int i = 0; i < 53 ; i++)
		{
			if(tabela[i] !=nullptr){
				auto atual = tabela[i];
				cout <<"["<< i << "]" << atual->front() << "=" << atual->return_rep(0) ;
				cout << "** tamanho das listas **  = " << atual->size() ;
				for(int j = 1; j <= atual->size() ; j++)
				{
					if(!(j>atual->size()-1))
					cout << " | " << atual->return_at(j) << "=" << atual->return_rep(j);
				}
				cout << endl;
			}			
		}
		
		
	}else
	{
		cout << "Erro na leitura do arquivo \n";
		exit(1);
	}

	





	return 0;
}