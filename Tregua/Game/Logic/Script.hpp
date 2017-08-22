/*
 * Script.hpp
 *
 *  Created on: Aug 14, 2017
 *      Author: santiago
 */

#pragma once

#include <Tregua/Utils/vec2.hpp>

struct Character;
struct World;

namespace trg{
namespace Logic{

class Script{
public:
	enum State{
		inactive,
		ready,
		active,
	};
	Script
	( Character& user
	, World& world
	)
	: user(&user)
	, world(&world)
	, state(inactive)
	{}
	virtual ~Script(){}
	void update(){
		switch(state){
			case ready:
				state=active;
				init();
			case active:
				applyStep();
		}
	};
	void start(){state = State::ready; init();}
	void end(){state = State::inactive; cleanup();}
protected:
	Character* user;
	World* world;
private:
	State state;

	virtual void applyStep()=0;
	virtual void init(){};
	virtual void cleanup(){};
};

class ScriptWalk : public Script{
public:
	ScriptWalk
	( Character& user
	, World& world
	, Vec2 direction
	)
	: Script(user,world)
	, direction(direction){

	}

	void setDirection(Vec2 dir){
		direction=dir;
	}
private:
	void applyStep() override{
//		user->velocity = Utils::Vec2::normalized(direction) * user->speed;
	}
	Vec2 direction;
};

class ScriptArcStrike : public Script{
public:
	ScriptArcStrike
	( Character& user
	, World& world
	, float damage
	, int frames
	, float reach
	, float range
	):
	Script(user,world),
	damage(damage),
	frames(frames),
	reach(reach),
	range(range)
	{};
private:
	float damage;
	int frames;
	float range;
	float reach;

	virtual void cleanup()override{}
};


}

}



