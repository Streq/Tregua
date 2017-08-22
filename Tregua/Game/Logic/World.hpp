/*
 * World.hpp
 *
 *  Created on: Jul 29, 2017
 *      Author: santiago
 */
#pragma once


#include <Tregua/Game/Logic/Character.hpp>
#include <vector>

namespace trg{
namespace Logic{

class World{
public:
	void update();
	void addCharacter(Character&& character);
	void addCharacter(const Character& character);

	std::vector<Character>& getCharacters();

private:
	std::vector<Character> mCharacters;


};


}
}



