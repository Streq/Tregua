#pragma once
/*
 * Controller.h
 *
 *  Created on: Jul 27, 2017
 *      Author: santiago
 */
#include <SFML/Window/Event.hpp>
#include <math.h>
#include <array>

namespace trg{
namespace Input{


enum Button{
	Up,
	Down,
	Left,
	Right,
	A,	//Attack
	B,	//Special Attack
	X,	//Jump
	Y,	//Block
	Start,
	size
};





struct Controller{
	struct Event{
		Button button;
		bool pressed;
	};

	struct Mapping{

		virtual ~Mapping() {};
		virtual Controller::Event handle_input(const sf::Event& e) const = 0;
	};




	void handle_event(const sf::Event& e){
		auto event = mapping->handle_input(e);
		handle_inner_event(event);
	};
	void unpress_all(){//called on lost focus
		Event e;
		e.pressed=false;
		for(size_t i = 0; i < Button::size; ++i){
			e.button = static_cast<Button>(i);
			handle_inner_event(e);
		}
	}

	struct State{
		std::array<bool,Button::size+1> pressed;
		std::array<bool,Button::size+1> updated;
	}state;

	private:

	void handle_inner_event(const Controller::Event& event){
		auto& pressed = state.pressed[event.button];
		auto& updated = state.updated[event.button];
		//updated equals wether the pressed event is different from the one saved
		updated = (pressed != event.pressed);
		pressed = event.button;
	}



	Mapping* mapping;

};



struct State{
	Controller controllers[4];
	bool close;
};



}
}
