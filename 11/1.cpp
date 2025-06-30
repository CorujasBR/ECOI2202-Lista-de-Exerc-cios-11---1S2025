#include<iostream>
#include<fstream>

int main(){
std::ofstream arquivo;//criar a variavel que vai receber os textos pro arquivo

setlocale(LC_ALL, "Portuguese");//pro portugues n ficar torto

arquivo.open("poema.txt", std::ios::out);//abrir ou criar o arquivo

if(arquivo.is_open()){//verificar se o arquivo foi aberto
std::cout<<"Arquivo abeto com sucusso!"<<std::endl;//avisar se foi aberto
}
    else{
        std::cout<<"Erro do processo"<<std::endl;//avisar se deu erro
        return 0;
    }

    

     arquivo<< "Pedro Pedreiro"<<std::endl;
    arquivo<< "Pensa na vida a passar"<<std::endl;
    arquivo<< "Pensa na morte que vem"<<std::endl;
    arquivo<< "Pensa na vida que tem"<<std::endl;
    arquivo<< "Pensa na morte que vem"<<std::endl;
    arquivo<< "Pensa na vida que tem"<<std::endl;
    arquivo<< "Razão de sobra pra se acabar"<<std::endl;

    arquivo.close();//pra fechar o arquivo
return 0;
}