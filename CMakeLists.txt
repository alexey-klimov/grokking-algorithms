# --------------------------------------------------------------------------------------------------
# Grokking algorithms implementation project

cmake_minimum_required(VERSION 3.0)
project(GrokkingAlgorithms)

# --------------------------------------------------------------------------------------------------
# C++ compiler settings

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
endif()

# --------------------------------------------------------------------------------------------------
# Source and header files

set(SOURCE_FILES
    src/BinarySearch.cpp
)

set(HEADER_FILES
    include/GrokkingAlgorithms.h
    include/BinarySearch.h
)

# --------------------------------------------------------------------------------------------------
# GrokkingAlgorithms library

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})

# --------------------------------------------------------------------------------------------------
# Third-party libraries, modules and includes

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)

# --------------------------------------------------------------------------------------------------
# GrokkingAlgorithms demo

set(DEMO_NAME ${PROJECT_NAME}Demo)

set(DEMO_SOURCE_FILES
    demo/Demo.cpp
    demo/BinarySearchDemo.cpp
)

set(DEMO_HEADER_FILES
    demo/BinarySearchDemo.h
)

add_executable(${DEMO_NAME} ${DEMO_SOURCE_FILES} ${DEMO_HEADER_FILES})

target_link_libraries(${DEMO_NAME} ${PROJECT_NAME})

target_include_directories(${DEMO_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --------------------------------------------------------------------------------------------------
# Tests

option(${PROJECT_NAME}_BUILD_TESTS "Build and run ${PROJECT_NAME} tests" ON)

if(${PROJECT_NAME}_BUILD_TESTS)
    message(STATUS "${PROJECT_NAME} build test ON")
else()
    message(STATUS "${PROJECT_NAME} build test OFF")
endif()

if (${PROJECT_NAME}_BUILD_TESTS)

    set(PROJECT_TEST ${PROJECT_NAME}Test)

    set(TEST_SOURCE_FILES
        test/Test.cpp
        test/BinarySearchTest.cpp
    )

    set(TEST_HEADER_FILES
        test/BinarySearchTest.h
    )

    add_executable(${PROJECT_TEST} ${TEST_SOURCE_FILES} ${TEST_HEADER_FILES})

    target_link_libraries(${PROJECT_TEST} ${PROJECT_NAME})

    target_include_directories(${PROJECT_TEST} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${MODULES_DIR}/kisstest
    )

    add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_TEST})

    set_tests_properties(${PROJECT_NAME} PROPERTIES TIMEOUT 60)

    add_custom_command(
        TARGET ${PROJECT_TEST}
        COMMENT "Run ${PROJECT_NAME} tests"
        POST_BUILD
        COMMAND ${PROJECT_TEST}
   )

endif()