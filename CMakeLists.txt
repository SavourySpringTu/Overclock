cmake_minimum_required(VERSION 3.5)

project(Overclock VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(src/HEADERS)
include_directories(src/SOURCES)
include_directories(src/FORMS)

set(SOURCES
    src/SOURCES/main.cpp
    src/SOURCES/Information.cpp
    src/SOURCES/Monitor.cpp
    src/SOURCES/Thread.cpp
    src/SOURCES/Window.cpp
)

set(HEADERS
    src/HEADERS/Information.h
    src/HEADERS/Monitor.h
    src/HEADERS/Thread.h
    src/HEADERS/Window.h
)

set(FORMS)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Overclock
        MANUAL_FINALIZATION
        ${SOURCES}
        ${HEADERS}
        ${FORMS}
        src/HEADERS/Global.h
        src/SOURCES/Global.cpp
        src/HEADERS/About.h
        src/SOURCES/About.cpp
    )
else()
    add_executable(Overclock
        ${SOURCES}
        ${HEADERS}
        ${FORMS}
    )
endif()

# Thêm tệp tài nguyên sau khi đã định nghĩa executable
qt_add_resources(Overclock "resources"
    PREFIX "/"
    FILES "src/resources.qrc"  # Đảm bảo đường dẫn chính xác
)

target_link_libraries(Overclock PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Overclock)
endif()
set_target_properties(Overclock PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Overclock
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Overclock)
endif()
