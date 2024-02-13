#include "Sprite.h"
#include <iostream>
#include "GameBase.h"
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/*
 Lê “dese0ho” de arquivo passado no construtor
Um Sprite é um std::vector de std::string
Um Sprite deve permitir que outro Sprite seja “desenhado” em uma posição dele
*/


Sprite::Sprite(vector<vector<string>> &m,vector<string> &s, int l, int c) : GameBase(), SpriteBase(s,l,c) {
    matriz = m;
    sprite = s;
    linha = l;
    coluna = c;
}

void Sprite::setMatriz(vector<vector<std::string>> &s) {
    for(int i = 0; i < 80; i++)
        for(int j = 0; j < 80; j++)
            s[i][j] = " ";
    matriz = s;
}
vector<vector<string>> Sprite::getMatriz() {
    return matriz;
}



void Sprite::setSprite(vector<string> &s) {
    sprite = s;
}
vector<string> Sprite::getSprite() const{
    return sprite;
}

void Sprite::setLinha(int l) {
    linha = l;
}
int Sprite::getLinha() {
    return linha;
}

void Sprite::setColuna(int c) {
    coluna = c;
}
int Sprite::getColuna() {
    return coluna;
}


void Sprite::apagarRastro() {
    for(int i = 0; i < 80; i++) {
        for (int j = 0; j < 80; j++)
            for(const string& text: sprite){
                if(matriz[i][j] == text)
                    matriz[i][j] = " ";
            }
    }
}

void  Sprite::DesenhaEm(int l, int c)  {
    setLinha(l);
    setColuna(c);
    for(const string& text: sprite){
        if(matriz[l][c] == " "){
            matriz[l][c] = text;
            l++;
            c++;
        }
    }
}

void Sprite::draw(vector<string> &s, int l , int c) {
    for(const string& text: s){
        matriz[l][c] = text;
        l++;
        c++;
    }
}