//
// Created by usuario on 09/06/2023.
//

#include <iostream>
#include <vector>
#include <string>
#include "Objeto_de_jogo.h"
using namespace std;

ObjetoJogo::ObjetoJogo(vector<vector<string>> &m ,vector<string> &o , int cX, int cy) :Sprite(m,o,cX,cy){
}


void ObjetoJogo::setX(int cx){
    x = cx;
}
int ObjetoJogo::getX() {
    return x;
}

void ObjetoJogo::setY(int cy) {
    y= cy;
}
int ObjetoJogo::getY(){
    return y;
}


/*void ObjetoJogo::DesenhaEm(int l, int c)  {

    for(const string& text: obj){
        matriz[l][c] = text;
        l++;
        c++;
    }

}*/

void ObjetoJogo::moveTo(int x, int y) {

    int newX = x;
    int newY = y;

    apagarRastro();
    DesenhaEm(newX, newY);
 //   setMatriz(matriz);
    setX(newX);
    setY(newY);

}

bool ObjetoJogo::colideCom(int l, int c) {
    //usando linha e coluna, é possível descobrir o vértice dos sprites
    //Essa função vai descobrir se um sprite está colidindo com outro sprite
    //Vou usar a lógica da colisão de quadrados

    if(getLinha() == l)
        if(getColuna() == c)
            return true;

    return false;
}