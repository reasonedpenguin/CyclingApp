PROJECT(widgets)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

SET(widgets_SOURCES 
    SearchWidget.cpp 
    qcustomplot.cpp)
    
SET(widgets_HEADERS 
    SearchWidget.h
    qcustomplot.h)
   
SET(widgets_FORMS
    forms/SearchWidgetBase.ui) 
    
SET(widgets_RESOURCES
    widgets.qrc)

QT4_WRAP_CPP(widgets_HEADERS_MOC ${widgets_HEADERS})
QT4_WRAP_UI(widgets_FORMS_HEADERS ${widgets_FORMS})
QT4_ADD_RESOURCES(widgets_RESOURCES_RCC ${widgets_RESOURCES})


ADD_LIBRARY(widgets ${widgets_SOURCES} 
    ${widgets_HEADERS_MOC}
    ${widgets_FORMS_HEADERS} 
    ${widgets_RESOURCES_RCC})
