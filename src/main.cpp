#include "student_manager.hpp"
#include <iostream>

int main() {
    std::string path;
    std::cout << "Enter path to JSON file: ";
    std::cin >> path;

    StudentManager sm(path);
    sm.load();
    sm.list_students();

    std::cout << "\nAdding sample student...\n";
    sm.create_student(123, "student-sample");
    sm.save();

    std::cout << "\nUpdated student list:\n";
    sm.list_students();

    return 0;
}

