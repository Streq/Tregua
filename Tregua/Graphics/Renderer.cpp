/*
 * Graphics.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: santiago
 */

#include <SFML/Graphics.hpp>
#include <Tregua/Graphics/Renderer.hpp>
#include <Tregua/definitions.hpp>
namespace trg{
	Renderer::Renderer() {
		// TODO Auto-generated constructor stub

	}

	void Renderer::draw(sf::RenderTarget& target){
		sf::VertexArray v(sf::PrimitiveType::Triangles,6);
		v[0].position=Vec2(0.f,0.f);
		v[1].position=Vec2(0.f,600.f);
		v[2].position=Vec2(800.f,0.f);
		v[3].position=Vec2(800.f,600.f);
		v[4].position=Vec2(0.f,600.f);
		v[5].position=Vec2(800.f,0.f);

		v[0].color=sf::Color::Yellow;
		v[1].color=sf::Color::Green;
		v[2].color=sf::Color::Blue;
		v[3].color=sf::Color::Red;
		v[4].color=sf::Color::Green;
		v[5].color=sf::Color::Blue;
		target.draw(v);
	}
}

