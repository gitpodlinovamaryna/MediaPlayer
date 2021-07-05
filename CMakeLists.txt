cmake_minimum_required(VERSION 2.8)

project(MediaPlayer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++14")
include_directories(
    src-gen
    ${CMAKE_CURRENT_SOURCE_DIR}/capicxx-core-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/capicxx-dbus-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dbus-1.12.16
)
link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/capicxx-core-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/capicxx-dbus-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/dbus-1.12.16/dbus/.libs
)
add_executable(MediaPlayer
    src/main.cpp
    src-gen/v1/MediaPlayer/MediaPlayerDBusProxy.cpp
    src-gen/v1/MediaPlayer/MediaPlayerDBusDeployment
)
target_link_libraries(MediaPlayer CommonAPI CommonAPI-DBus dbus-1)
add_executable(MediaPlayerSim
    src/sim/mainSim.cpp
    src-gen/v1/MediaPlayer/MediaPlayerDBusStubAdapter.cpp
    src-gen/v1/MediaPlayer/MediaPlayerStubDefault
    src-gen/v1/MediaPlayer/MediaPlayerDBusDeployment
)
target_link_libraries(MediaPlayerSim CommonAPI CommonAPI-DBus dbus-1)

