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

cheesechase::Vec2d cheesechase::GameModel::getWindVector()
{
    return Vec2d {0.0, 0.0};
}

std::vector<cheesechase::Vec2d> cheesechase::GameModel::getMicePositions()
{
    return std::vector<Vec2d> {{0.0, 5.0}, {5.0, 0.0}, {5.0, 5.0}, {7.0, 5.0}, {5.0, 7.0}};
}

std::shared_ptr<cheesechase::Level> cheesechase::GameModel::getLevel()
{
    return _level;
}

void cheesechase::GameModel::setWind(const std::shared_ptr<cheesechase::Wind> wind)
{
    this->_wind = std::move(wind);
}

void cheesechase::GameModel::setLevel(const std::shared_ptr<cheesechase::Level> level)
{
    this->_level = std::move(level);
}
