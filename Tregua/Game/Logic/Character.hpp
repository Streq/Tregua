#pragma once

#include <Tregua/definitions.hpp>
#include <Tregua/Utils/vec2.hpp>
#include <Tregua/Game/Logic/Script.hpp>
#include <Tregua/Game/Logic/Controller.hpp>
#include <array>

namespace trg{
namespace Logic{



enum ClassId{
	//clases
	tank,
	assassin,
	wizard,
	bowman
};



struct CharacterClass{
	float health;
	float mana;

	float speed;
	float ratio;
	float weight;

	std::array<std::unique_ptr<Script>,4> attacks;
};

struct Character{
	using ptr = std::unique_ptr<Character>;
	enum State{
		idle,
		attack,
		hurt,
		dead
	};

	float rotation_rads;
	Vec2 position;
	Vec2 velocity;
	float speed;

	float health;
	float mana;
	float ratio;
	float weight;

	ClassId clase;
	State state;



	Controller* controller;

	//std::array<std::unique_ptr<Script>,4> attacks;


	inline void move(){
		position+=velocity;
	}
//	inline void updateAI(){
//		controller->handle(*this);
//	}


	inline void update(){
		move();
	}

};






}
}
