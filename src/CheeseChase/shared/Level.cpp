#include "Tile.hpp"
#include "Level.hpp"

namespace cheesechase {

    Level::Level(const std::vector<std::vector<Tile *>> &tiles) : tiles(tiles) {
        neighbourOffsets[0] = Vec2i(-1, 1);
        neighbourOffsets[1] = Vec2i(0, 1);
        neighbourOffsets[2] = Vec2i(1, 1);
        neighbourOffsets[3] = Vec2i(-1, 0);
        neighbourOffsets[4] = Vec2i(1, 0);
        neighbourOffsets[5] = Vec2i(-1, -1);
        neighbourOffsets[6] = Vec2i(0, -1);
        neighbourOffsets[7] = Vec2i(1, -1);
    }

    Level::~Level() {
        for (int x = 0; x < tiles.size(); x++) {
            for (int y = 0; y < tiles[x].size(); y++) {
                delete tiles[x][y];
                tiles[x][y] = nullptr;
            }
        }
    }

//Returns the Tile at the given position or null if the position is invalid
    Tile *Level::getTile(const Vec2i &pos) const {
        if (pos.getX() < 0 || pos.getY() >= tiles.size())
            return nullptr;

        if (pos.getY() < 0 || pos.getY() >= tiles[pos.getX()].size())
            return nullptr;

        return tiles[pos.getX()][pos.getY()];
    }

//Returns all neighbouring tiles of the given position. If a tile is outside the level, null is returned
    std::array<Tile *, 8> Level::getNeighbours(const Vec2i &pos) const {
        std::array<Tile *, 8> neighbours;

        for (int i = 0; i < 8; i++) {
            Vec2i nPos = pos + neighbourOffsets[i];
            neighbours[i] = getTile(nPos);
        }

        return neighbours;
    }

//Returns the position of the cheese
    Vec2i Level::getCheesePosition() const {
        // stub
        return Vec2i(4, 4);
    }

//Adds a mouse with the given behaviour at the given position to the level.
    void Level::addMouse(const Behaviour &b, const Vec2i &pos) {

    }

//Updates the logic of the level.
    void Level::update(double deltaT) {

    }

//Returns the number of columns of the level
    unsigned int Level::getCols() {
        return tiles.size();
    }

//Returns the number of rows of the level
    unsigned int Level::getRows() {
        return tiles[0].size();
    }
}
