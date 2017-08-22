/*
 * Shape.hpp
 *
 *  Created on: Aug 16, 2017
 *      Author: santiago
 */

#pragma once
#include <Tregua/Utils/vec2.hpp>
namespace trg{
struct Shape{
	enum Type{
		AABB,//Rectangle with no rotation
		Circle,
		Box,//Rectangle with rotation
		Sector,//Pizza slices nom nom

	};

	struct Rectangle{
		vec2 halfsize;
	};
	struct Circle{
		float radius;
	};
	struct Sector{
		float radius;
		float angle;
	};


	Type type;
	union {
		Rectangle rectangle;
		Circle	  circle;
		Sector	  sector;
	} shape;



};
};
