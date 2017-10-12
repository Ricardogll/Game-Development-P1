#include "p2Defs.h"
#include "p2Log.h"
#include "j1Player.h"
#include "p2List.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Map.h"

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )



j1Player::j1Player() : j1Module()
{

	idle.PushBack({});


}




j1Player::~j1Player()
{
}


bool j1Player::Awake(pugi::xml_node& config)
{
	LOG("Loading Player");
	bool ret = true;

	playerpos.x = 10;
	playerpos.y = 10;
	speed.x = 0;
	speed.y = GRAVITY;

	return ret;
}

bool j1Player::Start()
{
	LOG("starting player");
	bool ret = true;
	graphics = App->tex->Load("maps/Mario.png");
	state = IDLE_RIGHT;
	

	return ret;
}

bool j1Player::Update()
{

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		playerpos.x += SPEED_X;
		state = WALK_RIGHT;
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_UP)
	{
		state = IDLE_RIGHT;
	}
	
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		playerpos.y += SPEED_Y;
		state = WALK_LEFT;
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_UP)
	{
		state = IDLE_LEFT;
	}
	return true;
}

bool j1Player::PostUpdate()
{
	//Input();
	//if (Falling())
	//{
	//	position.y += 1.0f;
	//}
	//Draw();
	return true;
}


bool j1Player::CleanUp()
{
	LOG("Destroying player");
	bool ret = true;
	return ret;
}


bool j1Player::Load(pugi::xml_node& node)
{
	bool ret = true;
	pugi::xml_node player = node.append_child("position"); //mirar bien que hace esto
	player.append_attribute("x") = playerpos.x;
	player.append_attribute("y") = playerpos.y;

	return ret;
}

void j1Player::Draw()
{
	switch (state)
	{
	case IDLE_RIGHT:
		current_animation = &idle_right;
		break;

	case IDLE_LEFT:
		current_animation = &idle_left;
		break;

	case WALK_RIGHT:
		current_animation = &walk_right;
		break;

	case WALK_LEFT:
		current_animation = &walk_left;
		break;

	case JUMP_RIGHT:
		current_animation = &jump_right;
		break;

	case JUMP_LEFT:
		current_animation = &jump_left;
		break;


	}
	SDL_Rect render = current_animation->GetCurrentFrame();
	App->render->Blit(graphics, playerpos.x, playerpos.y, &render);
}