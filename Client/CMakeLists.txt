cmake_minimum_required(VERSION 3.16)

# Setează numele proiectului și limbajul folosit
project(TestamQT VERSION 0.1 LANGUAGES CXX)

# Specifică calea către instalarea Qt6
set(Qt6_DIR "C:\\Qt\\6.8.0\\msvc2022_64\\lib\\cmake\\Qt6")
set(QT_DIR ${Qt6_DIR})
set(Qt6WidgetsTools_DIR "${Qt6_DIR}/WidgetsTools")
set(Qt6CoreTools_DIR "${Qt6_DIR}/CoreTools")
set(Qt6GuiTools_DIR "${Qt6_DIR}/GuiTools")

# Include automat directorul curent pentru fișierele .h
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Activează generarea automată a fișierelor .moc, .rcc și .ui
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Specifică versiunea C++ folosită
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Găsește pachetele Qt necesare
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Lista fișierelor sursă ale proiectului
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Creează executabilul, în funcție de versiunea de Qt
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TestamQT
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(TestamQT SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(TestamQT
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Linkează biblioteca Widgets
target_link_libraries(TestamQT PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Setează proprietățile pentru pachetele iOS și macOS, dacă este cazul
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TestamQT)
endif()
set_target_properties(TestamQT PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Include directoarele pentru instalare
include(GNUInstallDirs)
install(TARGETS TestamQT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalizează executabilul pentru Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TestamQT)
endif()