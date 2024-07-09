#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP


#include <iostream>
#include <sstream>

class livro;

class Emprestimo {

public:

    Emprestimo(int _id);
    ~Emprestimo();

    int getIdLivro();
    void setIdLivro(int _id);;
    
private:
    int idLivro;
};
#endif