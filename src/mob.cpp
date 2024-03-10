/*#include "mob.h"
int screenHeight =GetScreenHeight();
int screenWidth = GetScreenWidth();
const int groundy= (3 * screenHeight) / 4;
int gravity=1;
mob::mob(){

};
mob::~mob(){

}
void mob::init(Vector2 pos_mob ,Vector2 pos_tar){
  mob_track.traget_pos= pos_tar;
  mob_track.limit_range.x=360;
  mob_track.limit_range.y=795;
  update(pos_mob,pos_tar);
};
void mob::update(Vector2 pos_mob ,Vector2 pos_tar){
draw();//die 
draw();//attack
draw(idling,idle.frameRec,pos_mob);//idle
//draw();//walk
};
void mob::draw(Texture2D Texture,Rectangle framerec, Vector2 mob_Position){
DrawTextureRec(Texture,framerec,mob_Position,WHITE);
};*/
/*
Texture2D idling_sket=LoadTexture(skeleton_idle);
void init_sket(Vector2 pos){
	frame idle_sket;
	idle_sket.numFrames=11;
	idle_sket.frameWidth=idling_sket.width/idle_sket.numFrames;
	idle_sket.frameIndex=0;
	idle_sket.frameDelayCounter=0;
	idle_sket.frameDelay=5;
	idle_sket.frameRec={0.0f,0.0f,(float)idle_sket.frameWidth,(float)idling_sket.height};
}*/