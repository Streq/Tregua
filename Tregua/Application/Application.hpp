
#pragma once
/*
 * Application.h
 *
 *  Created on: Jul 15, 2017
 *      Author: santiago
 */
#include <SFML/System/Time.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <Tregua/Graphics/Renderer.hpp>
#include <Tregua/Input/InputSystem.hpp>
#include <Tregua/Game/Game.hpp>

namespace trg{

	class Application{
		public:
			Application();

			//main loop
			void run();
			void initialize();
			void update();
			void draw();
			void handle_input();
		private:
		//Modules
			//Window
			sf::RenderWindow mWindow;

			//Graphics
			Renderer mGraphics;

			//Audio

			//Input
			Input::System mInput;

			//Logic
			Game mGame;

		private:
			/////////////////////////
			//App general variables//
			/////////////////////////

			//Time Per Frame in milliseconds
			sf::Time timePerFrame = sf::seconds(1.f/60.f);

			/* Fixed Frame Time
			 * If this flag is set then a frame will begin only after
			 * the previous frame is done AND timePerFrame amount of time
			 * has passed since the beginning of said frame.
			 * Otherwise it will only check that the previous frame is done.
			*/
			bool limit_frame_rate = true;

			/* Frame Skip
			 * If this flag is set then frame renderization is
			 * skipped whenever it is not possible
			 * at the specified frame_time
			*/
			bool frame_skip = true;

	};

}
