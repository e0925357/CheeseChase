#include <iostream>
#include <thread>
#include <Level.hpp>
#include "LevelGen.hpp"
#include <memory>
#include <Tile.hpp>
#include "SparseLevelGenerator.hpp"
#include "Tile.hpp"


using namespace cheesechase;

void foo() {
    std::cout << "thread server" << std::endl;
}

int main()
{
    std::thread t1(foo);
    std::cout << "Server: Hello World!" << std::endl;
    t1.join();

    int width = 10;
    int height = 10;

    LevelGen* levelGen = new SparseLevelGenerator(width, height, 0.1f);
    std::shared_ptr<Level> level = levelGen->generateLevel();

    for(int y = 0; y < height; y++ ) {
        for(int x = 0; x < width; x++) {
            Tile* tile = level->getTile(Vec2i(x,y));

            if(tile != nullptr && tile->getTileType() == TileType::WALL)
                std::cout << 'X';
            else
                std::cout << ' ';
        }

        std::cout << std::endl;
    }

    return 0;
}

