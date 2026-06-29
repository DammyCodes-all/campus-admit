#include <iostream>
#include <iomanip>
#include "admission.h"

namespace CampusAdmit {

int getCutOff(const std::string& department) {
    if (department == "Medicine") return 270;
    if (department == "Computer Science") return 250;
    if (department == "Law") return 250;
    if (department == "Accounting") return 240;
    if (department == "Mass Communication") return 220;
    if (department == "Business Administration") return 200;
    return 200;
}

std::string evaluateAdmission(int score, const std::string& department) {
    int cutOff = getCutOff(department);
    if (score >= cutOff) return "ADMITTED";
    return "NOT ADMITTED";
}

void listDepartments() {
    std::cout << "\nAvailable Departments:\n";
    std::cout << std::left
              << std::setw(27) << "Department"
              << "Cut-off\n";
    std::cout << std::string(36, '-') << "\n";
    std::cout << std::left
              << std::setw(27) << "Medicine"
              << "270\n";
    std::cout << std::left
              << std::setw(27) << "Computer Science"
              << "250\n";
    std::cout << std::left
              << std::setw(27) << "Law"
              << "250\n";
    std::cout << std::left
              << std::setw(27) << "Accounting"
              << "240\n";
    std::cout << std::left
              << std::setw(27) << "Mass Communication"
              << "220\n";
    std::cout << std::left
              << std::setw(27) << "Business Administration"
              << "200\n";
    std::cout << std::left
              << std::setw(27) << "Others"
              << "200\n";
}

} // namespace CampusAdmit
