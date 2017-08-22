/*
 * KeyboardMapping.h
 *
 *  Created on: Jul 31, 2017
 *      Author: santiago
 */

#pragma once
#include <Tregua/Input/Controller.hpp>

namespace trg{
namespace Input{

struct KeyboardMapping{
			unsigned int mappings[Button::size];

			ButonEvent handle_input(const sf::Event& e)const override{
				ButonEvent ret;
				switch(e.type){
					case sf::Event::KeyPressed:
					case sf::Event::KeyReleased:{
						for(int i=0; i < Button::size; i++){
							const auto& map = mappings[i];
							if (map == e.key.code){
								ret.button = i;
								ret.pressed = e.type==sf::Event::KeyPressed;
								break;
							}
						}
					}break;
					default:{
						ret.button=Button::size;
					}
				}
				return ret;

			}
		};//Key boardMapping end


}
}



