/*
 * Graphics.h
 *
 *  Created on: Jul 15, 2017
 *      Author: santiago
 */
#pragma once
//Graphics
/* Design
 * No details of "how this should be drawn" are ever passed to this module
 * it just needs to know the state of the game,
 * everything else is decided by itself.
 *
 * All it needs to know is the current state of the game,
 * though the previous loaded state should help minimize
 * resource initialization.
 */
namespace sf{
	class RenderTarget;
}
namespace trg
{
	class Renderer {
	public:
		Renderer();

		void draw(sf::RenderTarget& target);

	};
}
