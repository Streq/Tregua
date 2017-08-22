/*
 * app_constants.h
 *
 *  Created on: Jul 18, 2017
 *      Author: santiago
 */
#pragma once
#include <memory>
#include <cstdint>
#include <cfloat>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
namespace trg{
	constexpr float timeStep = 1.f/60.f;

	constexpr float epsilon = 1e-5;

	using Window = sf::RenderWindow;
	using Vec2 = sf::Vector2f;
	using Clock = sf::Clock;
	using Time = sf::Time;

	using int8 = std::int8_t;
	using int16 = std::int16_t;
	using int32 = std::int32_t;
	using int64 = std::int64_t;

	using uint8 = std::uint8_t;
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;

	using float32 = float;
	using float64 = double;

	template <class T>
	using ptr = std::unique_ptr<T>;

}
