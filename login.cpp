#include "login.hpp"
#include "usuario.hpp"
#include "livro.hpp"
#include "admnistrador.hpp"

#include <iostream>
#include <vector>

void Login::login(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& usuarioId, std::string administradorSenha) {
    std::string login, senha;

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\nInsira o nome de usuario: ";
        std::cin >> login;

        std::cout << "Insira a senha: ";
        std::cin >> senha;

        bool found = false;

        for (Adm* adm : adms) {
            if (adm->getLogin() == login && adm->getSenha() == senha) {
                std::cout << "\nAdiminstrador logado\n";
                adm->opcoesUsuario(livros, usuarios, adms, usuarioId, administradorSenha);
                found = true;
                break;
            }
        }
        if (!found) {
            for (Usuario* usuario : usuarios) {
                if (usuario->getLogin() == login && usuario->getSenha() == senha) {
                    std::cout << "\nUsuario logado\n";
                    usuario->opcoesUsuario(livros, usuarios);
                    found = true;
                    break;
                }
            }
        }

        if (found == false) {
            std::cout << "\nUsuario ou senha invalidos\n";
        }
        else {
            break;
        }
    }
}