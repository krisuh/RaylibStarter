cmake_minimum_required(VERSION 3.16)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME} LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

# Fetch raylib
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

# Fetch Catch2
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.11.0 # Pick a stable version
)
FetchContent_MakeAvailable(Catch2)

# Fetch glm
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.2
)
FetchContent_MakeAvailable(glm)

# Game library and source files
set(PROJECT_LIB "${PROJECT_NAME}_lib")
file(GLOB_RECURSE EXECUTABLE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
# Library
list(REMOVE_ITEM EXECUTABLE_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
add_library(${PROJECT_LIB} ${EXECUTABLE_SOURCES})
target_include_directories(${PROJECT_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_LIB} PUBLIC raylib glm)

# Main executable
add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_LIB})
target_compile_definitions(${PROJECT_NAME} PRIVATE
    APP_NAME="${PROJECT_NAME}"
)

# Resources directory
set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources")
set(OUTPUT_ASSETS_DIR "${CMAKE_CURRENT_BINARY_DIR}/resources")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${ASSETS_DIR} ${OUTPUT_ASSETS_DIR}
)

install(TARGETS ${PROJECT_NAME})
install(DIRECTORY resources DESTINATION .)


# Test executable
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS tests/*.cpp)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain ${PROJECT_LIB})
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)