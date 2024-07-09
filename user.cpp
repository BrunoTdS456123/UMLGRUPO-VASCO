#include <iostream>
#include <string>
#include <vector>
#include "user.hpp"
#include "emprestimo.hpp"
#include "livro.hpp"

//costrutor e destrutor

User::User(std::string _login, std::string _senha, int _id, int _tipo) {
    login = _login;
    senha = _senha;
    id = _id;
    multa = 0;
    status = true;
    tipo = _tipo;
}

User::~User() {

}

//get

int User::getTipo() {
    return tipo;
}

float User::getMulta() {
    return multa;
}

int User::getId() {
    return id;
}

std::string User::getLogin() {
    return login;
}

std::string User::getSenha() {
    return senha;
}

//set

void User::setLoginSenha(std::string _login, std::string _senha) {
    senha = _senha;
    login = _login;
}

void User::setMulta(float _multa) {
    multa = _multa;
}

void User::setStatus(bool _status) {
    status = _status;
}

void User::exibirDados(std::vector<Livro*>& livros) {
    std::cout << "\n---------------------------\n";
    std::cout << "\nLogin: " << login << std::endl;
    std::cout << "Multa: " << multa << std::endl;

    if (emprestimos.size() > 0) {
        std::cout << "\nLivros emprestados: " << std::endl;
        for (Emprestimo* emprestimo : emprestimos) {
            int id = emprestimo->getIdLivro();
            std::cout << "\n" << livros[id]->getTitulo() << ", ID: " << id + 1 << std::endl;
            std::cout << "Data de emprestimo: " << emprestimo->mostrarDataEmprestimo();
            std::cout << "Data de devolucao: " << emprestimo->mostrarDataDevolucao();
            if (livros[id]->getStatus()) {
                std::cout << "!!Devolvido!!\n";
            }
        }
    }
    std::cout << "\n";
}

void User::emprestarLivro(std::vector<Livro*>& livros) {
    if (multa > 300) {
        std::cout << "\nUsuário bloqueado por excesso de multa\n";
        return;
    }
    int id = livrosDisponiveis(livros);
    Emprestimo* emprestimo = new Emprestimo(id);
    emprestimos.push_back(emprestimo);
}

void User::calcMulta() {
    multa = 0;
    for (Emprestimo* emprestimo : emprestimos) {
        multa += emprestimo->calcMulta();
    }
    setMulta(multa);
}

void User::devolverLivro(std::vector<Livro*>& livros) {
    int op;
    bool devolvido = false;
    std::cout << "\n---------------------------\n";
    std::cout << "\nLivros emprestados: \n\n";
    for (Emprestimo* emprestimo : emprestimos) {
        int id = emprestimo->getIdLivro();
        std::cout << livros[id]->getTitulo() << ", ID: " << id + 1 << std::endl;
    }
    std::cout << "\nDigite o ID de um livro para devolver: ";
    std::cin >> op;
    for (Emprestimo* emprestimo : emprestimos) {
        if (op - 1 == emprestimo->getIdLivro()) {
            livros[op - 1]->setStatus(true);
            devolvido = true;
            break;
        }
    }
    if (devolvido == false) {
        std::cout << "\nID invalido\n";
    }
    return;
}

void User::pagarMulta() {
    float valor;
    std::cout << "\nDigite o valor que deseja pagar: ";
    std::cin >> valor;
    multa -= valor;
    if (multa < 0) {
        multa = 0;
    }
    std::cout << "\nMulta paga com sucesso\n";
}

int User::livrosDisponiveis(std::vector<Livro*>& livros) {
    int nLivro;
    std::cout << "\n---------------------------\n";
    std::cout << "\nEscolha um livro e digite seu ID\n\n";
    for (int i = 0; i < livros.size(); i++) {
        Livro* livro = livros[i];
        bool status = livros[i]->getStatus();
        if (status) {
            std::cout << "Livro: " << livro->getTitulo() << ", ID: " << livro->getId() + 1 << ", Autor: " << livro->getAutor() << ", Ano: " << livro->getAno() << std::endl;
        }
    }
    std::cout << "\nSua escolha: ";
    std::cin >> nLivro;
    if (nLivro > livros.size() || nLivro < 0) {
        std::cout << "\nID inválido\n";
        return -1;
    }
    int id = livros[nLivro - 1]->getId();
    livros[nLivro - 1]->setStatus(false);
    return id;
}

void User::opcoesUsuario(std::vector<Livro*>& livros, std::vector<User*>& users) {
    int opcao;

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\n1 - Emprestar livro\n2 - Devolver livro\n3 - Pagar multa\n4 - Exibir dados\n0 - Sair\n\nSua opçao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            emprestarLivro(livros);
        }
        else if (opcao == 2) {
            devolverLivro(livros);
        }
        else if (opcao == 3) {
            pagarMulta();
        }
        else if (opcao == 4) {
            exibirDados(livros);
        }
        else if (opcao == 5) {
            autoDeletar(users);
        }
        else if (opcao == 0) {
            break;
        }
        else {
            std::cout << "\nOpção invalida\n";
        }
    }
}

void User::autoDeletar(std::vector<User*>& users) {
    for (auto it = users.begin(); it != users.end(); ) {
        if (*it == this) {
            it = users.erase(it);
            delete this;
            break;
        }
        else {
            ++it;
        }
    }
}