project( Client )

find_package( Qt4 REQUIRED )

file(GLOB Client_SOURCES "*.cpp")
file(GLOB Client_HEADERS "*.h" "*.hpp")
file(GLOB Client_FORMS "Forms/*.ui")

qt4_wrap_cpp( Client_HEADERS_MOC ${Client_HEADERS} )
qt4_wrap_ui( Client_FORMS_HEADERS ${Client_FORMS} )

include( ${QT_USE_FILE} )
include_directories( ${SHARED_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR} )

add_definitions( ${QT_DEFINITIONS} )

add_executable(${PROJECT_NAME} ${Client_SOURCES} ${Client_HEADERS_MOC} ${Client_FORMS_HEADERS} )
target_link_libraries( ${PROJECT_NAME} LibShared ${QT_LIBRARIES} )
