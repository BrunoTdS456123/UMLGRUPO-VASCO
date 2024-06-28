#include<iostream>
#include <string>
#include "user.hpp"
#include "emprestimo.hpp"
#include "livro.hpp"
#include <vector>

int option;


using namespace std;

void inicializarLivros(std::vector<Livro*>& livros){
    for (int i = 0; i < 10; i++) {
        Livro* livro = new Livro();
        livro->setTitulo("Livro " + std::to_string(i+1));
        livro->setAutor("Autor " + std::to_string(i+1));
        livro->setAno(2000 + i+1);
        livro->setEditora("Editora " + std::to_string(i+1));
        livro->setId(i);
        livros.push_back(livro);
    }
}
void inicializarBiblioteca(){
    User user;
    cout << "----------------------Bem vindo a biblioteca simas!----------------------\n|Digite:\n|1 Cadastrar usuario ,\n|2 Fazer login e \n|3 Entrar como admin\n|4 Sair";
    cin >> option ;
    switch(option){
    case 1:
        user.cadastrar();
        break;
    case 2:
        //user.login();
        break;
    case 3:
        user.isAdm(); 
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
    
    
    inicializarBiblioteca();
    inicializarLivros(livros);

   
    //int is_adm;
    //User onielson;
    //onielson.cadastrar();
    //onielson.isAdm();
    return 0;
}