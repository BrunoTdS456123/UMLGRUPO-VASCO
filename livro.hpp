#include <iostream>
#include <string>
#include <vector>
#ifndef LIVRO_HPP
#define LIVRO_HPP


using namespace std;

class Livro{
    public:
     Livro();
    ~Livro();
   

     void setTitulo(std::string _titulo){
            titulo = _titulo;
        }

        void setAutor(std::string _autor){
            autor = _autor;
        }

        void setAno(int _ano){
            ano = _ano;
        }

        void setEditora(std::string _editora){
            editora = _editora;
        }   

        std::string getTitulo(){
            return titulo;
        }

        std::string getAutor(){
            return autor;
        }

        int getAno(){
            return ano;
        }

        std::string getEditora(){
            return editora;
        }

        bool getStatus(){
            return status;
        }

        void setStatus(bool _status){
            status = _status;
        }

        void setId(int _id){
            id = _id;
        }

        int getId(){
            return id;
        }



    private:
        bool status;
        std::string titulo, autor, editora;
        int ano, id;
        
};

#endif