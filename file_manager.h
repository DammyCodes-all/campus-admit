#ifndef CAMPUS_ADMIT_FILE_MANAGER_H
#define CAMPUS_ADMIT_FILE_MANAGER_H

#include <string>
#include <vector>
#include "applicant.h"

namespace CampusAdmit {

void saveApplicants(const std::vector<Applicant>& applicants, const std::string& filename);
void loadApplicants(std::vector<Applicant>& applicants, const std::string& filename);

} // namespace CampusAdmit

#endif
