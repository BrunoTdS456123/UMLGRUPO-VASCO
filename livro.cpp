#include "livro.hpp"



Livro::Livro() {}

Livro::~Livro() {}



std::string Livro::getTitulo() {
	return titulo;
}

std::string Livro::getAutor() {
	return autor;
}

std::string Livro::getEditora() {
	return editora;
}

int Livro::getAno() {
	return ano;
}

int Livro::getId() {
	return id;
}

bool Livro::getStatus() {
	return status;
}



void Livro::setTitulo(std::string _titulo) {
	titulo = _titulo;
}

void Livro::setAutor(std::string _autor) {
	autor = _autor;
}

void Livro::setEditora(std::string editora_){
	editora = editora_;
}

void Livro::setAno(int _ano) {
	ano = _ano;
}


void Livro::setId(int _id) {
	id = _id;
}

void Livro::setStatus(bool _status) {
	status = _status;
}

//funcoes