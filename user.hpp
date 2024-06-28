#include <iostream>
#include <string>
#include <vector>


using namespace std;

class User{
public:
    User();
    ~User();

    void setNome();
    void setID();
    void setEmail();
    void cadastrar();
    int isAdm();
    void modificarStatusUsuario();
    void pagamentoMulta();
    
private:
    int is_adm;
    int adm_pass = 123;
    int multa = 0;
    int v_multa = 0;
    string id;
    string nome;
    string email;
    string senha;
};