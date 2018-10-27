cmake_minimum_required(VERSION 3.12)
project(Rumor)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES "Source Files/main.cpp" "Source Files/Application.cpp" "Source Files/Random.cpp" "Source Files/Automaton.cpp" "Header Files/Automaton.h" "Source Files/Person.cpp" "Header Files/Person.h" "Header Files/Rumor.h")

add_executable(Rumor ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Rumor ${SFML_LIBRARIES})
endif()