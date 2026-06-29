#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include "applicant.h"
#include "admission.h"
#include "file_manager.h"

void showMenu() {
    std::cout << "\n========================\n";
    std::cout << "     CampusAdmit\n";
    std::cout << "========================\n";
    std::cout << "1. Register Applicant\n";
    std::cout << "2. View Applicants\n";
    std::cout << "3. Save Applicants\n";
    std::cout << "4. Exit\n";
    std::cout << "------------------------\n";
    std::cout << "Choice: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void registerApplicant(std::vector<CampusAdmit::Applicant>& applicants) {
    using CampusAdmit::Applicant;

    clearInputBuffer();

    Applicant a;

    std::cout << "Full name: ";
    std::getline(std::cin, a.fullName);

    std::cout << "Department: ";
    std::getline(std::cin, a.department);

    std::cout << "JAMB score: ";
    std::cin >> a.jambScore;

    if (std::cin.fail()) {
        clearInputBuffer();
        std::cout << "Invalid score. Registration cancelled.\n";
        return;
    }

    int cutOff = CampusAdmit::getCutOff(a.department);
    a.admissionStatus = CampusAdmit::evaluateAdmission(a.jambScore, a.department);
    applicants.push_back(a);

    std::cout << "Cut-off for " << a.department << ": " << cutOff << "\n";
    std::cout << "Status: " << a.admissionStatus << "\n";
}

int main() {
    std::vector<CampusAdmit::Applicant> applicants;
    int choice;
    const std::string filename = "applicants.txt";

    CampusAdmit::loadApplicants(applicants, filename);

    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            clearInputBuffer();
            std::cout << "Invalid input. Enter a number (1-4).\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerApplicant(applicants);
                break;
            case 2:
                CampusAdmit::displayApplicants(applicants);
                break;
            case 3:
                CampusAdmit::saveApplicants(applicants, filename);
                break;
            case 4:
                CampusAdmit::saveApplicants(applicants, filename);
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Enter 1-4.\n";
        }
    }
}
