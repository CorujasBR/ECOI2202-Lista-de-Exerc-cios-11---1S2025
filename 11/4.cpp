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

bool letra=false, espaco=false;

arquivo.open("poema.txt", std::ios::in);

if(arquivo.is_open()){
    std::cout<<"Arquivo aberto com sucesso"<<std::endl;
}
    else{
        std::cout<<"Problema pra abrir o arquivo"<<std::endl;
    }

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
           
           for(int i = 0; i < linha.length(); i++){
            if((linha[i]== 't')or(linha[i]== 'T')){
                letra=true;
            }
                if(linha[i]==' '){
                    espaco=true;
                }
                    if((letra==true)and(espaco==true)){
                        quant++;
                        letra =false;
                        espaco=false;
                    }                
           }
        }
    }
    std::cout<<"valor de caracteres "<<quant<<std::endl;

arquivo.close();
}