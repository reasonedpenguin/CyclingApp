PROJECT(widgets)

SET(widgets_SOURCES  
    qcustomplot.cpp)
    
SET(widgets_HEADERS 
    qcustomplot.h)
    


QT4_WRAP_CPP(widgets_HEADERS_MOC ${widgets_HEADERS})
QT4_WRAP_UI(widgets_FORMS_HEADERS ${widgets_FORMS})
QT4_ADD_RESOURCES(widgets_RESOURCES_RCC ${widgets_RESOURCES})


ADD_LIBRARY(widgets ${widgets_SOURCES} 
    ${widgets_HEADERS_MOC}
    ${widgets_FORMS_HEADERS} 
    ${widgets_RESOURCES_RCC})
