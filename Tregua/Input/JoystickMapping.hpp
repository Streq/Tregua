/*
 * JoystickMapping.h
 *
 *  Created on: Jul 31, 2017
 *      Author: santiago
 */

#pragma once
#include <Tregua/Input/Controller.hpp>
namespace trg{
namespace Input{
struct JoystickMapping : Controller::Mapping{
			struct Input{
				enum Type{
					Axis,
					Button
				};
				Type type;
				union Data{
					struct AxisInput{
						unsigned char id;
						bool positive;
					} axis;
					struct ButtonInput
					{
						unsigned short id;
					} button;
				} data;
			};

			unsigned char 	id;
			float 			deadzone;//from 0.f to 100.f;
			Input 			mappings[Button::size];

			Controller::Event handle_input(const sf::Event& e) const override{
				Controller::Event ret;
				switch (e.type){
					case sf::Event::EventType::JoystickMoved:{
						if(e.joystickMove.joystickId==id){
							for(int i=0; i<Button::size; i++){
								const auto& map = mappings[i];
								if (map.type==Input::Type::Axis && map.data.axis.id == e.joystickMove.axis){
									ret.button = i;
									ret.pressed = !signbit(e.joystickMove.position) == map.data.axis.positive && std::abs(e.joystickMove.position)>deadzone;
								}
							}
						}
					}break;
					case sf::Event::JoystickButtonPressed:
					case sf::Event::JoystickButtonReleased:{
						if(e.joystickButton.joystickId==id){
							for(int i=0; i<Button::size; i++){
								const auto& map = mappings[i];
								if (!map.type==Input::Type::Button && map.data.button.id == e.joystickButton.button){
									ret.button = i;
									ret.pressed = e.type==sf::Event::JoystickButtonPressed;
									break;
								}
							}
						}
					}break;
					default:{
						ret.button=Button::size;
					}break;
				}
				return ret;
			}
		};//JoystickMapping end
}
}

