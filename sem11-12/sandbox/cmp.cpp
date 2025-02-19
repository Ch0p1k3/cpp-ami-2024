#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <tuple>
#include <vector>

enum class Grade : uint8_t {
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
};

struct Student {
    std::string name;
    std::string surname;
    Grade grade;
};


std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << student.name << " " << student.surname << ' ' << static_cast<int>(student.grade);
    return out;
}


bool operator<(const Student& left, const Student& right) {
    return std::tie(right.grade, left.name, left.surname) < std::tie(left.grade, right.name, right.surname);
}

std::string Foo();

int main() {
    std::vector<Student> students = {
        {"Chill", "Guy", Grade::Three},
        {"Ivan", "Luchsh", Grade::Five},
        {"Maxim", "Bassalaev", Grade::Two},
    };

    std::sort(students.begin(), students.end());

    for (const auto& student : students) {
        std::cout << student << std::endl;
    }

    std::cout << Foo() << std::endl;
}
