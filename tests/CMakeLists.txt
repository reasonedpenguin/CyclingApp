PROJECT(tests)



SET(tests_SOURCES main.cpp tst_exporttest.cpp tst_importtest.cpp)
SET(tests_HEADERS tst_exporttest.h tst_importtest.h)
SET(tests_RESOURCES tests.qrc)

QT4_WRAP_CPP(tests_HEADERS_MOC ${tests_HEADERS})
QT4_WRAP_UI(tests_FORMS_HEADERS ${tests_FORMS})
QT4_ADD_RESOURCES(tests_RESOURCES_RCC ${tests_RESOURCES})

ADD_EXECUTABLE(CyclingAppTests ${tests_SOURCES} 
    ${tests_HEADERS_MOC}
    ${tests_FORMS_HEADERS} 
    ${tests_RESOURCES_RCC})
    
TARGET_LINK_LIBRARIES(CyclingAppTests gpsdata ${QT_LIBRARIES})