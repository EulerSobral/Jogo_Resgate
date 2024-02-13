//
// Created by usuario on 09/06/2023.
//

#ifndef JOGO_RESGATE_OBJETO_DE_JOGO_H
#define JOGO_RESGATE_OBJETO_DE_JOGO_H

#include <iostream>
#include <vector>
#include <string>
#include "Sprite.h"
#include "Sprite_base.h"
#include "GameBase.h"

class ObjetoJogo : public  Sprite{


public:
    //Dois construtores,um construtor com o sprite estático e outro com o sprite animado

   ObjetoJogo(vector<vector<string>> &,vector<string>& ,int, int );
    bool colideCom(int, int); //verifica se um objeto vai colidir com outro objeto
    void moveTo(int , int); //move os objetos na tela

    void setX(int);
    int getX();

    void setY(int);
    int getY();

    void init() { }
    virtual void update(){}

private:
    int x, y,linha, coluna;
    bool ativo;
    vector<vector<string>> matriz;
    vector<string> obj;
};


#endif //JOGO_RESGATE_OBJETO_DE_JOGO_H
