project( Shared )

aux_source_directory(. SRC_LIST)
file(GLOB Shared_HEADERS "*.h" "*.hpp")

add_library( LibShared ${SRC_LIST} ${Shared_HEADERS})

set( SHARED_INCLUDE_DIRS ${Shared_SOURCE_DIR} CACHE STRING "Includedir for Shared." FORCE )
