#include <iostream>
#include <string>
#include <vector>

#include "usuario.hpp"
#include "admnistrador.hpp"
#include "livro.hpp"
#include "cadastro.hpp"
#include "login.hpp"
#include "inicio.hpp"


void livroCriacao(std::vector<Livro*>& livros) {
    for (int x = 0; x < 10; x++) {
        Livro* livro = new Livro();
        livro->setAno(2024);
        livro->setEditora("Editora " + std::to_string(x + 1));
        livro->setId(x);
        livro->setTitulo("T�tulo " + std::to_string(x + 1));
        livro->setAutor("Autor " + std::to_string(x + 1));
        livros.push_back(livro);
    }
}

int main() {
    std::string admnistradorSenha = "flasco";
    std::vector<Livro*> livros;
    std::vector<Adm*> administradores;
    std::vector<Usuario*> usuarios;
    
    int usuarioId = 0;

    livroCriacao(livros);
    Inicio::inicio(usuarios, livros, administradores, usuarioId, admnistradorSenha);

    

    for (auto it = livros.begin(); it != livros.end(); ) {
        delete* it;
        *it = nullptr;
        it = livros.erase(it);
    }
    livros.clear();

    for (auto it = usuarios.begin(); it != usuarios.end(); ) {
        delete* it;
        *it = nullptr;
        it = usuarios.erase(it);
    }
    usuarios.clear();

    for (auto it = administradores.begin(); it != administradores.end(); ) {
        delete* it;
        *it = nullptr;
        it = administradores.erase(it);
    }
    administradores.clear();

    return 0; 
}