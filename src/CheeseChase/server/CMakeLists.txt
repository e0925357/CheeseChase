project( Server )

include_directories( ${SHARED_INCLUDE_DIRS} )

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries( ${PROJECT_NAME} LibShared "-lboost_system")
