#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>

class Livro {

public:

    Livro();

    ~Livro();

    //get

    int getAno();

    std::string getTitulo();

    std::string getAutor();

    std::string getEditora();

    int getId();

    bool getStatus();

    //set

    void setTitulo(std::string _titulo);

    void setAutor(std::string _autor);

    void setAno(int _ano);

    void setEditora(std::string _genero);

    void setStatus(bool _status);

    void setId(int _id);

private:

    std::string titulo, autor, editora;
    int ano, id;
    bool status;
};

#endif