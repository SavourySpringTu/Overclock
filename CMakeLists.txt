cmake_minimum_required(VERSION 3.5)

# Đặt tên project và version
project(Overclock VERSION 0.1 LANGUAGES CXX)

# Tự động xử lý UIC, MOC, và RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Đặt chuẩn C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tìm và cài đặt các thành phần của Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Thêm các thư mục chứa file nguồn và file tiêu đề (Nếu có)
include_directories(.)
include_directories(resources)

# Đặt các tệp nguồn và tiêu đề
set(SOURCES
    main.cpp
    Information.cpp
    Monitor.cpp
    Thread.cpp
    Window.cpp
    Global.cpp
    About.cpp
)

set(HEADERS
    Information.h
    Monitor.h
    Thread.h
    Window.h
    Global.h
    About.h
)

set(FORMS)

# Xử lý tạo executable khác nhau dựa trên phiên bản Qt
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Overclock
        MANUAL_FINALIZATION
        ${SOURCES}
        ${HEADERS}
        ${FORMS}
    )
else()
    add_executable(Overclock
        ${SOURCES}
        ${HEADERS}
        ${FORMS}
    )
endif()

# Thêm tệp tài nguyên sau khi đã định nghĩa executable
qt_add_resources(SOURCES resources.qrc)

# Tạo file thực thi

# Liên kết với các thư viện Widgets của Qt
target_link_libraries(Overclock PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Xử lý trường hợp MacOS nếu phiên bản Qt nhỏ hơn 6.1.0
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Overclock)
endif()

# Đặt thuộc tính cho project
set_target_properties(Overclock PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Định nghĩa cài đặt cho GNU Install
include(GNUInstallDirs)
install(TARGETS Overclock
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize executable nếu dùng Qt 6 trở lên
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Overclock)
endif()
