PROJECT(CyclingApp)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

SET(app_SOURCES main.cpp MainWindow.cpp PlotWindow.cpp)
SET(app_HEADERS MainWindow.h PlotWindow.h)
SET(app_FORMS 
    forms/MainWindowBase.ui 
    forms/PlotWindowBase.ui)
    
SET(app_RESOURCES app.qrc)

QT4_WRAP_CPP(app_HEADERS_MOC ${app_HEADERS})
QT4_WRAP_UI(app_FORMS_HEADERS ${app_FORMS})
QT4_ADD_RESOURCES(app_RESOURCES_RCC ${app_RESOURCES})


ADD_EXECUTABLE(CyclingApp ${app_SOURCES} 
    ${app_HEADERS_MOC} 
    ${app_FORMS_HEADERS} 
    ${app_RESOURCES_RCC})
    
TARGET_LINK_LIBRARIES(CyclingApp src ${QT_LIBRARIES})