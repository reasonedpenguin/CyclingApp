cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED)

SET(QT_USE_QTSQL TRUE)
SET(QT_USE_QTXML TRUE)
SET(QT_USE_QTTEST TRUE)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})


include_directories("${PROJECT_SOURCE_DIR}/gpsdata")
include_directories("${PROJECT_SOURCE_DIR}/widgets")

add_subdirectory(CyclingApp)
add_subdirectory(gpsdata)
add_subdirectory(widgets)
add_subdirectory(tests) 