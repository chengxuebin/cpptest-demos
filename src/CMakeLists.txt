project(example CXX)
add_library(${PROJECT_NAME} SHARED)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    example.cpp
    my_math.cpp
)

# target_include_directories(
# ${PROJECT_NAME}
# PUBLIC
# ${CMAKE_CURRENT_LIST_DIR}
# )
