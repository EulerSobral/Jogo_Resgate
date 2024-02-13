#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include "Sprite.h"
#include "Fase.h"
#include "Objeto_de_jogo.h"
using namespace std;


int main() {

    /*ifstream arquivo2("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\helicoptero.txt", ios::in);
    vector<string> dado2;
    if(arquivo2.is_open()){
        string txt;
        while (getline(arquivo2, txt))
            dado2.push_back(txt);
        arquivo2.close();
    }

    vector<vector<string>> matriz(80, vector<string>(80));

    Fase f(matriz, dado2, 5,4); // O parametro linha e coluna é o mesmo de desenhaEm
    f.init();
     */

    ifstream arquivo("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\personagem.txt", ios::in);
    vector<string> dado;
    if(arquivo.is_open()){
        string text;
        while (getline(arquivo, text)) {
            dado.push_back(text);
        }

        arquivo.close();
    }

    ifstream arquivo2("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\helicoptero.txt", ios::in);
    vector<string> dado2;
    if(arquivo2.is_open()){
        string txt;
        while (getline(arquivo2, txt))
            dado2.push_back(txt);
        arquivo2.close();
    }
    ifstream arquivo3("C:\\Users\\usuario\\CLionProjects\\Jogo_Resgate\\imagens\\ilha.txt", ios::in);
    vector<string> dado3;
    if(arquivo3.is_open()){
        string txt;
        while (getline(arquivo3, txt))
            dado3.push_back(txt);
        arquivo3.close();
    }
    vector<vector<string>> matriz(80, vector<string>(80));
    Fase F(matriz, dado2, 5,4);
    F.init();
    cout << F.printFim();

    /*for (const auto& row : O.getMatriz()) {
        for (const auto& element : row) {
            std::cout << element;
        }
        std::cout << std::endl;
    }*/
    /*if(O.colideCom(8,5) == true)
        cout << "Deu certo 1!" << endl;
    else if(O.colideCom(0,1) == true)
        cout << "Deu certo 2!" << endl;
    else if(O.colideCom(0, 10) == true)
        cout << "Deu certo 3!" << endl;*/
    return 0;
}
