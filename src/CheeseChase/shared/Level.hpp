#ifndef HEADER_Level_CLASS
#define HEADER_Level_CLASS

#include<array>
#include<vector>
#include "Vec2i.hpp"

namespace cheesechase
{
    class Tile;
    class Behaviour;

    class Level
	{
	public:
        Level(const std::vector<std::vector<Tile*>>& tiles);
        virtual ~Level();

        //Returns the Tile at the given position or null if the position is invalid
        Tile* getTile(const Vec2i& pos) const;

        //Returns all neighbouring tiles of the given position. If a tile is outside the level, null is returned
        //The neighbours are traversed in following order: from left to right, then up to down, where the origion
        //is in the lower left corner.
        std::array<Tile*, 8> getNeighbours(const Vec2i& pos) const;

        //Returns the position of the cheese
        Vec2i getCheesePosition() const;

        //Adds a mouse with the given behaviour at the given position to the level.
        void addMouse(const Behaviour& b, const Vec2i& pos);

        //Updates the logic of the level.
        void update(double deltaT);

    private:
        std::vector<std::vector<Tile*>> tiles;

        Vec2i neighbourOffsets[8];
	};
}

#endif
