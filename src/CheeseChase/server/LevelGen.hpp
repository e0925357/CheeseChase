#ifndef HERADER_LevelGen_INTERFACE
#define HERADER_LevelGen_INTERFACE

#include<memory>

namespace cheesechase {
	class Level;

	class LevelGen {
	public:
		virtual ~LevelGen() = default;
		LevelGen(LevelGen const &) = delete;
		LevelGen & operator=(LevelGen const &) = delete;

		//Generates a new Level
		virtual std::shared_ptr<Level> generateLevel() = 0;

	protected:
		//Only children can create instances
		LevelGen() = default;
	};
}

#endif