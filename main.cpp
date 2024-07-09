#include<iostream>
#include <string>
#include "user.hpp"
#include "emprestimo.hpp"
#include "livro.hpp"
#include <vector>

int option;


using namespace std;

void iniciarMultas(std::vector<User*>& users) {
    for (User* user : users) {
        user->calcMulta();
    }
}

void inicializarLivros(std::vector<Livro*>& livros){
    for (int i = 0; i < 10; i++) {
        Livro* livro = new Livro();
        livro->setTitulo("Livro " + std::to_string(i+1));
        livro->setAutor("Autor " + std::to_string(i+1));
        livro->setAno(2000 + i+1);
        livro->setEditora("Editora " + std::to_string(i+1));
        livro->setId(i);
        livro->setStatus(true);
        livros.push_back(livro);
    }
}

void mostrarLivros(std::vector<Livro*>& livros) {
    for (int i = 0; i < 10; i++) {
        //colocar tamanho ao inves do "i", por que se for criado um livro novo pode ser que nao imprima ( o 11 )
        Livro* livro = livros[i];
        std::cout << "Livro: " << livro->getTitulo() << ", ID: " << livro->getId() + 1 << ", Autor: " << livro->getAutor() << ", Ano: " << livro->getAno() << std::endl;
     
      
    }
}
void inicializarBiblioteca(){
    //User users;
    cout << "------------------------Bem vindo a biblioteca simas!----------------------\n|Digite:\n|1 Cadastrar usuario ,\n|2 Fazer login e \n|3 Entrar como admin\n|4 Sair\n";
    cin >> option ;
    switch(option){
    case 1:
        
        break;
    case 2:
        //user.login();
        break;
    case 3:
         
        break;
    case 4:
        return;
        break;
    default:

        break;
    }
}

int main(){
    std::vector<Livro*> livros;
    std::vector<User*> users;
    
    
    inicializarBiblioteca();
    inicializarLivros(livros);
    mostrarLivros(livros);

   
    //int is_adm;
    //User onielson;
    //onielson.cadastrar();
    //onielson.isAdm();
    return 0;
}