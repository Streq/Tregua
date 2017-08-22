/*
 * Game.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: santiago
 */
#include <Tregua/Game/Game.hpp>
#include <Tregua/Game/Logic/Character.hpp>
namespace trg{
void Game::update(const Input::State& input){
	StepControllers(input);
	StepAI();
	StepPhysics();
	StepLogic();
};

Game::Game()
: world{}
{

}

void Game::StepControllers(){
	auto& chars = world.getCharacters();
	std::for_each(chars.begin(),chars.end(),
		[](Logic::Character& character){
				auto& state = input.controllers[character.controller].state;

				Vec2 mov
				{ Utils::Vector2::normalized
				  ( Vec2
					{ static_cast<float32>(state.pressed[Input::Right] - state.pressed[Input::Left])
					, static_cast<float32>(state.pressed[Input::Down] - state.pressed[Input::Up])
					}
				  )
				};

				character.velocity = mov*character.speed;

			};
		}
	);
}

void Game::StepAI() {
}

void Game::StepPhysics() {
	world.update();
}

void Game::StepLogic() {
}

}
