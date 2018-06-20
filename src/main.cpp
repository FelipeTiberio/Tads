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
	return 53;
}


int main(int argc, char const *argv[])
{
	
	std::ifstream arquivo("arquivo.txt");
	if(!arquivo)
	{
		cout << "Erro na leitura do arquivo \n";
		exit(1);
	}

	std::vector<shared_ptr<Node<string>>> vect;
	vect.resize(53,nullptr);
	std::string line;
	std::string palavra_aux;

	int possicao = 0;

	while(getline(arquivo, line))
	{
		std::stringstream  str(line);
		std::getline(str, palavra_aux, ' ');
		possicao = dispen(palavra_aux);

	}



	return 0;
}