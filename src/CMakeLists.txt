
# Collect all sources in src/ (excluding main.cpp)
file(GLOB_RECURSE BOTTRADING_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Separate main.cpp
set(MAIN_SRC "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
list(REMOVE_ITEM BOTTRADING_SOURCES ${MAIN_SRC})

# Create a library for your core logic
add_library(bot_core ${BOTTRADING_SOURCES})

target_include_directories(bot_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Now create the executable
add_executable(bottrading ${MAIN_SRC})
target_link_libraries(bottrading PRIVATE bot_core)