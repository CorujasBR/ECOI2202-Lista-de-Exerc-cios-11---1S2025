#include<iostream>
#include<fstream>

void verifica();

int main(){
    verifica();

    return 0;
}

void verifica(){
std::ifstream arquivo;
std::string linha;
int quant = 0;
arquivo.open("poema.txt", std::ios::in);

if(arquivo.is_open()){
    std::cout<<"Arquivo aberto com sucesso"<<std::endl;
}
    else{
        std::cout<<"Problema pra abrir o arquivo"<<std::endl;
    }

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            std::cout<< linha<<std::endl;
            quant = quant + linha.length();
        }
    }
    std::cout<<"valor de caracteres "<<quant<<std::endl;

arquivo.close();
}