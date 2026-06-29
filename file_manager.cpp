#include <fstream>
#include <iostream>
#include <sstream>
#include "file_manager.h"

namespace CampusAdmit {

void saveApplicants(const std::vector<Applicant>& applicants, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << " for writing.\n";
        return;
    }

    for (const auto& a : applicants) {
        file << a.fullName       << "|"
             << a.department     << "|"
             << a.jambScore      << "|"
             << a.admissionStatus << "\n";
    }

    std::cout << "Saved " << applicants.size() << " applicant(s) to " << filename << "\n";
}

void loadApplicants(std::vector<Applicant>& applicants, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "No existing data file found. Starting fresh.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);
        Applicant a;

        std::getline(ss, a.fullName,       '|');
        std::getline(ss, a.department,     '|');

        std::string scoreStr;
        std::getline(ss, scoreStr,         '|');
        a.jambScore = std::stoi(scoreStr);

        std::getline(ss, a.admissionStatus, '|');

        applicants.push_back(a);
    }

    std::cout << "Loaded " << applicants.size() << " applicant(s) from " << filename << "\n";
}

} // namespace CampusAdmit
