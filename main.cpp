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
    std::cout << "3. Search Applicant\n";
    std::cout << "4. View Statistics\n";
    std::cout << "5. Save Applicants\n";
    std::cout << "6. Exit\n";
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

    if (a.jambScore < 0 || a.jambScore > 400) {
        std::cout << "Invalid score. JAMB score must be between 0 and 400.\n";
        return;
    }

    int cutOff = CampusAdmit::getCutOff(a.department);
    a.admissionStatus = CampusAdmit::evaluateAdmission(a.jambScore, a.department);
    applicants.push_back(a);

    std::cout << "Cut-off for " << a.department << ": " << cutOff << "\n";
    std::cout << "Status: " << a.admissionStatus << "\n";
}

bool confirmSave() {
    std::cout << "Overwrite applicants.txt? (y/n): ";
    char response;
    std::cin >> response;
    return response == 'y' || response == 'Y';
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
            std::cout << "Invalid input. Enter a number (1-6).\n";
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
                clearInputBuffer();
                CampusAdmit::searchApplicant(applicants);
                break;
            case 4:
                CampusAdmit::showStatistics(applicants);
                break;
            case 5:
                if (confirmSave()) {
                    CampusAdmit::saveApplicants(applicants, filename);
                } else {
                    std::cout << "Save cancelled.\n";
                }
                break;
            case 6:
                CampusAdmit::saveApplicants(applicants, filename);
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Enter 1-6.\n";
        }
    }
}
