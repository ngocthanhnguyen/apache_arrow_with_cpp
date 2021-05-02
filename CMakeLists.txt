cmake_minimum_required(VERSION 3.5)

project(ExecTestSchemaJsonConversion)

find_package(Arrow REQUIRED)

add_subdirectory(src)
add_executable(ExecTestSchemaJsonConversion test.cpp)
target_link_libraries(ExecTestSchemaJsonConversion PUBLIC src)
target_link_libraries(ExecTestSchemaJsonConversion PRIVATE arrow_shared)

target_include_directories(ExecTestSchemaJsonConversion PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/src"
                          )
                          
