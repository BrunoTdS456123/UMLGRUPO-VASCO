#include "cadastro.hpp"
#include "login.hpp"
#include "usuario.hpp"
#include "livro.hpp"
#include "admnistrador.hpp"

void Cadastro::cadastro(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& usuarioId, std::string admnistradorSenha) {
    std::string nomeUsuario, senha;
    while (true) {
        std::cout << "\n===================================================\n";
        std::cout << "\nInsira o nome de usuario: ";
        std::cin >> nomeUsuario;

        bool existeUser = false;

        for (Usuario* usuario : usuarios) {
            if (usuario->getLogin() == nomeUsuario) {
                existeUser = true;
                break;
            }
        }
        if (existeUser == false) {
            for (Adm* adm : adms) {
                if (adm->getLogin() == nomeUsuario) {
                    existeUser = true;
                    break;
                }
            }
        }
        if (existeUser) {
            std::cout << "\nUsuario ja existente!\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Insira a senha: ";
        std::cin >> senha;

        if (senha == admnistradorSenha) {
            std::cout << "\nErro!!!\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "\nVoce quer cadastrar como um administrador ou como um usuario\n (1 - Administrador, 2 - Usuario): ";
        int opcao;
        std::cin >> opcao;
        if (opcao == 1) {
            bool existeAdm = false;

            for (int i = 0; i < 5; i += 1) {
                std::string codigo;
                std::cout << "Insira o codigo de verificacao: ";
                std::cin >> codigo;
                if (codigo == admnistradorSenha) {
                    int tipo = 1;
                    Adm* adm = new Adm(nomeUsuario, senha, usuarioId, tipo);
                    adms.push_back(adm);
                    std::cout << "\nAdministrador foi cadastrado com exito!!!\n";
                    existeAdm = true;
                    break;
                }
                else {
                    std::cout << "\nErro!!!\n";
                }
            }
            if (existeAdm) {
                break;
            }
            else {
                opcao = 2;
            }

        }
        else if (opcao == 2) {
            int tipo = 2;
            Usuario* usuario = new Usuario(nomeUsuario, senha, usuarioId, tipo);
            usuarios.push_back(usuario);
            std::cout << "\nUsuario cadastrado com exito!!!\n";
            break;
        }
        else {
            std::cout << "\nErro!!!\n";
        }
    }
    usuarioId += 1;

}