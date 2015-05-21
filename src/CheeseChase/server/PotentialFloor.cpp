//
// Created by Stefan on 20.05.2015.
//

#include "PotentialFloor.h"

cheesechase::PotentialFloor::PotentialFloor(const cheesechase::Vec2i &position,
                                            const cheesechase::Vec2i &parentPosition) :
                                                position(position), parentPosition(parentPosition) {

}


const cheesechase::Vec2i &cheesechase::PotentialFloor::getPosition() {
    return position;
}


const cheesechase::Vec2i &cheesechase::PotentialFloor::getParentPosition() {
    return parentPosition;
}
