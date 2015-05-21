//
// Created by Stefan on 18.05.2015.
//

#ifndef CHEESECHASE_WALL_H
#define CHEESECHASE_WALL_H

#include "Tile.hpp"

namespace cheesechase
{
    class Wall : public Tile
    {
    public:
        Wall() : Tile() {};
        virtual ~Wall() = default;
        virtual TileType getTileType();

    };
}

#endif //CHEESECHASE_WALL_H
