#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>

class Livro {

public:
    Livro();
    ~Livro();
    int getAno();
    void setAno(int _ano);


    std::string getTitulo();
    void setTitulo(std::string _titulo);

    std::string getAutor();
    void setAutor(std::string _autor);

    std::string getEditora();
    void setEditora(std::string _genero);

    int getId();
    void setId(int _id);

    bool getStatus();
    void setStatus(bool _status);

 private:
    bool status;

    std::string  autor, editora,titulo ;

    int ano, id;
    
};

#endif