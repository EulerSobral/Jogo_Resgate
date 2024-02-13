#include "Sprite_base.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

SpriteBase::SpriteBase(vector<string> &s ,int l, int c){
    sprite = s;
    linha = l;
    coluna = c;
}

void SpriteBase::setLinha(int l) {
    linha = l;
}

int SpriteBase::getLinha() {
    return linha;
}

void SpriteBase::setColuna(int c) {
    coluna = c;
}
int SpriteBase::getColuna() {
    return coluna;
}

void SpriteBase::setSprite(vector<string> &s) {
    sprite = s;
}
vector<string> SpriteBase::getSprite(){
    return sprite;
}