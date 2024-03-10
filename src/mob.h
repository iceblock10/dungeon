#pragma once  
#include "raylib.h"
#include "head/frame.h"
#include "head/character_value.h"
#include "track.h"
#include "head/resourse.h"
class mob{
public :
mob();
virtual ~mob();
void update(Vector2 pos_mob ,Vector2 pos_tar); 
void draw(Texture2D Texture,Rectangle framerec, Vector2 role_Position);
void init(Vector2 pos_mob ,Vector2 pos_tar);
private:
track mob_track;
frame running ; 
frame attack; 
frame idle  ; 
frame die;
value_set mob_value ;  
Texture2D idling;
Texture2D run;
Texture2D attacking;
Texture2D death;
protected:
};