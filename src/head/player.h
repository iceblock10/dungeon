#include "raylib.h"
#include "head/character_value.h"
#include"head/frame.h"
#include"head/resourse.h"
#pragma once 
class player{
    public:
    player();
    virtual ~player();
    virtual bool update(bool onground);
    virtual void draw (); 
    virtual void goUp();
	virtual void goLeft();
	virtual void goRight();
	virtual void goNowhere();
    virtual void doInteractWith();
    virtual bool attack();
    private: 
    bool at_ground ;
    frame idle_f;
    frame attack_f;
    frame run_f;
    frame jump_f;
    frame roll_f;
    frame died_f; 
    value_set player_value;
    protected:  
};