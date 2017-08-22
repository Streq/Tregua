/*
 * InputController.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: santiago
 */

#include <Tregua/Game/Logic/InputController.h>
#include <Tregua/Game/Logic/Character.hpp>
namespace trg {
namespace Logic{

void InputController::handle(const Input::Controller::State& controller, Character& character)const{

	Vec2 mov
	{ Utils::Vector2::normalized
	  ( Vec2
		{ static_cast<float32>(controller.pressed[Input::Right] - controller.pressed[Input::Left])
		, static_cast<float32>(controller.pressed[Input::Down] - controller.pressed[Input::Up])
		}
	  )
	};

	character.velocity = mov*character.speed;
}



}
}
