#include <iostream>
#include <iomanip>
#include <map>
#include "applicant.h"

namespace CampusAdmit {

std::string truncate(const std::string& text, size_t width) {
    if (text.size() <= width) return text;
    return text.substr(0, width - 2) + "..";
}

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
                  << std::setw(25) << truncate(a.fullName, 25)
                  << std::setw(22) << truncate(a.department, 22)
                  << std::right
                  << std::setw(8)  << a.jambScore
                  << "  "
                  << std::left
                  << std::setw(15) << a.admissionStatus
                  << "\n";
    }
}

void searchApplicant(const std::vector<Applicant>& applicants) {
    if (applicants.empty()) {
        std::cout << "No applicants registered yet.\n";
        return;
    }

    std::cout << "Enter name to search: ";

    std::string query;
    std::getline(std::cin, query);

    std::vector<const Applicant*> matches;

    for (const auto& a : applicants) {
        if (a.fullName.find(query) != std::string::npos) {
            matches.push_back(&a);
        }
    }

    if (matches.empty()) {
        std::cout << "No applicants found matching \"" << query << "\".\n";
        return;
    }

    std::cout << "\nFound " << matches.size() << " match(es):\n\n";

    std::cout << std::left
              << std::setw(25) << "Name"
              << std::setw(22) << "Department"
              << std::right
              << std::setw(8)  << "Score"
              << "  "
              << std::left
              << std::setw(15) << "Status"
              << "\n";

    std::cout << std::string(72, '-') << "\n";

    for (const auto* a : matches) {
        std::cout << std::left
                  << std::setw(25) << truncate(a->fullName, 25)
                  << std::setw(22) << truncate(a->department, 22)
                  << std::right
                  << std::setw(8)  << a->jambScore
                  << "  "
                  << std::left
                  << std::setw(15) << a->admissionStatus
                  << "\n";
    }
}

void showStatistics(const std::vector<Applicant>& applicants) {
    if (applicants.empty()) {
        std::cout << "No applicants registered yet.\n";
        return;
    }

    int total = applicants.size();
    int admitted = 0;
    int notAdmitted = 0;

    std::map<std::string, int> deptTotal;
    std::map<std::string, int> deptAdmitted;

    for (const auto& a : applicants) {
        deptTotal[a.department]++;

        if (a.admissionStatus == "ADMITTED") {
            admitted++;
            deptAdmitted[a.department]++;
        } else {
            notAdmitted++;
        }
    }

    std::cout << "\n========= Statistics =========\n";
    std::cout << "Total Applicants:  " << total << "\n";
    std::cout << "Admitted:          " << admitted << "\n";
    std::cout << "Not Admitted:      " << notAdmitted << "\n";
    std::cout << "------------------------------\n";
    std::cout << "Per Department:\n\n";

    std::cout << std::left
              << std::setw(25) << "Department"
              << std::right
              << std::setw(8) << "Total"
              << std::setw(12) << "Admitted"
              << "\n";

    std::cout << std::string(45, '-') << "\n";

    for (const auto& [dept, count] : deptTotal) {
        int deptAdmitCount = deptAdmitted[dept];
        std::cout << std::left
                  << std::setw(25) << dept
                  << std::right
                  << std::setw(8) << count
                  << std::setw(12) << deptAdmitCount
                  << "\n";
    }

    std::cout << "==============================\n";
}

} // namespace CampusAdmit
