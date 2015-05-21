#ifndef HERADER_Tile_INTERFACE
#define HERADER_Tile_INTERFACE

namespace cheesechase {

	enum TileType {
		WALL, FLOOR
	};

	class Tile {
	public:
		virtual ~Tile() = default;
		Tile(Tile const &) = delete;
		Tile & operator=(Tile const &) = delete;

		//Returns the type of this tile
		virtual TileType getTileType() = 0;

	protected:
		//Only children can create instances
		Tile() = default;
		
	};
}

#endif