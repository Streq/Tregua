/*
 * Body.h
 *
 *  Created on: Jul 29, 2017
 *      Author: santiago
 */

#pragma once
#include <SFML/System/Vector2.hpp>
#include <Tregua/Game/Physics/Fixture.hpp>
#include <Tregua/Utils/vec2.hpp>
namespace trg{
namespace Physics{

struct Body{
	enum class Type{
		Dynamic,
		Static,
		size
	};

	Type 		type;
	vec2 		position;
	vec2 		velocity;
	float		rotation;
	float		angularVelocity;

};

}
}


