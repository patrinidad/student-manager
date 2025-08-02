#include "student_manager.hpp"
#include <iostream>
#include <fstream>

StudentManager::StudentManager(const std::string& file_path)
    : path_(file_path) {
}

void StudentManager::create_student(int id, const std::string& name) {
    nlohmann::json new_student = {
        {"id", id},
        {"name", name}
    };

    data_["students"].push_back(new_student);
}

void StudentManager::delete_student(int id) {
    auto& students = data_["students"];

    students.erase(
        std::remove_if(students.begin(), students.end(),
            [id](const auto& student) {
                return student["id"] == id;
            }),
        students.end()
    );
}

void StudentManager::list_students() const {
    if (!data_.contains("students") || !data_["students"].is_array()) {
        std::cout << "No students available.\n";
        return;
    }

 
    std::cout << "Student List:\n";
    for (const auto& student : data_["students"]) {
        std::cout << "ID: " << student["id"]
                  << ", Name: " << student["name"] << "\n";
    }
}

void StudentManager::save() {
    std::ofstream out(path_);
    if (out.is_open()) {
        out << data_.dump(4);
        out.close();

        std::cout << "Data saved to " << path_ << "\n";
    } else {
        std::cerr << "Failed to open file for writing: " << path_ << "\n";
    }
}

void StudentManager::load() { 
    std::ifstream in(path_);
    if (in.is_open()) {
        in >> data_;
        in.close();
        std::cout << "Data loaded from " << path_ << "\n";
    } else {
        std::cout << "No file found at " << path_ << ". Starting with empty student list.\n";
    }
}

