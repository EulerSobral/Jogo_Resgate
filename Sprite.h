 //
// Created by usuario on 31/05/2023.
//

#ifndef JOGO_RESGATE_SPRITE_H
#define JOGO_RESGATE_SPRITE_H

#include <iostream>
#include <vector>
#include <string>
#include "GameBase.h"
#include "Sprite_base.h"
using namespace std;

class Sprite: public SpriteBase, GameBase {
public:
    Sprite(){}
    Sprite(vector<vector<string>> &m,vector<string> &s, int l, int c);

    void setMatriz(vector<vector<string>> &);
    vector<vector<string>> getMatriz();

   void setSprite(vector<string> &s);
   vector<string> getSprite() const;

    void setLinha(int);
    int getLinha();

    void setColuna(int);
    int getColuna();

    void apagarRastro();

    void DesenhaEm(int, int);
    void draw(vector<string> &,int , int );
    void init(){}
    void update(){}
private:
    vector<string> sprite;
    vector<vector<string>> matriz;
    int linha, coluna;
};



#endif //JOGO_RESGATE_SPRITE_H
