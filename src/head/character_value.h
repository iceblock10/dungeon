#pragma once 
#include "raylib.h"
class value_set{
    public:
    int hp;
    int damage; 
    int speed;
    int jump_speed; 
    Vector2 position;
    Vector2 role_Velocity= {0.0f,0.0f};
    int hp_posion=3;
};
