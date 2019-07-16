cmake_minimum_required(VERSION 3.7.2)
project(algorithms)

##### google-test-section-start ################################################
find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

set(GTEST_LIB_DIR "${binary_dir}/lib/")
set(GTEST_INCLUDE_DIR "${source_dir}/googletest/include"
                      "${source_dir}/googlemock/include"
)

##### google-test-section-end ##################################################

function(build_target TARGET_SOURCE_PATH)
    string(REPLACE "_" "-" TARGET_NAME ${TARGET_SOURCE_PATH})
    # remove extension of source file
    string(REGEX REPLACE "\\.[^.]*$" "" TARGET_NAME ${TARGET_NAME})
    set(TARGET_NAME ${PROJECT_NAME}_${TARGET_NAME})

    add_executable(${TARGET_NAME} ${TARGET_SOURCE_PATH})
    #    add_dependencies(${TARGET_NAME} gtest)
    target_compile_options(${TARGET_NAME} PRIVATE
        -std=c++17 -pedantic -Wall -Wextra -Wcast-align
        -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization
        -Wformat=2 -Winit-self -Wlogical-op
        -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept
        -Wold-style-cast -Woverloaded-virtual -Wredundant-decls
        -Wshadow -Wsign-conversion -Wsign-promo
        -Wstrict-null-sentinel -Wstrict-overflow=5
        -Wswitch-default -Wundef -Werror -Wno-unused
    )

    # determine if file is testable
    file(READ ${TARGET_SOURCE_PATH} TMP)
    string(FIND "${TMP}" "TEST_BUILD" MATCH_POSITION)
    if(NOT ${MATCH_POSITION} EQUAL -1)
        add_executable(${TARGET_NAME}_tests ${TARGET_SOURCE_PATH})
        add_dependencies(${TARGET_NAME}_tests gtest)
        target_include_directories(
            ${TARGET_NAME}_tests PRIVATE ${GTEST_INCLUDE_DIR}
        )
        target_link_libraries(${TARGET_NAME}_tests
            ${GTEST_LIB_DIR}/libgmock.a
            ${GTEST_LIB_DIR}/libgtest.a
            pthread
        )
        target_compile_definitions(${TARGET_NAME}_tests PRIVATE TEST_BUILD)
        add_test(NAME ${TARGET_NAME}_tests COMMAND ${TARGET_NAME}_tests)
    endif()
endfunction()

enable_testing()

add_subdirectory(hackerrank)
