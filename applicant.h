#ifndef CAMPUS_ADMIT_APPLICANT_H
#define CAMPUS_ADMIT_APPLICANT_H

#include <string>
#include <vector>

namespace CampusAdmit {

struct Applicant {
    std::string fullName;
    int jambScore;
    std::string department;
    std::string admissionStatus;
};

void displayApplicants(const std::vector<Applicant>& applicants);

} // namespace CampusAdmit

#endif
