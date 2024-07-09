#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <vector>
#include <iostream>
#include <string>

class Livro;
class Emprestimo;

class User {

public:

    User(std::string _login, std::string _senha, int _id, int _tipo);

    ~User();

    //get

    int getTipo();

    float getMulta();

    int getId();

    std::string getLogin();

    std::string getSenha();

    //set

    void setLoginSenha(std::string _login, std::string _senha);

    void setMulta(float _multa);

    void setStatus(bool _status);

    //funcoes

    void exibirDados(std::vector<Livro*>& livros);

    void emprestarLivro(std::vector<Livro*>& livros);

    void calcMulta();

    void devolverLivro(std::vector<Livro*>& livros);

    void pagarMulta();

    int livrosDisponiveis(std::vector<Livro*>& livros);

    void opcoesUsuario(std::vector<Livro*>& livros, std::vector<User*>& users);

    void autoDeletar(std::vector<User*>& users);

private:

    std::string senha, login;
    float multa;
    bool status;
    std::vector<Emprestimo*> emprestimos;
    int id, tipo;
};

#endif