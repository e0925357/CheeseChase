project( Shared )

aux_source_directory(. SRC_LIST)
add_library( LibShared ${SRC_LIST})

set( SHARED_INCLUDE_DIRS ${Shared_SOURCE_DIR} CACHE STRING "Includedir for Shared." FORCE )
