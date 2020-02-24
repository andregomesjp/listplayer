cmake_minimum_required(VERSION 3.1.0)

project(helloworld)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
set(VIEW_INC "view/inc")
set(VIEW_SRC "view/src")

set(SOURCES
    main.cpp
    ${VIEW_SRC}/MainView.cpp
)

set(HEADERS
    ${VIEW_INC}/MainView.h
)

include_directories(${VIEW_INC})

add_executable(helloworld
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(helloworld Qt5::Widgets Qt5::Core Qt5::Gui)
