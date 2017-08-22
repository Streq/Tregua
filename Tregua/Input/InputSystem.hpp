/*
 * InputSystem.h
 *
 *  Created on: Jul 15, 2017
 *      Author: santiago
 */
#pragma once
#include <Tregua/Input/Controller.hpp>
#include <vector>
namespace sf{
	class Window;
}
namespace trg{
namespace Input{
	class System {
	public:

		/* Handles external input
		 * and maps it to Application relevant messages.
		 */
		System();


		void handle_input(sf::Window& window);

	private:
		std::unique_ptr<Controller::Mapping> controllers;

		Input::State state;


	};
}
}
