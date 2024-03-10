/*******************************************************************************************
*
*   RayLib 2D Challenge - An animated character
*
*   @author Hans de Ruiter
*
*   @copyright (c) 2022 by Kea Sigma Delta Limited, all rights reserved
*
*   License:
*   This software is provided 'as-is', without any express or implied warranty. In no event 
*   will the authors be held liable for any damages arising from the use of this software.
*   
*   Permission is granted to anyone to use this software for any purpose, including 
*   commercial applications, and to alter it and redistribute it freely, subject to the 
*   following restrictions:
*   
*   1. The origin of this software must not be misrepresented; you must not claim that you 
*   wrote the original software. If you use this software in a product, an acknowledgment 
*   in the product documentation would be appreciated but is not required.
*   
*   2. Altered source versions must be plainly marked as such, and must not be misrepresented 
*   as being the original software.
*   
*   3. This notice may not be removed or altered from any source distribution.
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>
#include "head/resourse.h"
#include"head/frame.h"
#include "head/character_value.h"

bool isTextureValid(const Texture2D *texture) {
	return texture->id > 0;
}
    const int screenWidth = 1600;
    const int screenHeight = 900;
	const int groundy= (3 * screenHeight) / 4;
bool on_ground(Texture2D *scarfy, Vector2 *scarfyPosition) {
	if(scarfyPosition->y + scarfy->height >= groundy) {
		return true;
	}
	 else {
		return false;
	}
}
int colddown=10;
frame slime;
value_set smile_value;
value_set player;
frame player_roll;
const int gravity=1;
Rectangle groundbox1={410,515,135,50};
Rectangle groundbox2={530,529,61,50};
Rectangle groundbox3={585,547,120,50};
	int delaycount=0;
		int delay=10;
	int	damage_count=0;
struct Skeleton  
{
Vector2 enemy_pos={500,groundy-33};
int enemy_hp=50;
int enemy_damage=2;
int speed=6;
Vector2 velocity={0.0f,0.0f};
frame idle; 
frame run;
frame death; 
frame attack; 
bool mob_damge_ch=false;
bool mob_moving=false;
bool mob_attack=false;
bool dead=false; 
Rectangle enemy={enemy_pos.x,enemy_pos.y,25,50};
Rectangle attack_box={enemy_pos.x+20,enemy_pos.y,25,50};
};
struct undead   
{
bool direct=false;
int delaycount=0;
int delay=10;
int total_frame=22;
Vector2 enemy_pos={600,groundy-150};
int enemy_hp=150;
int enemy_damage=5;
int speed=6;
Vector2 velocity={0.0f,0.0f};
frame idle; 
frame run;
frame death; 
frame attack; 
frame summon;
frame skill;
bool mob_damge_ch=false;
bool mob_moving=false;
bool mob_attack=false;
bool dead=false; 
Rectangle enemy={enemy_pos.x+100,enemy_pos.y+75,80,80};
Rectangle attack_box={enemy_pos.x+20,enemy_pos.y,70,80};
};

int main(void)
{
	undead boss;
	Skeleton sket;
    // Initialization
    //--------------------------------------------------------------------------------------
	player.hp=100;
	player.damage=10;
	 int role_Speed = 2;
	 bool rolling=false;
    InitWindow(screenWidth, screenHeight, "testing");
	InitAudioDevice();
	Texture2D boss_attack=LoadTexture(smile_attacking);
	Texture2D boss_run=LoadTexture(smile_running);
	Texture2D boss_idle=LoadTexture(smile_idling);
	Texture2D boss_death=LoadTexture(smile_dead);
	Texture2D sket_dead=LoadTexture(Skeleton_dead);
	Texture2D sket_run=LoadTexture(skeleton_run);
	Texture2D sket_idle=LoadTexture("Skeleton/Sprite Sheets/Skeleton Idle.png");
	Texture2D sket_attack=LoadTexture("Skeleton/Sprite Sheets/Skeleton Attack.png");
	Sound att_s=LoadSound("sound_effect/mixkit-dagger-woosh-1487.wav");
	Sound bgm_s=LoadSound("sound_effect/bgm.wav");
	Sound footstep=LoadSound("sound_effect/footstep.wav");
	Texture2D lv1=LoadTexture("map/stage 1 level1.png");
	Texture2D lv2=LoadTexture("map/lv2.png");
	Texture2D background=LoadTexture("map/map.png");
	Texture2D bossfight=LoadTexture("map/bossfight.png");
	Texture2D role = LoadTexture(role_run);
	Texture2D at=LoadTexture(role_attack);
	Texture2D st=LoadTexture(role_stand);
	Texture2D roll=LoadTexture(role_roll);
	Texture2D roled=LoadTexture(role_dead);
	frame role_death;
//
	sket.idle.numFrames=11;
	sket.idle.frameDelayCounter=0;
	sket.idle.frameIndex=0;
	sket.idle.frameDelay=5;
	sket.idle.frameWidth=sket_idle.width/sket.idle.numFrames;
	sket.idle.frameRec={0.0f,0.0f,(float)sket.idle.frameWidth,(float)sket_idle.height};
	sket.run .numFrames=13;
	sket.run.frameDelayCounter=0;
	sket.run.frameIndex=0;
	sket.run.frameDelay=2;
	sket.run.frameWidth=sket_run.width/sket.run.numFrames;
	sket.run.frameRec={0.0f,0.0f,(float)sket.run.frameWidth,(float)sket_run.height};
	sket.death.numFrames=15;
	sket.death.frameDelayCounter=0;
	sket.death.frameIndex=0;
	sket.death.frameDelay=3;
	sket.death.frameWidth=sket_dead.width/sket.death.numFrames;
	sket.death.frameRec={0.0f,0.0f,(float)sket.death.frameWidth,(float)sket_dead.height};
	sket.attack.numFrames=18;
	sket.attack.frameDelayCounter=0;
	sket.attack.frameIndex=0;
	sket.attack.frameDelay=3;
	sket.attack.frameWidth=sket_attack.width/sket.attack.numFrames;
	sket.attack.frameRec={0.0f,0.0f,(float)sket.attack.frameWidth,(float)sket_attack.height};
	bool direct=true;
////////////////////////////////////////////////////////////////	
	boss.idle.numFrames=6;
	boss.idle.frameDelayCounter=0;
	boss.idle.frameIndex=0;
	boss.idle.frameDelay=5;
	boss.idle.frameWidth=(boss_idle.width/boss.total_frame);
	boss.idle.frameRec={0.0f,0.0f,(float)boss.idle.frameWidth,(float)boss_idle.height};	
	boss.death.numFrames=22;
	boss.death.frameDelayCounter=0;
	boss.death.frameIndex=0;
	boss.death.frameDelay=5;
	boss.death.frameWidth=(boss_death.width/boss.total_frame);
	boss.death.frameRec={0.0f,0.0f,(float)boss.death.frameWidth,(float)boss_death.height};	
	boss.run.numFrames=12;
	boss.run.frameDelayCounter=0;
	boss.run.frameIndex=0;
	boss.run.frameDelay=5;
	boss.run.frameWidth=(boss_run.width/boss.total_frame);
	boss.run.frameRec={0.0f,0.0f,(float)boss.run.frameWidth,(float)boss_run.height};	
	boss.attack.numFrames=14;
	boss.attack.frameDelayCounter=0;
	boss.attack.frameIndex=0;
	boss.attack.frameDelay=3;
	boss.attack.frameWidth=(boss_attack.width/boss.total_frame);
	boss.attack.frameRec={0.0f,0.0f,(float)boss.attack.frameWidth,(float)boss_attack.height};	
	///
	role_death.numFrames=10;
	role_death.frameDelayCounter=0;
	role_death.frameIndex=0;
	role_death.frameDelay=5;
	role_death.frameWidth=(roled.width/role_death.numFrames);
	role_death.frameRec={0.0f,0.0f,(float)role_death.frameWidth,(float)roled.height};	
	
	
////////////////////////////////////////////////////////////////	
bool role_dead=false;

	int  press_delay_count=10;
	int press_delay=0;
	unsigned numFrames = 10;
	unsigned frameDelay = 5;
	unsigned frameDelayCounter = 0;
	unsigned frameIndex = 0;
	unsigned stnumFrames = 10;
	unsigned stframeDelay = 3;
	unsigned stframeDelayCounter = 0;
	int stframeWidth = role.width / numFrames;
	Rectangle stframeRec = { 0.0f, 0.0f, (float)stframeWidth, (float)role.height };
	unsigned stframeIndex = 0;
	int frameWidth = role.width / numFrames;
	Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)role.height};
	Vector2 role_Position = {screenWidth / 2.0f-420, 519};
    Vector2 role_Velocity = {0.0f,0.0f};
	bool role_attack=false;
	bool damage_ch=false;
	Rectangle attframeRec = { 0.0f, 0.0f, (float)frameWidth, (float)at.height };
	unsigned attframeDelay = 3;
	unsigned attframeDelayCounter = 0;
	unsigned attframeIndex = 0;
	player_roll.numFrames=12;
	player_roll.frameWidth=roll.width/player_roll.numFrames;
	player_roll.frameRec={ 0.0f, 0.0f, (float)frameWidth, (float)role.height };
	player_roll.frameDelayCounter=0;
	player_roll.frameDelay=2;
	player_roll.frameIndex=0;
	 Camera2D camera = { 0 };
    camera.target = (Vector2){ role_Velocity.x + 20.0f, role_Velocity.y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 5.0f;
    SetTargetFPS(60);
	int switch_=-1;
	int time=1;
	////////////////////////////////////////////////////////////////
    //------------------
    // Main game loop
	PlaySound(bgm_s);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {if(switch_==-1&&IsKeyDown(KEY_ENTER))switch_++;
	if(player.hp<=0)role_dead=true;
	if(switch_==1&&time==1){sket.enemy_pos.x=600;sket.enemy_hp=50;
	sket.dead=false;time--;
	sket.death.frameIndex=0;sket.mob_attack=false;}
damage_ch=false;
damage_count++;
	bool ground_ch=on_ground(&role,&role_Position);
		// Update
		Rectangle hitbox_attack={role_Position.x+65,role_Position.y+40,(float)frameWidth-65,(float)role.height-40};
		Rectangle hitbox_player={role_Position.x+45,role_Position.y+40,(float)frameWidth-100,(float)role.height-40};
		if( CheckCollisionRecs(hitbox_player,groundbox1)  || CheckCollisionRecs(hitbox_player,groundbox2)   || CheckCollisionRecs(hitbox_player,groundbox3)         )ground_ch=true;
	if(switch_>-1){
		if(ground_ch) {
		press_delay++;
	if(!role_dead){ if(IsKeyDown(KEY_SPACE)&&player.hp_posion>0&&press_delay>press_delay_count){
		press_delay=0;
		player.hp_posion--;
		player.hp+=20;
		if(player.hp>100)player.hp=100;
	 }
		if(role_Position.x==795&&IsKeyDown(KEY_ENTER)){switch_++;role_Position.x=screenWidth / 2.0f-420;}
	
		if (IsKeyDown(KEY_D) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
			role_Velocity.x = role_Speed;
			if(frameRec.width < 0) {
				frameRec.width = -frameRec.width;
				stframeRec.width = -stframeRec.width;
				attframeRec.width = -attframeRec.width;
				player_roll.frameRec.width=-player_roll.frameRec.width;
				role_death.frameRec.width=-role_death.frameRec.width;
			}
			if(IsKeyDown(KEY_L)){
				role_Velocity.x = role_Speed+1;
					frameDelay=3;
					rolling=true;
			}
			else{
				frameDelay=5;
			}

        } else if (IsKeyDown(KEY_A) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
			role_Velocity.x = -role_Speed;
			if(frameRec.width > 0) {
				stframeRec.width = -stframeRec.width;
				frameRec.width = -frameRec.width;
				attframeRec.width = -attframeRec.width;
				player_roll.frameRec.width=-player_roll.frameRec.width;
				role_death.frameRec.width=-role_death.frameRec.width;
			}
				if(IsKeyDown(KEY_L)){
				role_Velocity.x =-( role_Speed+1);
					frameDelay=3;
					rolling=true;
			}
			else{
				frameDelay=5;
			}
		}else if(IsKeyDown(KEY_J)){
			role_attack=true;

	if(damage_count>colddown) 		
{damage_ch=true;
	damage_count=0;
}
        } 
        else {
			role_Velocity.x = 0;
		}
		}
	}	}	
		bool scarfyMoving = role_Velocity.x != 0.0f || role_Velocity.y != 0.0f;
		role_Position = Vector2Add(role_Position, role_Velocity);
		if(role_Position.x>795)role_Position.x=795;
		if(role_Position.x<360)role_Position.x=360;
	hitbox_attack={role_Position.x+65,role_Position.y+40,(float)frameWidth-65,(float)role.height-40};
	 hitbox_player={role_Position.x+45,role_Position.y+40,(float)frameWidth-100,(float)role.height-40};
		if(role_Velocity.x<0||frameRec.width<0){
			hitbox_player={role_Position.x+55,role_Position.y+40,(float)frameWidth-100,(float)role.height-40};
		    hitbox_attack={role_Position.x,role_Position.y+40,(float)frameWidth-65,(float)role.height-40};
		}
		ground_ch=on_ground(&role,&role_Position);
		
		//================================================================
		if( CheckCollisionRecs(hitbox_player,groundbox1)  || CheckCollisionRecs(hitbox_player,groundbox2)   || CheckCollisionRecs(hitbox_player,groundbox3)         )ground_ch=true;
		if(ground_ch) {
			role_Velocity.y = 0;
			if(CheckCollisionRecs(hitbox_player,groundbox1) )role_Position.y = 516- role.height;
			else if(CheckCollisionRecs(hitbox_player,groundbox2) )role_Position.y = 530 - role.height;
			else if(CheckCollisionRecs(hitbox_player,groundbox3) )role_Position.y =550- role.height;
			else  role_Position.y = groundy - role.height;
			
		} else {
		 		  role_Velocity.y += gravity;
		}
		/////////////////////////////////////////////////////////////////////////////////////
		if(sket.mob_attack==false)sket.attack.frameIndex=0;
		if(boss.mob_attack==false)boss.attack.frameIndex=0;
		if(damage_ch&&CheckCollisionRecs(sket.enemy,hitbox_attack)){
			sket.enemy_hp-=10;
			if(sket.enemy_hp<=0){sket.enemy_hp=0;sket.dead=true;
			if(switch_==1)(sket.enemy_pos.y=groundy-sket_dead.height)+2;
			else boss.enemy_pos.y=groundy-sket_dead.height+3;
			}
		}
		if(switch_==2&&damage_ch&&CheckCollisionRecs(boss.enemy,hitbox_attack)){
	 	boss.enemy_hp-=10;
			if(boss.enemy_hp<=0){
				boss.enemy_hp=0;boss.dead=true;boss.enemy_pos.y=groundy-115; 
			
			}

		}
		delaycount++;
		if(CheckCollisionRecs(sket.attack_box,hitbox_player)&&!rolling&&sket.enemy_hp>0&&sket.mob_damge_ch){
			player.hp-=sket.enemy_damage;
			if(player.hp<0)player.hp=0;
		}


		if(abs(role_Position.x - sket.enemy_pos.x)<=200&&delaycount>delay&&sket.enemy_hp>0){
			delaycount = 0;
			Vector2 tar;
			tar.x=hitbox_player.x;
			if(tar.x>sket.enemy.x&&tar.x-sket.enemy.x<30){
				sket.velocity.x=0;
				sket.mob_attack=true;
				sket.mob_moving=false;
				sket.attack_box.x=sket.enemy.x+25;
				sket.enemy_pos.y=(groundy-sket_attack.height);
					sket.attack_box.y=sket.enemy.y;
				if(sket.attack.frameRec.width<0)sket.attack.frameRec.width=abs(sket.attack.frameRec.width);
			}
			else if(tar.x<sket.enemy.x&&tar.x-sket.enemy.x>-25){
				sket.velocity.x=0;
				sket.mob_attack=true;
				sket.mob_moving=false;
				sket.attack_box.x=sket.enemy.x-5;
				sket.enemy_pos.y=(groundy-sket_attack.height);
	
				sket.attack_box.y=sket.enemy.y;
				if(sket.attack.frameRec.width>0)sket.attack.frameRec.width=-abs(sket.attack.frameRec.width);

			}
			else if(tar.x >sket.enemy_pos.x){//向右
				sket.velocity.x=sket.speed;
				direct=true;
				sket.mob_moving=true;
				//sket.run.frameWidth<0&&sket.velocity.x>0
			if(direct)
			{sket.enemy_pos.y=(groundy-sket_run.height)-1;
				sket.run.frameRec.width=abs(sket.run.frameRec.width);
				sket.idle.frameRec.width=abs(sket.idle.frameRec.width);
				sket.death.frameRec.width=abs(sket.death.frameRec.width);
				sket.attack.frameRec.width=abs(sket.attack.frameRec.width);
		
			}
			}
			else if(tar.x <sket.enemy_pos.x){//向左
				sket.velocity.x=-sket.speed;
				sket.enemy_pos.y=(groundy-sket_run.height)-1;
				direct=false;
				sket.mob_moving=true;
				if(sket.run.frameWidth>0&&sket.velocity.x<0){
				sket.run.frameRec.width=-abs(sket.run.frameRec.width);
				sket.idle.frameRec.width=-abs(sket.idle.frameRec.width);
				sket.death.frameRec.width=-abs(sket.death.frameRec.width);
				sket.attack.frameRec.width=-abs(sket.attack.frameRec.width);
		
			}}
			else if(abs(tar.x - sket.enemy_pos.x)>200) 
			{
				sket.velocity.x=0;
				sket.mob_moving=false;
			}
			
			
				sket.enemy_pos=Vector2Add(sket.enemy_pos,sket.velocity);
		}

		if(sket.enemy_hp==0)sket.velocity.x=0;
		 sket.enemy.x=sket.enemy_pos.x;
		sket.enemy.y=sket.enemy_pos.y;
        //----------------------------------------------------------------------------------
		++sket.run.frameDelayCounter;
		if(sket.run.frameDelayCounter > sket.run.frameDelay){
			sket.run.frameDelayCounter = 0;
		if(sket.mob_moving){sket.run.frameIndex++;
		sket.run.frameIndex%=sket.run.numFrames;
		}
		sket.run.frameRec.x = (float) sket.run.frameWidth *sket.run.frameIndex;
		}
		++sket.idle.frameDelayCounter;
		if(sket.idle.frameDelayCounter > sket.idle.frameDelay) {
			sket.idle.frameDelayCounter = 0;
		if(!sket.mob_moving){sket.idle.frameIndex++;
		sket.idle.frameIndex%=sket.idle.numFrames;}
				sket.idle.frameRec.x = (float) sket.idle.frameWidth *sket.idle.frameIndex;
		}
////////////////////////////////

		if(switch_==2){
			boss.delaycount++;
		if((CheckCollisionRecs(boss.attack_box,hitbox_player))&&!rolling&&boss.enemy_hp>0&&boss.mob_damge_ch){
			player.hp-=boss.enemy_damage;
				if(player.hp<0)player.hp=0;
		}
			if(abs(role_Position.x - boss.enemy_pos.x)<=900&&boss.delaycount>boss.delay&&boss.enemy_hp>0){
			boss.delaycount = 0;
			Vector2 tar;
			tar.x=hitbox_player.x;
			if(tar.x>boss.enemy.x&&tar.x-boss.enemy.x<150){
				boss.velocity.x=0;
				boss.mob_attack=true;
				boss.mob_moving=false;
				boss.enemy_pos.y=(groundy-boss_attack.height)+5;
				boss.attack_box.x=boss.enemy.x+75;
					boss.attack_box.y=boss.enemy.y;
				if(boss.attack.frameRec.width>0)boss.attack.frameRec.width=-abs(boss.attack.frameRec.width);
			}
			else if(tar.x<boss.enemy.x&&tar.x-boss.enemy.x>-70){
				boss.velocity.x=0;
				boss.mob_attack=true;
				boss.mob_moving=false;
				boss.enemy_pos.y=(groundy-boss_attack.height)+5;
				boss.attack_box.x=boss.enemy.x-65;
				boss.attack_box.y=boss.enemy.y;
				boss.enemy.x=boss.enemy_pos.x+100;
				if(boss.attack.frameRec.width<0)boss.attack.frameRec.width=abs(boss.attack.frameRec.width);

			}
			else if(tar.x >boss.enemy.x){//向右
				boss.velocity.x=boss.speed;
				boss.direct=true;
				boss.mob_moving=true;
				boss.enemy_pos.y=groundy-110;
				//sket.run.frameWidth<0&&sket.velocity.x>0
			if(boss.direct)
			{
				boss.run.frameRec.width=-abs(boss.run.frameRec.width);
				boss.idle.frameRec.width=-abs(boss.idle.frameRec.width);
				boss.death.frameRec.width=-abs(boss.death.frameRec.width);
				boss.attack.frameRec.width=-abs(boss.attack.frameRec.width);
		
			}
			}
			else if(tar.x <boss.enemy.x){//向左
				boss.velocity.x=-boss.speed;
				boss.direct=false;
				boss.mob_moving=true;
				boss.enemy_pos.y=groundy-110;
				if(boss.run.frameWidth>0&&boss.velocity.x<0){
				boss.run.frameRec.width=abs(boss.run.frameRec.width);
				boss.idle.frameRec.width=abs(boss.idle.frameRec.width);
				boss.death.frameRec.width=abs(boss.death.frameRec.width);
				boss.attack.frameRec.width=abs(boss.attack.frameRec.width);
		
			}}
			
				boss.enemy_pos=Vector2Add(boss.enemy_pos,boss.velocity);
		}

		}
		boss.enemy.x=boss.enemy_pos.x+100;
		boss.enemy_pos.y=boss.enemy.y-35;

		++boss.run.frameDelayCounter;
		if(boss.run.frameDelayCounter > boss.run.frameDelay){
			boss.run.frameDelayCounter = 0;
		if(boss.mob_moving){boss.run.frameIndex++;
		boss.run.frameIndex%=boss.run.numFrames;
		}
		boss.run.frameRec.x = (float) boss.run.frameWidth *boss.run.frameIndex;
		}
		++boss.idle.frameDelayCounter;
		if(boss.idle.frameDelayCounter > boss.idle.frameDelay) {
			boss.idle.frameDelayCounter = 0;
		if(!boss.mob_moving){boss.idle.frameIndex++;
		boss.idle.frameIndex%=boss.idle.numFrames;}
				boss.idle.frameRec.x = (float) boss.idle.frameWidth *boss.idle.frameIndex;
		}

////////////////////////////////////////////////////////////////
		++stframeDelayCounter;
		if(stframeDelayCounter > stframeDelay){
			stframeDelayCounter = 0;
			if(!scarfyMoving) {
				if(ground_ch){++stframeIndex;
				stframeIndex %= stnumFrames;
			
		}

			}
				stframeRec.x = (float) stframeWidth *stframeIndex;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////

		//----------------------------------------------------------------------------------
		++frameDelayCounter;
		if(frameDelayCounter > frameDelay) {
			frameDelayCounter = 0;
			if(scarfyMoving) {
				if(ground_ch){++frameIndex;
				frameIndex %= numFrames;
		if(!rolling&&(frameIndex==1||frameIndex==6))PlaySound(footstep);
		}
			 else {
					if(role_Velocity.y < 0) {
						frameIndex= 5;
					} else  {
						frameIndex = 7;
					}

				}

			}
				frameRec.x = (float) frameWidth * frameIndex;

		}
		////////////////////////////////
		if(role_attack==false )attframeIndex=0;
		++attframeDelayCounter;
			if(attframeDelayCounter > attframeDelay) {
			attframeDelayCounter = 0;
			if(role_attack) {
				++attframeIndex;
				attframeIndex %= numFrames;
				attframeRec.x = (float) frameWidth * attframeIndex;
				if(attframeIndex==1||attframeIndex==6)PlaySound(att_s);
				}
		}
if(rolling==false )player_roll.frameIndex=0;
++player_roll.frameDelayCounter;
if(player_roll.frameDelayCounter>player_roll.frameDelay){
	player_roll.frameDelayCounter=0;
	if(rolling){
		++player_roll.frameIndex;
		player_roll.frameIndex%=player_roll.numFrames;
		player_roll.frameRec.x=(float)player_roll.frameWidth*player_roll.frameIndex;
	}
}
   camera.target = (Vector2){ role_Position.x +70.0f,role_Position.y+30};
        BeginDrawing();
		BeginMode2D(camera);
            ClearBackground(BLACK);
			 DrawTexture(background, 0, groundy-500, WHITE); 
			switch(switch_){
				case -1:
				DrawText("I dont know how to name it ",camera.target.x-50,camera.target.y,5,WHITE);
				DrawText("moving : WASD",camera.target.x,camera.target.y+10,2,WHITE);
				DrawText("ATTACk :J",camera.target.x,camera.target.y+20,2,WHITE);
				DrawText("Rolling: L ",camera.target.x,camera.target.y+30,2,WHITE);
				DrawText("Drink posion: Space ",camera.target.x,camera.target.y+40,2,WHITE);
				DrawText("Interact object : Enter ",camera.target.x,camera.target.y+50,2,WHITE);
				break;
				case 0:
				DrawTexture(lv1, 400, groundy-241, WHITE); 
				break;
				case 1:
			    DrawTexture(lv2, 400, groundy-244, WHITE); 
				break;
				case 2:
				DrawTexture(bossfight,400, groundy-241, WHITE);
				break;
				case 3:
				DrawText("YOU WIN ",camera.target.x-10,camera.target.y,5,WHITE);


				break;
				
			}
		if(switch_==2){
	DrawText(TextFormat("boss_hp: %i", (int)boss.enemy_hp),camera.target.x+70,camera.target.y-70,2,BLUE);

		if(boss.dead){
		++boss.death.frameDelayCounter;
		if(boss.death.frameDelayCounter > boss.death.frameDelay) {
		boss.death.frameDelayCounter = 0;
		boss.death.frameIndex++;
		if(boss.death.frameIndex>21)boss.death.frameIndex=21;
		boss.death.frameIndex%=boss.death.numFrames;
		boss.death.frameRec.x = (float) boss.death.frameWidth *boss.death.frameIndex;
		}
		DrawTextureRec(boss_death, boss.death.frameRec,boss.enemy_pos,WHITE);
		}
		else if(boss.mob_moving)DrawTextureRec(boss_run,boss.run.frameRec,boss.enemy_pos,WHITE);
		else if(boss.mob_attack){
		++boss.attack.frameDelayCounter;
		if(boss.attack.frameDelayCounter >boss.attack.frameDelay) {
	boss.attack.frameDelayCounter = 0;
		boss.attack.frameIndex++;
		boss.attack.frameIndex%=boss.attack.numFrames;
		if(boss.attack.frameIndex==8)boss.mob_damge_ch=true;
		else boss.mob_damge_ch=false;
		boss.attack.frameRec.x = (float) boss.attack.frameWidth *boss.attack.frameIndex;
		}
		
			DrawTextureRec(boss_attack,boss.attack.frameRec,boss.enemy_pos,WHITE);
	boss.mob_attack=true;
		}
		else DrawTextureRec(boss_idle,boss.idle.frameRec,boss.enemy_pos,WHITE);
		}	
		if(switch_<2){
		if(sket.dead){
		++sket.death.frameDelayCounter;
		if(sket.death.frameDelayCounter > sket.death.frameDelay) {
		sket.death.frameDelayCounter = 0;
		sket.death.frameIndex++;
		if(sket.death.frameIndex>14)sket.death.frameIndex=14;
		sket.death.frameIndex%=sket.death.numFrames;
		sket.death.frameRec.x = (float) sket.death.frameWidth *sket.death.frameIndex;
		}
		DrawTextureRec(sket_dead, sket.death.frameRec,sket.enemy_pos,WHITE);
		}
		else if(sket.mob_moving)DrawTextureRec(sket_run,sket.run.frameRec,sket.enemy_pos,WHITE);
		else if(sket.mob_attack){
		++sket.attack.frameDelayCounter;
		if(sket.attack.frameDelayCounter > sket.attack.frameDelay) {
		sket.attack.frameDelayCounter = 0;
		sket.attack.frameIndex++;
		sket.attack.frameIndex%=sket.attack.numFrames;
		if(sket.attack.frameIndex==8)sket.mob_damge_ch=true;
		else sket.mob_damge_ch=false;
		sket.attack.frameRec.x = (float) sket.attack.frameWidth *sket.attack.frameIndex;
		
		}
		
			DrawTextureRec(sket_attack,sket.attack.frameRec,sket.enemy_pos,WHITE);
		sket.mob_attack=true;
		}
		else if(sket.velocity.x==0) {
			DrawTextureRec(sket_idle,sket.idle.frameRec,sket.enemy_pos,WHITE);
			}
			}
		if(switch_<3&&switch_>-1){	
			DrawText(TextFormat("hp: %i", (int)player.hp),role_Position.x-80,(int)role_Position.y+100,2,RED);
			DrawText(TextFormat("hp_posion: %i", (int)player.hp_posion),role_Position.x-80,(int)role_Position.y+90,2,WHITE);
				if(role_dead){
		++role_death.frameDelayCounter;
		if(role_death.frameDelayCounter > role_death.frameDelay) {
		role_death.frameDelayCounter = 0;
		role_death.frameIndex++;
		if(role_death.frameIndex>9)role_death.frameIndex=9;
		role_death.frameIndex%=role_death.numFrames;
		role_death.frameRec.x = (float) role_death.frameWidth *role_death.frameIndex;
		}
		DrawTextureRec(roled, role_death.frameRec,role_Position,WHITE);
		}
			else  if(role_Velocity.x != 0){
				if(rolling) {DrawTextureRec(roll, player_roll.frameRec, role_Position, WHITE);rolling = false;}
				else DrawTextureRec(role, frameRec, role_Position, WHITE);
			
			}
			else if(role_attack){
			
			DrawTextureRec(at, attframeRec, role_Position, WHITE);
			role_attack=false;
		}
			else{
				if(role_Velocity.y!=0)DrawTextureRec(role, frameRec, role_Position, WHITE);
				else DrawTextureRec(st,stframeRec,role_Position,WHITE);
			 }
		}
			  
		EndMode2D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded resources at this point
	UnloadSound(footstep);
	UnloadSound(att_s);
    UnloadSound(bgm_s);
	CloseAudioDevice(); 
    CloseWindow();      
	 // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
