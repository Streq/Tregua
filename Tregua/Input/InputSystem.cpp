/*
 * InputSystem.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: santiago
 */

#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <Tregua/Input/InputSystem.hpp>
namespace trg{
namespace Input{
	System::System() {
		// TODO Auto-generated constructor stub
	}

	void System::handle_input(sf::Window& window){
		sf::Event e;
		while(window.pollEvent(e)){
			switch(e.type){
				case sf::Event::Closed:{
					window.close();
					//state.close=true;
				}break;
				case sf::Event::Resized:{
					//Notify Renderer
				}break;
			}
		}
	}
}
}
