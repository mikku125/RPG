#include<iostream>
#include<string>
#include "game.hpp"
#include "hero.hpp"

int main() {
    RPG::Game game;
    game.startGame();
    RPG::Hero hero("mars",0,0,1,10);
    RPG::MapObject mobject("chest",0,5,false);
    RPG::Object *object = new RPG::MapObject;
    object->info();
    mobject.info();
    hero.info();
}
