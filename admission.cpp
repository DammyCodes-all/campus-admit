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

} // namespace CampusAdmit
