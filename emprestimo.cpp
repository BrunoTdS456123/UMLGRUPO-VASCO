#include <iostream>
#include <string>
#include "emprestimo.hpp"
#include <vector>



using namespace std;



Emprestimo::Emprestimo(){};
Emprestimo::~Emprestimo(){};


float Emprestimo::Registro(){
   std::cout << "insira o número do livro que deseja locar:";
   std::cin >> id_livro;
   std::cout  << "dia 10 de julho";
   data_loc=10;
   data_dev=24;
   std::cout << "a data de devolução do livro é:" << data_dev << "de julho";
   
}

