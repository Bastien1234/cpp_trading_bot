cmake_minimum_required(VERSION 3.16)

# --- Fetch GoogleTest ---
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- Collect test sources ---
file(GLOB TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# --- Create test executable ---
add_executable(unit_tests ${TEST_SOURCES})

# Include your src directory for headers
target_include_directories(unit_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link GoogleTest + pthread + your core library
target_link_libraries(unit_tests
    PRIVATE
        bot_core
        GTest::gtest
        GTest::gtest_main
        pthread
)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(unit_tests)
