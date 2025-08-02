find_package(nlohmann_json REQUIRED)
find_library(SIMPLE_LIBRARY simple-library-lib)

add_executable(student-manager
    main.cpp
    student_manager.cpp
)

target_link_libraries(student-manager
    ${SIMPLE_LIBRARY}
    nlohmann_json::nlohmann_json
)

