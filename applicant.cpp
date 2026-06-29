#include <iostream>
#include <iomanip>
#include "applicant.h"

namespace CampusAdmit {

void displayApplicants(const std::vector<Applicant>& applicants) {
    if (applicants.empty()) {
        std::cout << "No applicants registered yet.\n";
        return;
    }

    std::cout << "\n"
              << std::left
              << std::setw(25) << "Name"
              << std::setw(22) << "Department"
              << std::right
              << std::setw(8)  << "Score"
              << "  "
              << std::left
              << std::setw(15) << "Status"
              << "\n";

    std::cout << std::string(72, '-') << "\n";

    for (const auto& a : applicants) {
        std::cout << std::left
                  << std::setw(25) << a.fullName
                  << std::setw(22) << a.department
                  << std::right
                  << std::setw(8)  << a.jambScore
                  << "  "
                  << std::left
                  << std::setw(15) << a.admissionStatus
                  << "\n";
    }
}

} // namespace CampusAdmit
