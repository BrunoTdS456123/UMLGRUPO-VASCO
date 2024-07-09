#include <iostream>
#include <string>
#include "emprestimo.hpp"

Emprestimo::Emprestimo(int id__) {
	idLivro = id__;
	
}
Emprestimo::~Emprestimo() {

}
int Emprestimo::getIdLivro() {
    return idLivro;
}
void Emprestimo::setIdLivro(int _id) {
    idLivro = _id;
}










