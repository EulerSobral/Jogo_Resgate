/*
 Essa classe vai ter três métodos virtuais puros
 init() -> inicializa o objeto
 update() ->  é destinado a fazer algum processamento na iteração, por exemplo, avançar o passo do SpriteAnimado, ou reduzir combustível do Helicóptero
 draw(screen, x, y) -> desenha o objeto na tela na screen x, y
 * */

#ifndef JOGO_RESGATE_GAMEBASE_H
#define JOGO_RESGATE_GAMEBASE_H

#include <vector>
#include <string>
using std::vector, std::string;

class GameBase {
public:
    GameBase(){}
   virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw(vector<string> &,int , int ) = 0;
};


#endif //JOGO_RESGATE_GAMEBASE_H
