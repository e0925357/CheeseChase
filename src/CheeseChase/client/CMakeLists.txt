project( Client )

include_directories( ${SHARED_INCLUDE_DIRS} )

find_package(Boost 1.54.0 COMPONENTS system)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries( ${PROJECT_NAME} LibShared "-lboost_system")
