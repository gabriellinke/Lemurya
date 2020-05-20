#pragma once
#include "Menu.h"

class MenuPause: public Menu
{
private:

public:
    MenuPause(Lemurya* jogo);
    ~MenuPause();

    //M�todos de State
    void draw();
    void input();
    void update();

    void inicializar();
    void voltarAoMenu();
    void voltarAFase();
};
