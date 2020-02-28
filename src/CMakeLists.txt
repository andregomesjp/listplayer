set(SOURCES
    main.cpp
    ${VIEW_SRC}/PlaylistListView.cpp
    ${MODEL_SRC}/Playlist.cpp
    ${MODEL_SRC}/PlaylistListModel.cpp
    ${CONTROLLER_SRC}/PlaylistListController.cpp
)

set(HEADERS
    ${VIEW_INC}/PlaylistListView.h
    ${MODEL_INC}/Playlist.h
    ${MODEL_INC}/PlaylistListModel.h
    ${CONTROLLER_INC}/PlaylistListController.h
)

set(
    EXECUTABLE_OUTPUT_PATH ${APP_PATH}
)

include_directories(
    ${SRC_DIR}
    ${VIEW_INC}
    ${MODEL_INC}
    ${CONTROLLER_INC}
)

add_definitions(-DRES_DIR="${APP_RES_DIR}")

add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

#if unit tests

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)
