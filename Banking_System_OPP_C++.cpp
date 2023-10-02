#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Student {
private:
  std::string name;
  int grade;
  
public:
  Student(const std::string& studentName, int studentGrade)
    : name(studentName), grade(studentGrade) {}
  
  std::string getName() const { return name; }
  int getGrade() const { return grade; }
};

class Gradebook {
private:
  std::vector<Student> students;
  
public:
  void addStudent(const Student& student) {
    students.push_back(student);
  }
  
  double calculateAverageGrade() const {
    if (students.empty()) {
      return 0.0;
    }
    
    double totalGrade = 0.0;
    for (const Student& student : students) {
      totalGrade += student.getGrade();
    }
    
    return totalGrade / students.size();
  }
  
  void displayHighestAndLowestGrades() const {
    if (students.empty()) {
      std::cout << "No students in the gradebook." << std::endl;
      return;
    }
    
    auto minMax = std::minmax_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
      return a.getGrade() < b.getGrade();
    });
    
    std::cout << "Highest Grade: " << minMax.second->getGrade() << " (" << minMax.second->getName() << ")" << std::endl;
    std::cout << "Lowest Grade: " << minMax.first->getGrade() << " (" << minMax.first->getName() << ")" << std::endl;
  }
  
  void displayStudentList() const {
    if (students.empty()) {
      std::cout << "No students in the gradebook." << std::endl;
      return;
    }
    
    std::cout << "Student List:" << std::endl;
    for (const Student& student : students) {
      std::cout << student.getName() << ": " << student.getGrade() << std::endl;
    }
  }
};

int main() {
  Gradebook gradebook;
  
  gradebook.addStudent(Student("Alice", 85));
  gradebook.addStudent(Student("Bob", 92));
  gradebook.addStudent(Student("Charlie", 78));
  
  std::cout << "Average Grade: " << gradebook.calculateAverageGrade() << std::endl;
  gradebook.displayHighestAndLowestGrades();
  gradebook.displayStudentList();
  
  return 0;
}
