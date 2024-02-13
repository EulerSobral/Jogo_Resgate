//
// Created by usuario on 19/06/2023.
//

#include "Fase.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
using namespace std;





Fase::Fase(vector<vector<string>> &m,vector<string>&s ,int l, int c) : ObjetoJogo(m,s,l,c){}

ostream &operator<<(ostream &out, Fase &t){
    out << t.printFim();
    return out;
}

string Fase::printFim(){
    system("clear");
    system("cls");
    return "End Game!";
}

void Fase::update() {
    vector<vector<string>> matriz(80, vector<string>(80));
    setMatriz(matriz);
}
void Fase::run() {
    ifstream arquivo("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\personagem.txt", ios::in);
    vector<string> dado, dado_vazio;
    if(arquivo.is_open()){
        string text;
        while (getline(arquivo, text)) {
            dado.push_back(text);
        }
        for(int i = 0; i < dado.size(); i++)
            dado_vazio.push_back(" ");
        arquivo.close();
    }

    ifstream arquivo3("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\ilha.txt", ios::in);
    vector<string> dado3;
    if(arquivo3.is_open()){
        string txt;
        while (getline(arquivo3, txt))
            dado3.push_back(txt);
        arquivo3.close();
    }
    ifstream arquivo4("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\rescue_base.txt", ios::in);
    vector<string> dado4;
    if(arquivo4.is_open()){
        string txt;
        while (getline(arquivo4, txt))
            dado4.push_back(txt);
        arquivo4.close();
    }
    ifstream arquivo5("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\gasolina.txt", ios::in);
    vector<string> dado5;
    if(arquivo5.is_open()){
        string txt;
        while (getline(arquivo5, txt))
            dado5.push_back(txt);
        arquivo5.close();
    }
    DesenhaEm(40,0);
    draw(dado5, 40, 40);
    draw(dado3, 58, 40);
    draw(dado3, 58, 10);
    draw(dado4, 70, 0);
    draw(dado, 55, 65);
    draw(dado,55,55);
    draw(dado, 55, 25);
    draw(dado,55,45);
    draw(dado, 55, 15);
    show();
    int qtdResgatados = 0, carga = 0, combustivel = 100, qtdPassageiros = 0;
    while (1){
        string dado;
        getline(std::cin, dado);
        combustivel--;
        if(combustivel <= 0){
            system("cls");
            cout << "Mission Failed!";
            break;
        }

        if(dado == "s" || dado == "S"){
            try{
                moveTo(Sprite::getLinha() + 5, Sprite::getColuna());
            }catch (const out_of_range& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            } catch (const exception& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            }
        } else if(dado == "w" || dado == "W"){
            try{
                moveTo(Sprite::getLinha() - 5, Sprite::getColuna());
            }catch (const out_of_range& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            }catch (const exception& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            }
        } else if(dado == "d" || dado == "d"){
            try{
                moveTo(Sprite::getLinha(), Sprite::getColuna() + 5);
            }catch (const out_of_range& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            }catch (const exception& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            }
        } else if(dado == "a" || dado == "A"){
            try{
                moveTo(Sprite::getLinha(), Sprite::getColuna() - 5);
            }catch (const out_of_range& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            }catch (const exception& e){
                cout << "Infelizmente você não pode ir para essa posição!" << endl;
                continue;
            }
        } else if(dado == "x" || dado == "X"){
            if(colideCom(55, 15) == true || colideCom(55, 25) == true || colideCom(55, 45) == true || colideCom(55, 55) == true || colideCom(55, 65) == true ){
                if(carga < 300 && qtdPassageiros < 4){
                    qtdResgatados++;
                    qtdPassageiros++;
                    carga+=50;
                    cout << "Passageiro esta no helicoptero!" << endl;
                    if (colideCom(55, 15) == true) {
                        draw(dado_vazio, 55, 15);
                    }
                    else if( colideCom(55, 25) == true) {
                        draw(dado_vazio, 55, 25);
                    }else if(colideCom(55, 45) == true) {
                        draw(dado_vazio, 55, 45);
                    }else if(colideCom(55, 55) == true) {
                        draw(dado_vazio, 55, 55);
                    }else if(colideCom(55, 65) == true){
                        draw(dado_vazio, 55, 65);
                    }
                }
                continue;
            }  else if(colideCom(70, 0) == true){
                if(qtdResgatados == 5){
                    system("clear");
                    system("cls");
                    cout << "Level Complete!";
                    break;
                } else if(qtdResgatados >= 1 && qtdResgatados < 5){
                    cout << "Passageiro esta na base!" << endl;
                    int descarga = qtdResgatados * 50;
                    carga-=descarga;
                    qtdPassageiros-=qtdResgatados;
                }
                continue;

            } else if(colideCom(40, 40) == true){
                if(combustivel <= 50) {
                    combustivel += 50;
                    draw(dado_vazio, 40, 40);
                }
            } else{
                continue;
            }
        }
        system("clear");
        system("cls");
        show();
        cout << endl << "Combustivel: " << combustivel << " Peso: " << carga <<" Quantidade de passageiros: " << qtdPassageiros << " Quantidade de Resgatados: " << qtdResgatados;
    }

}

void Fase::show() {
    for (const auto& row : getMatriz()) {
        for (const auto& element : row) {
            cout << element;
        }
        cout << endl;
    }

}

void Fase::init() {
    ifstream helicoptero_menu("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\helicoptero_menu.txt", ios::in);
    vector<string> hel_me;
    if(helicoptero_menu.is_open()){
        string text;
        while (getline(helicoptero_menu, text)) {
            hel_me.push_back(text);
        }
        helicoptero_menu.close();
    }
    draw(hel_me, 60, 50);
    show();
    string entrada;
    cout << "Aperte a tecla Enter para iniciar o jogo! " << endl << "Aperta a tecla Q para sair do jogo!";
    cout << "Aperta tecla: ";
    getline(std::cin, entrada);
    if(entrada == "q" || entrada == "Q")
        return;
    else {
        system("cls");
        system("clear");
        update();
        run();
    }
}
