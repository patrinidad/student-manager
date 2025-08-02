set(SIMPLE_LIBRARY_LIB ${CMAKE_SOURCE_DIR}/../simple-library-pt/build/src/libsimple-library-lib.a)

find_package(nlohmann_json REQUIRED)

add_executable(student-manager
    main.cpp
    student_manager.cpp
)

target_link_libraries(student-manager
    ${SIMPLE_LIBRARY_LIB}
    nlohmann_json::nlohmann_json
)

