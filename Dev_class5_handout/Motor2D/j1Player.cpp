#include "p2Defs.h"
#include "p2Log.h"
#include "j1Player.h"
#include "p2List.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Map.h"
#include "SDL\include\SDL_timer.h"

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )



j1Player::j1Player() : j1Module()
{

	idle_right.PushBack({ 1,39,20,35 });	
	idle_right.PushBack({ 21,39,20,35 });
	idle_right.PushBack({ 42,39,20,35 });
	idle_right.PushBack({ 63,39,20,35 });
	idle_right.PushBack({ 84,39,20,35 });
	idle_right.PushBack({ 105,39,20,35 });
	idle_right.PushBack({ 126,39,20,35 });
	idle_right.PushBack({ 147,39,20,35 });
	idle_right.PushBack({ 168,39,20,35 });
	idle_right.PushBack({ 189,39,20,35 });
	idle_right.PushBack({ 210,39,20,35 });
	idle_right.PushBack({ 231,39,20,35 });
	idle_right.speed = 0.05f;
	
	idle_left.PushBack({ 1,157,20,35 });	
	idle_left.PushBack({ 21,157,20,35 });
	idle_left.PushBack({ 42,157,20,35 });
	idle_left.PushBack({ 63,157,20,35 });
	idle_left.PushBack({ 84,157,20,35 });
	idle_left.PushBack({ 105,157,20,35 });
	idle_left.PushBack({ 126,157,20,35 });
	idle_left.PushBack({ 147,157,20,35 });
	idle_left.PushBack({ 168,157,20,35 });
	idle_left.PushBack({ 189,157,20,35 });
	idle_left.PushBack({ 210,157,20,35 });
	idle_left.PushBack({ 231,157,20,35 });
	idle_left.speed = 0.05f;

	walk_right.PushBack({ 1,1,22,33 });
	walk_right.PushBack({ 23,1,19,33 });
	walk_right.PushBack({ 43,1,16,33 });
	walk_right.PushBack({ 60,1,20,33 });
	walk_right.PushBack({ 80,1,20,33 });
	walk_right.PushBack({ 100,1,19,33 });
	walk_right.PushBack({ 119,1,20,33 });
	walk_right.PushBack({ 139,1,23,33 });
	walk_right.speed = 0.05f;

	walk_left.PushBack({ 1,118,22,33 });
	walk_left.PushBack({ 23,118,19,33 });
	walk_left.PushBack({ 43,118,16,33 });
	walk_left.PushBack({ 60,118,20,33 });
	walk_left.PushBack({ 80,118,20,33 });
	walk_left.PushBack({ 100,118,19,33 });
	walk_left.PushBack({ 119,118,20,33 });
	walk_left.PushBack({ 139,118,23,33 });
	walk_left.speed = 0.05f;

	jump_right.PushBack({ 162,1,19,37 });
	jump_right.PushBack({ 203,1,19,37 });
	jump_right.PushBack({ 223,1,21,37 });
	jump_right.PushBack({ 182,1,21,37 });
	jump_right.speed = 0.05f;
	jump_right.loop = false;

	jump_left.PushBack({ 162,118,19,37 });
	jump_left.PushBack({ 203,118,19,37 });
	jump_left.PushBack({ 223,118,21,37 });
	jump_left.PushBack({ 182,118,21,37 });
	jump_left.speed = 0.05f;
	jump_left.loop = false;
	
	ledge_right.PushBack({ 1,76,21,41 });
	ledge_right.PushBack({ 22,76,20,41 });
	ledge_right.PushBack({ 42,76,19,41 });
	ledge_right.PushBack({ 61,76,20,41 });
	ledge_right.PushBack({ 81,76,20,41 });
	ledge_right.PushBack({ 101,76,20,41 });
	ledge_right.speed = 0.05f;
	ledge_right.loop = false;

	ledge_left.PushBack({ 1,194,21,41 });
	ledge_left.PushBack({ 22,194,20,41 });
	ledge_left.PushBack({ 42,194,19,41 });
	ledge_left.PushBack({ 61,194,20,41 });
	ledge_left.PushBack({ 81,194,20,41 });
	ledge_left.PushBack({ 101,194,20,41 });
	ledge_left.speed = 0.05f;
	ledge_left.loop = false;	

}




j1Player::~j1Player()
{
	//p2List_item<j1Module*>* item = modules.end;

	//while (item != NULL)
	//{
	//	RELEASE(item->data);
	//	item = item->prev;
	//}

	//modules.clear();

	//config_file.reset();
}


bool j1Player::Awake(pugi::xml_node& config)
{
	LOG("Loading Player");
	bool ret = true;

	save_file.load_file("save_game.xml");
	positionnode = save_file.child("game_state").child("position");
	position_attr_x = positionnode.child("position").attribute("x");
	position_attr_y = positionnode.child("position").attribute("y");


	//for (pugi::xml_node tool = positionnode.first_child(); tool; tool = tool.next_sibling())
	//{
	//	//std::cout << "Tool:";
	//	LOG("Tool:");
	//	for (pugi::xml_attribute attr = tool.first_attribute(); attr; attr = attr.next_attribute())
	//	{
	//		LOG(" %s = %i", attr.name(), attr.value());
	//		//int a = tool.attribute("x").as_int;
	//		LOG("%d", tool.attribute("x").as_int());
	//		//std::cout << " " << attr.name() << "=" << attr.value();
	//	}

	//	
	//}
	/*LOG(" aa %d  aaaaa", positionnode.child("position").attribute("x").as_int());
	pugi::xml_attribute positionattrx = positionnode.child("position").attribute("x");
	positionattrx.set_value(100);
	LOG(" aa %d  aaaaa", positionnode.child("position").attribute("x").as_int());
	LOG("aaa %d aaaa", positionattrx.as_int());*/



	return ret;
}

bool j1Player::Start()
{
	LOG("starting player");
	bool ret = true;
	graphics = App->tex->Load("maps/PlayerSprites.png");
	state = IDLE_RIGHT;
	
	playerpos.x = 100;
	playerpos.y = 100;
	speed.x = 0;
	//speed.y = GRAVITY;
	speed.y = 0;

	return ret;
}

bool j1Player::Update()
{

	//LOG("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"); //log doesnt appear. Update doesnt run. why?
	//if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	//{
	//	//playerpos.x += SPEED_X;
	//	state = WALK_RIGHT;
	//	LOG("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	//}
	//if (App->input->GetKey(SDL_SCANCODE_D) == KEY_UP)
	//{
	//	state = IDLE_RIGHT;
	//}
	//
	//if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	//{
	//	//playerpos.y += SPEED_Y;
	//	state = WALK_LEFT;
	//}
	//if (App->input->GetKey(SDL_SCANCODE_A) == KEY_UP)
	//{
	//	state = IDLE_LEFT;
	//}
	return true;
}

bool j1Player::PostUpdate()
{

	/*if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN && needs_load) {
		
	
	}*/
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN) {
		SavePosition();
	}

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN) {
		LoadPosition();
	}


	//Input();
	//if (Falling())
	//{
	//	position.y += 1.0f;
	//}
	//Draw();
	//LOG("AAAAAAASDASDSDASDASDSDSDSDSDADASDASDADSSD");
	//LOG("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{

		playerpos.x += SPEED_X;
		if (jumping == false) {
			state = WALK_RIGHT;
		}
		else {
			state = JUMP_RIGHT;
		}
		
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_UP)
	{
		if (jumping == false) {
			state = IDLE_RIGHT;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		playerpos.x -= SPEED_X;
		if (jumping == false) {
			state = WALK_LEFT;
		}
		else {
			state = JUMP_LEFT;
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_UP)
	{
		if (jumping == false) {
			state = IDLE_LEFT;
		}
		
	}
	//if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	//{
	//	state = JUMP_LEFT;
	//	
	//}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		if(playerdir==RIGHT)
			state = JUMP_RIGHT;
		else if(playerdir==LEFT)
			state = JUMP_LEFT;
		Jumping();

	}
	if (App->input->GetKey(SDL_SCANCODE_V) == KEY_REPEAT)
	{
		state = LEDGE_RIGHT;
	}
	if (App->input->GetKey(SDL_SCANCODE_C) == KEY_REPEAT)
	{
		state = LEDGE_LEFT;
		//LOG("%d", GetCurrentTime());
	}


	if (playerpos.y < 400) {
		speed.y += GRAVITY;
		
	}
	else if (playerpos.y >= 400) {
		speed.y = 0;
		onGround = true;
		ledge_right.Reset();
		ledge_left.Reset();
		jump_right.Reset();
		jump_left.Reset();
		jumping = false;
	}
	playerpos.y += speed.y;
	Draw();
	return true;
}

bool j1Player::Jumping() {
	bool ret = true;
	//uint currentTime = SDL_GetTicks();

	//if (currentTime > (lastTime + 1000)) {
	//
	//	lastTime = currentTime;
	//	jump_flag = true;
	//}

	//if (jump_flag) {
	//	playerpos.y += SPEED_Y;
	//}
	if (onGround)
	{
		jumping = true;
		speed.y = -2.0f;
		onGround = false;
		playerpos.y-=5;
	}

	if (speed.y < -2.0f / 2) {
		speed.y = -2.0f / 2;
	}

	return ret;
}


bool j1Player::CleanUp()
{
	LOG("Destroying player");
	bool ret = true;
	return ret;
}


bool j1Player::Load(pugi::xml_node& node)//document o node
{
	bool ret = true;
	////pugi::xml_node player = node.append_child("position"); //mirar bien que hace esto
	////player.append_attribute("x") = playerpos.x;
	////player.append_attribute("y") = playerpos.y;
	//playerpos.x = node.attribute("x").as_float;
	//playerpos.y = node.attribute("y").as_float;


	return ret;
}


//pugi::xml_node j1Player::LoadFile(pugi::xml_document& document)//document o node
//{
//	pugi::xml_node ret;
//	pugi::xml_parse_result result = document.load_file("save_game.xml");
//
//	if (result == NULL)
//		LOG("Could not load map xml file config.xml. pugi error: %s", result.description());
//	else
//		ret = document.child("config");
//
//	return ret;
//}
//
//bool j1Player::LoadFile() {
//	bool ret = true;
//	pugi::xml_parse_result result = save_file.load_file("save_game.xml");
//
//	if (result == NULL) {
//		LOG("Could not load map xml file camera.xml. pugi error: %s", result.description());
//		ret = false;
//	}
//	else
//	{
//		positionnode = save_file.child("game_state");
//	}
//
//	return ret;
//	
//
//}

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
	case LEDGE_RIGHT:
		current_animation = &ledge_right;
		break;
	case LEDGE_LEFT:
		current_animation = &ledge_left;
		break;

	}
	SDL_Rect render = current_animation->GetCurrentFrame();
	App->render->Blit(graphics, playerpos.x, playerpos.y, &render);
	//LOG("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
}




void j1Player::LoadPosition() {

	//LOG(" aa %d  aaaaa", positionnode.child("position").attribute("x").as_int());
	//pugi::xml_attribute positionattrx = positionnode.child("position").attribute("x");
	//positionattrx.set_value(100);
	//LOG(" aa %d  aaaaa", positionnode.child("position").attribute("x").as_int());
	playerpos.x = position_attr_x.as_int();
	playerpos.y = position_attr_y.as_int();

}

//need to add attr for map 1/2 so we change if needed
void j1Player::SavePosition() {
	position_attr_x.set_value(playerpos.x);
	position_attr_y.set_value(playerpos.y);
}