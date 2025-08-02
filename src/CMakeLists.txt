cmake_minimum_required(VERSION 3.5.1)
project(student-manager)

find_package(nlohmann_json REQUIRED)
find_library(SIMPLE_LIBRARY simple-library-lib REQUIRED)

add_executable(student-manager
    main.cpp
    student_manager.cpp
)

target_link_libraries(student-manager
    ${SIMPLE_LIBRARY}
    nlohmann_json::nlohmann_json
)

