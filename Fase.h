//
// Created by usuario on 19/06/2023.
//

#ifndef JOGO_RESGATE_FASE_H
#define JOGO_RESGATE_FASE_H

#include "Objeto_de_jogo.h"
#include <vector>
#include <string>

class Fase : public ObjetoJogo{

public:
    Fase(vector<vector<string>> &,vector<string>& ,int, int);

    friend ostream &operator<<(const ostream &, const Fase &);
    string printFim();
    void run();
    void init();
    void show();
    void update();
private:
    int l,c;
    vector<vector<string>> matriz;
    vector<string> obj;
};


#endif //JOGO_RESGATE_FASE_H
