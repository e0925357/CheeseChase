//
// Created by Stefan on 20.05.2015.
//

#ifndef CHEESECHASE_POTENTIALFLOOR_H
#define CHEESECHASE_POTENTIALFLOOR_H

#include"Vec2i.hpp"

namespace cheesechase {
    class PotentialFloor {
    public:
        PotentialFloor(Vec2i const& position, Vec2i const& parentPosition);

        Vec2i const& getPosition();
        Vec2i const& getParentPosition();

    private:
        Vec2i position;
        Vec2i parentPosition;
    };
}


#endif //CHEESECHASE_POTENTIALFLOOR_H
