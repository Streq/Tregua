/*
 * Fixture.h
 *
 *  Created on: Jul 29, 2017
 *      Author: santiago
 */

#pragma once

#include <Tregua/Utils/vec2.hpp>
#include <Tregua/Game/Physics/Shape.hpp>
#include <Tregua/Game/Physics/Body.hpp>
namespace trg{
namespace Physics{

struct Fixture{
	Body* 		body;
	vec2 		origin;
	bool		is_sensor;
	Shape		shape;

};

}
}




