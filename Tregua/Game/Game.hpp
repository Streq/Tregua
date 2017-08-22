/*
 * Game.h
 *
 *  Created on: Jul 27, 2017
 *      Author: santiago
 */
#pragma once
#include <Tregua/Input/Controller.hpp>
#include <Tregua/Game/Logic/World.hpp>
namespace trg{

class Game{
public:
	Game();
	void update();

private:
	void StepControllers();
	void StepAI();
	void StepPhysics();
	void StepLogic();

	Logic::World world;

};

}





