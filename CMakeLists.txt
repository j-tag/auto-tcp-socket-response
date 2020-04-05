cmake_minimum_required(VERSION 3.5)

project(tcp-socket-tester LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS forms/ )

set(ALL_FILES
    src/main.cpp
    includes/MainWindow.hpp
    src/MainWindow.cpp
    includes/TcpSocketClient.hpp
    src/TcpSocketClient.cpp
    includes/AutoSocket.hpp
    src/AutoSocket.cpp
    forms/MainWindow.ui
    )

if(ANDROID)
  add_library(tcp-socket-tester SHARED
    ${ALL_FILES}
  )
else()
  add_executable(tcp-socket-tester
    ${ALL_FILES}
  )
endif()

target_link_libraries(tcp-socket-tester PRIVATE Qt5::Widgets Qt5::Network)
