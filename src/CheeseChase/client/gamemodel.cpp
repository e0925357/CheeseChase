#include "Level.hpp"
#include "Wind.h"

#include "gamemodel.h"

cheesechase::GameModel::GameModel() :
    _wind(nullptr),
    _level(nullptr)
{
}

cheesechase::GameModel::~GameModel()
{
}

cheesechase::Vec2d cheesechase::GameModel::getWindVector() const
{
    return Vec2d {0.0, 0.0};
}

cheesechase::Vec2i cheesechase::GameModel::getCheesePosition() const
{
    return _level->getCheesePosition();
}

cheesechase::Vec2d cheesechase::GameModel::getVirtualCheesePosition() const
{
    return Vec2d {3.5, 4.4};
}

std::vector<cheesechase::Vec2d> cheesechase::GameModel::getMicePositions() const
{
    return std::vector<Vec2d> {{0.0, 5.0}, {5.0, 0.0}, {5.0, 5.0}};
}

cheesechase::Tile *cheesechase::GameModel::getLevelTile(const Vec2i &pos) const
{
    return _level->getTile(pos);
}

unsigned int cheesechase::GameModel::getLevelCols()
{
    return _level->getCols();
}

unsigned int cheesechase::GameModel::getLevelRows()
{
    return _level->getRows();
}

void cheesechase::GameModel::setWind(const std::shared_ptr<cheesechase::Wind> wind)
{
    this->_wind = std::move(wind);
}

void cheesechase::GameModel::setLevel(const std::shared_ptr<cheesechase::Level> level)
{
    this->_level = std::move(level);
}
