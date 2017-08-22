/*
 * Application.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: santiago
 */

#include <SFML/System/Clock.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Tregua/Application/Application.hpp>
#include <Tregua/definitions.hpp>

namespace trg{

	Application::Application()
		:mWindow(sf::VideoMode(800,600), "~~~T r e g u a~~~")
	{

	}

	void Application::run(){
		sf::Clock clock;
		sf::Time timeSinceLastFrame{sf::Time::Zero};
		while(mWindow.isOpen()){

			do{//wait for frame
				sf::Time dt{clock.restart()};
				timeSinceLastFrame += dt;
			}while(limit_frame_rate && timeSinceLastFrame < timePerFrame);

			//handle input once per frame
			handle_input();

			do{//spend time
				//update game logic by one step
				update();
				timeSinceLastFrame -= timePerFrame;
			}while(frame_skip && timeSinceLastFrame > timePerFrame);

			//call the drawino functionino
			draw();
		}




	}

	void Application::initialize(){
	}
	void Application::draw(){
		mWindow.clear();
		mGraphics.draw(mWindow);
		mWindow.display();
	}
	void Application::update(){
		mGame.update();
	}
	void Application::handle_input(){
		mInput.handle_input(mWindow);
	}

}
