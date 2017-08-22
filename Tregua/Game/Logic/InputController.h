/*
 * InputController.h
 *
 *  Created on: Aug 21, 2017
 *      Author: santiago
 */

#pragma once
#include <Tregua/Game/Logic/Controller.hpp>


namespace trg {
namespace Logic{
struct Character;


class InputController : public Controller{
public:
	virtual void handle(const Input::Controller::State& controller, Character& character)const override;

};



}
} /* namespace trg */
