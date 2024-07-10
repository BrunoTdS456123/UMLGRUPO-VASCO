#include "inicio.hpp"
#include "cadastro.hpp"
#include "login.hpp"

void Inicio::inicio(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& usuarioId, std::string administradorSenha) {
    int opcao;

    std::cout << "\nSeja bem-vindo ao inicio da biblioteca flasco\n";

    while (true) {
        std::cout << "\n===================================================\n";
        std::cout << "\nDigite: 1 -Fazer cadastro\n2 -Fazer Login\n0 - Sair\n\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            Cadastro::cadastro(usuarios, livros, adms, usuarioId, administradorSenha);
        }
        else if (opcao == 2) {
            Login::login(usuarios, livros, adms, usuarioId, administradorSenha);
        }
        else {
            std::cout << "\nErro!!!\n";
        }
    }
}