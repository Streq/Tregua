#include <Tregua/Game/Logic/World.hpp>

#include <utility>
#include <vector>
namespace trg{
namespace Logic{
void World::update(){
	for(auto& character : mCharacters){
		character.update();
	}
}

void World::addCharacter(Character&& character) {
	mCharacters.push_back(std::forward<Character>(character));
}

void World::addCharacter(const Character& character) {
	mCharacters.push_back(character);
}

std::vector<Character>& World::getCharacters() {
	return mCharacters;
}

}
}


