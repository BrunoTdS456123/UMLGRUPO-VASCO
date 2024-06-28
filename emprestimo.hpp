#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Emprestimo{
    public:
    Emprestimo();
    ~Emprestimo();
    
    float Registro();

    private:
        int data_loc;
        int data_dev; 
        int id_livro;
        
};
