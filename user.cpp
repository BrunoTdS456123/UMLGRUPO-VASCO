#include "user.hpp"
#include <iostream>
#include <string>
#include <vector>


void User::setNome(){
    std::cout<<"Digite seu nome:";
    std::cin>>nome;
}

void User::setID(){
    std::cout<<"Digite sua senha:";
    std::cin>>senha;
}   

void User::setEmail(){
    std::cout<<"Digite seu email:";
    std::cin>>email;
}

void User::cadastrar(){
    setNome();
    setID();
    setEmail();
}

int User::isAdm(){
    int pass;
    cout << "Você é um administrador?" << std::endl;
    cin >> pass;

    if (pass == adm_pass){
        is_adm = 1;
        return is_adm;
    }
    else {
        is_adm = 0;
        return is_adm;
    }
}

void User::pagamentoMulta(){
    multa = 0;
}
void User::modificarStatusUsuario(){
    if(multa==0){
        cout<<"Status da multa do Usuario:Pago";
    }
    else if (multa>0)
    {
        cout<<"Status da multa do Usuario:A pagar"<<multa;
        std::cout<<"Digite 1 para pagar a multa ou 2 para sair da operaçao:";
        std::cin>>v_multa;
        if(v_multa==1){
            void pagamentoMulta();
        }
    }
    
}