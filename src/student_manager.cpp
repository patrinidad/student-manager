#include "student_manager.hpp"
#include <iostream>
#include <fstream>


// Constructor initializes the path to the JSON file
StudentManager::StudentManager(const std::string& file_path)
    : path_(file_path) {
    // Initialization is complete
}

// Adds a new student to the in-memory JSON structure
void StudentManager::create_student(int id, const std::string& name) {
    // Build a JSON object for the new student
    nlohmann::json new_student = {
        {"id", id},
        {"name", name}
    };

    // Append the student object to the "students" array
    data_["students"].push_back(new_student);
}

// Deletes a student from the "students" array by matching the ID
void StudentManager::delete_student(int id) {
    // Access the array of students
    auto& students = data_["students"];

    // Remove any student object whose "id" field matches the given id
    students.erase(
        std::remove_if(students.begin(), students.end(),
            [id](const auto& student) {
                return student["id"] == id;
            }),
        students.end()
    );
}

// Lists all student records to the standard output
void StudentManager::list_students() const {
    // Check whether the "students" key exists and is an array
    if (!data_.contains("students") || !data_["students"].is_array()) {
        std::cout << "No students available.\n";
        return;
    }

    // Output each student in the list
    std::cout << "Student List:\n";
    for (const auto& student : data_["students"]) {
        std::cout << "ID: " << student["id"]
                  << ", Name: " << student["name"] << "\n";
    }
}

// Saves the current JSON data to the file specified by path_
void StudentManager::save() {
    // Open the file for writing
    std::ofstream out(path_);
    if (out.is_open()) {
        // Write formatted JSON data
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

