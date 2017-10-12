#ifndef _j1PLAYER_H_
#define _j1PLAYER_H_

#include	"PugiXml/src/pugixml.hpp"
#include	"j1Module.h"
#include	"p2List.h"
#include	"p2Point.h"
#include	"j1Textures.h"
#include	"Animation.h"

#define GRAVITY 2.0f //change gravity after testing it
#define SPEED_X 1.0f
#define SPEED_Y 1.0f


struct SDL_texture;
struct SDL_Rect;

//enum player state? idle, jumping...?
//enum player moving? idle, right, up...?
enum STATE {
	IDLE_RIGHT,
	IDLE_LEFT,
	WALK_RIGHT,
	WALK_LEFT,
	JUMP_RIGHT,
	JUMP_LEFT,
	NO_STATE,
};




class j1Player :public j1Module
{
public:
	j1Player();
	~j1Player();
	
	bool Start();
	bool CleanUp();
	bool Awake(pugi::xml_node& config);
	bool Update();
	bool PostUpdate();
	bool Load(pugi::xml_node&);
	void Draw();

private:

	uint width = 0;
	uint height = 0;
	SDL_Texture* graphics = nullptr;
	fPoint speed;
	STATE state=NO_STATE;
	Animation* current_animation;
	Animation idle_right;
	Animation walk_right;
	Animation jump_right;
	Animation idle_left;
	Animation walk_left;
	Animation jump_left;


public:

	fPoint playerpos;


};




#endif