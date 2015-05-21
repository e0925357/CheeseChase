project( Shared )

aux_source_directory(. SRC_LIST)
add_library( LibShared ${SRC_LIST} Wall.cpp Wall.h Floor.cpp Floor.h Tile.hpp)

set( SHARED_INCLUDE_DIRS ${Shared_SOURCE_DIR} CACHE STRING "Includedir for Shared." FORCE )
