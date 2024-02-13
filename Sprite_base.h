

/*
    Essa classe vai conter um método virtual que vai ser utilizado por sprite
  */
#ifndef JOGO_RESGATE_SPRITE_BASE_H
#define JOGO_RESGATE_SPRITE_BASE_H

#include <string>
#include <vector>
using namespace std;

class SpriteBase {
    public:
        SpriteBase(){}
        SpriteBase(vector<string> & ,int, int);

        void setSprite(vector<string> &s);
        vector<string> getSprite();

        virtual void DesenhaEm(int, int) = 0;

        void setColuna(int);
        int getColuna();

        void setLinha(int);
        int getLinha();

    private:
            vector<string> sprite;
            int linha, coluna;

};


#endif //JOGO_RESGATE_SPRITE_BASE_H
