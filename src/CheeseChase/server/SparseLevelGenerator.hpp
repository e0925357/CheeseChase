#ifndef HEADER_SparseLevelGenerator_CLASS
#define HEADER_SparseLevelGenerator_CLASS

#include <vector>
#include"LevelGen.hpp"
#include"Vec2i.hpp"

namespace cheesechase
{
    class Tile;

    class SparseLevelGenerator : public LevelGen
	{
	public:
        SparseLevelGenerator(int width, int height, float overrideProbability);
        virtual ~SparseLevelGenerator() = default;

        virtual std::shared_ptr<Level> generateLevel();

    private:
        bool isInside(Vec2i const& pos);
        bool isFloor(Vec2i const& pos, std::vector<std::vector<Tile*>> &tiles);
        //always between 0 and 1
        float overrideProbability;
        int width;
        int height;
        Vec2i offsets[4];
	};
}

#endif
