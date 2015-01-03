PROJECT(tests)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

SET(tests_SOURCES TcxDataSource_Test.cpp TcxWriter_Test.cpp ActivityDB_Test.cpp)
SET(tests_HEADERS )
SET(tests_RESOURCES tests.qrc)

QT4_WRAP_CPP(tests_HEADERS_MOC ${tests_HEADERS})
QT4_WRAP_UI(tests_FORMS_HEADERS ${tests_FORMS})
QT4_ADD_RESOURCES(tests_RESOURCES_RCC ${tests_RESOURCES})

ADD_EXECUTABLE(CyclingAppTests ${tests_SOURCES} 
    ${tests_HEADERS_MOC}
    ${tests_FORMS_HEADERS} 
    ${tests_RESOURCES_RCC})
    
TARGET_LINK_LIBRARIES(CyclingAppTests gpsdata ${QT_LIBRARIES} ${GTEST_BOTH_LIBRARIES} pthread)

add_test(AllTestsForCyclingApp CyclingAppTests) 