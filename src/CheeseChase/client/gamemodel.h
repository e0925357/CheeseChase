#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include <array>
#include <memory>

namespace cheesechase {
    class Level;
    class Wind;

    typedef std::array<double, 2> Vec2d;

    class GameModel
    {
    public:
        GameModel();
        ~GameModel();

        Vec2d getWindVector();
        std::vector<Vec2d> getMicePositions();
        std::shared_ptr<Level> getLevel();

        void setWind(const std::shared_ptr<Wind> wind);
        void setLevel(const std::shared_ptr<Level> level);

    private:
        std::shared_ptr<Wind> _wind;
        std::shared_ptr<Level> _level;
    };
}

#endif // GAMEMODEL_H
