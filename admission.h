#ifndef CAMPUS_ADMIT_ADMISSION_H
#define CAMPUS_ADMIT_ADMISSION_H

#include <string>

namespace CampusAdmit {

int getCutOff(const std::string& department);
std::string evaluateAdmission(int score, const std::string& department);

} // namespace CampusAdmit

#endif
