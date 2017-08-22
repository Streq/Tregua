/*
 * Controller.hpp
 *
 *  Created on: Aug 20, 2017
 *      Author: santiago
 */

#pragma once
#include <Tregua/Input/Controller.hpp>
#include <Tregua/Utils/vec2.hpp>
namespace trg{
//namespace Input{
//struct Controller;
//}

namespace Logic{
struct Character;

class Controller{
public:

	virtual ~Controller(){};
	virtual void handle(Character& character)const = 0;

};




}
}


