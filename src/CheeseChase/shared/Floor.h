//
// Created by Stefan on 18.05.2015.
//

#ifndef CHEESECHASE_FLOOR_H
#define CHEESECHASE_FLOOR_H

#include "Tile.hpp"

namespace cheesechase {
    class Floor : public Tile {
    public:
        virtual ~Floor() = default;

        virtual TileType getTileType();
    };
}


#endif //CHEESECHASE_FLOOR_H
