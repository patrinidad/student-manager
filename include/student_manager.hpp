#include <string>
#include <nlohmann/json.hpp>

class StudentManager {
public:
    StudentManager(const std::string& file_path);
    void create_student(int id, const std::string& name);
    void delete_student(int id);
    void list_students() const;
    void save();
    void load();

private:
    std::string path_;
    nlohmann::json data_;
};

