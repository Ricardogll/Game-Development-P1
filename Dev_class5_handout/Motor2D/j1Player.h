#ifndef _j1PLAYER_H_
#define _j1PLAYER_H_

#include	"PugiXml/src/pugixml.hpp"
#include	"j1Module.h"
#include	"p2List.h"
#include	"p2Point.h"
#include	"j1Textures.h"
#include	"Animation.h"

#define GRAVITY 0.01f //change gravity after testing it
#define SPEED_X 1.0f
#define SPEED_Y 0.3f


struct SDL_texture;
struct SDL_Rect;
struct Collider;

//enum player state? idle, jumping...?
//enum player moving? idle, right, up...?
enum STATE {
	IDLE_RIGHT,
	IDLE_LEFT,
	WALK_RIGHT,
	WALK_LEFT,
	JUMP_RIGHT,
	JUMP_LEFT,
	LEDGE_RIGHT,
	LEDGE_LEFT,
	NO_STATE,
};

enum X_DIRECTION {
	RIGHT,
	LEFT,
	NONE,
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
	void LoadPosition();
	void SavePosition();
	//void Load();
//	pugi::xml_node LoadFile(pugi::xml_document& document);
	//bool LoadFile();
	void Draw();
	bool Jumping();
	void OnCollision(Collider* c1, Collider* c2);
private:

	uint width = 0;
	uint height = 0;
	SDL_Texture* graphics = nullptr;
	fPoint speed;
	STATE state=NO_STATE;
	Animation* current_animation = nullptr;
	//Animation* last_animation = nullptr;
	//Animation* last_animation_2 = nullptr;
	STATE last_state = NO_STATE;
	STATE last_state_2 = NO_STATE;
	Animation idle_right;
	Animation walk_right;
	Animation jump_right;
	Animation idle_left;
	Animation walk_left;
	Animation jump_left;
	Animation ledge_right;
	Animation ledge_left;

	uint lastTime = 0;
	bool jumping=false;
	bool onGround = true;
	X_DIRECTION playerdir = NONE;
	pugi::xml_node positionnode;
	pugi::xml_document save_file;
	pugi::xml_attribute position_attr_x;
	pugi::xml_attribute position_attr_y;
	//p2List<j1Module*> modules;
	//mutable bool needs_load = true, needs_save = false;
	bool on_ledge_right = false;
	bool on_ledge_left = false;
public:

	fPoint playerpos;
	//fPoint playervel;
	Collider* playerCollider;
	bool touching_floor = false;
	bool in_ledge = false;
	bool ledge_disabled = false;
	uint disable_ledge = 0;
	uint currentTime = 0;
	bool ledge_jump_x_disabled = false;
	


};




#endif