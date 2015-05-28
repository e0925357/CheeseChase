#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include <array>
#include <memory>

namespace cheesechase {
    class Level;
    class Tile;
    class Vec2i;
    class Wind;

    typedef std::array<double, 2> Vec2d;

    class GameModel
    {
    public:
        GameModel();
        ~GameModel();

        Vec2d getWindVector() const;
        Vec2i getCheesePosition() const;
        Vec2d getVirtualCheesePosition() const;
        std::vector<Vec2d> getMicePositions() const;
        Tile *getLevelTile(const Vec2i& pos) const;
        unsigned int getLevelCols();
        unsigned int getLevelRows();

        void setWind(const std::shared_ptr<Wind> wind);
        void setLevel(const std::shared_ptr<Level> level);

    private:
        std::shared_ptr<Wind> _wind;
        std::shared_ptr<Level> _level;
    };
}

#endif // GAMEMODEL_H
