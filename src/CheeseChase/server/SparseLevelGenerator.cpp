#include "SparseLevelGenerator.hpp"
#include "Level.hpp"
#include "PotentialFloor.h"
#include <vector>
#include <Wall.h>
#include <unordered_set>
#include <Floor.h>
#include <random>
#include <chrono>

namespace cheesechase {

    SparseLevelGenerator::SparseLevelGenerator(int width, int height, float overrideProbability) :
            width(width), height(height), overrideProbability(overrideProbability) {
        offsets[0] = Vec2i(1, 0);
        offsets[1] = Vec2i(-1, 0);
        offsets[2] = Vec2i(0, 1);
        offsets[3] = Vec2i(0, -1);
    }

    std::shared_ptr<Level> SparseLevelGenerator::generateLevel() {
        std::vector<std::vector<Tile *>> tiles(width);

        for (int x = 0; x < width; x++) {
            tiles.push_back(std::vector<Tile *>(height));

            for (int y = 0; y < height; y++) {

                if(x == width/2 && y == height/2)
                {
                    tiles[x].push_back(new Floor());
                }
                else {
                    tiles[x].push_back(new Wall());
                }
            }
        }

        std::vector<PotentialFloor> wallList;
        Vec2i middle(width/2, height/2);
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator (seed);
        std::uniform_real_distribution<float> probabilityDistribution(0.f, 1.f);


        for(int i = 0; i < 4; i++)
        {
            wallList.push_back(PotentialFloor(middle + offsets[i], middle));
        }

        while(!wallList.empty()) {
            std::uniform_int_distribution<int> rGen(0, (int)wallList.size()-1);
            int randomIndex = rGen(generator);
            PotentialFloor pf = wallList[randomIndex];
            wallList.erase(wallList.begin() + randomIndex);

            //Ignore tiles that are already a floor
            if(tiles[pf.getPosition().getX()][pf.getPosition().getY()]->getTileType() == TileType::FLOOR)
                continue;

            Vec2i forward = pf.getPosition() - pf.getParentPosition();
            bool invalid = false;
            Vec2i halfNeighbour = pf.getPosition() + forward;

            //Check in a half-circle around the next field
            invalid = invalid || isFloor(halfNeighbour, tiles);

            if(forward.getX() != 0)
            {
                invalid = invalid || isFloor(halfNeighbour + offsets[2], tiles);
                invalid = invalid || isFloor(halfNeighbour + offsets[3], tiles);
                invalid = invalid || isFloor(pf.getPosition() + offsets[2], tiles);
                invalid = invalid || isFloor(pf.getPosition() + offsets[3], tiles);
            }
            else
            {
                invalid = invalid || isFloor(halfNeighbour + offsets[0], tiles);
                invalid = invalid || isFloor(halfNeighbour + offsets[1], tiles);
                invalid = invalid || isFloor(pf.getPosition() + offsets[0], tiles);
                invalid = invalid || isFloor(pf.getPosition() + offsets[1], tiles);
            }

            if(invalid && probabilityDistribution(generator) > overrideProbability)
                continue;

            delete tiles[pf.getPosition().getX()][pf.getPosition().getY()];
            tiles[pf.getPosition().getX()][pf.getPosition().getY()] = new Floor();

            for(int i = 0; i < 4; i++)
            {
                Vec2i potentialNextWall = pf.getPosition() + offsets[i];

                if(!isInside(potentialNextWall) || isFloor(potentialNextWall, tiles))
                    continue;

                wallList.push_back(PotentialFloor(potentialNextWall, pf.getPosition()));
            }
        }

        return std::shared_ptr<Level>(new Level(tiles));
    }


    bool SparseLevelGenerator::isInside(Vec2i const &pos) {
        return pos.getX() >= 0 && pos.getX() < width && pos.getY() >= 0 && pos.getY() < height;
    }


    bool SparseLevelGenerator::isFloor(Vec2i const &pos, std::vector<std::vector<Tile *>> &tiles) {
        if(isInside(pos))
            return tiles[pos.getX()][pos.getY()]->getTileType() == TileType::FLOOR;
        else
            return false;
    }
}
