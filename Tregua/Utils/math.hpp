/*
 * math.hpp
 *
 *  Created on: Aug 19, 2017
 *      Author: santiago
 */

#pragma once

namespace trg{
namespace Utils{
namespace Math{
	constexpr float PI = 3.14159265359f;

	//CONVERSION CONSTANTS
	static constexpr float D2R = (PI) / 180.f;
	static constexpr float R2D = 180.f / (PI);

	inline constexpr float degToRad(float deg){
		return deg*D2R;
	}
	inline constexpr float radToDeg(float rad){
		return rad*R2D;
	}
}
}
}



