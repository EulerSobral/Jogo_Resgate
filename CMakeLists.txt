cmake_minimum_required(VERSION 3.25)
project(Jogo_Resgate)

set(CMAKE_CXX_STANDARD 17)

add_executable(Jogo_Resgate main.cpp Sprite.cpp Sprite.h GameBase.h Sprite_base.cpp Sprite_base.h Objeto_de_jogo.cpp Objeto_de_jogo.h Helicoptero.h Fase.cpp Fase.h)
