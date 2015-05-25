project( Server )

include_directories( ${SHARED_INCLUDE_DIRS} )

aux_source_directory(. SRC_LIST)
file(GLOB Server_HEADERS "*.h" "*.hpp")

add_executable(${PROJECT_NAME} ${SRC_LIST} ${Server_HEADERS})
target_link_libraries( ${PROJECT_NAME} LibShared )
