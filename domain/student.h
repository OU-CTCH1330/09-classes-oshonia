#pragma once

#include <string>
#include "../src/constants.h"
#include "date_time.h"

namespace ctch1330::domain
{
    class Student
    {
        public:
            Student() : Student(0, "", "", 0) {}
            Student(int id, std::string first_name, std::string last_name, int age);

            int id;

            std::string GetStudentInformation();

            /// @brief inactivate the student
            void Inactivate() { is_active_ = false; };

            /// @brief activate the student
            void Activate() { is_active_ = true; };

            /// @brief get active status
            /// @return true if active, otherwise false
            bool IsActive() { return is_active_; }              

            /// @brief inspect all enrollment eligibility requirements
            /// @return true if active, otherwise false
            bool IsEligibleForEnrollment();

            int Age() { return DateTime::GetCurrentDateTime().year - born_year_ ; }

            /// @brief add credits to students earned credits
            /// @param new_credits new credits earned
            /// @return updated total credits earned
            int AddCredits(int new_credits);

            // accessors
            int Credits() { return credits_earned_; }
            void Credits( int credits ) { credits_earned_ = credits; }

            void Residency(ctch1330::Residency residency) { residency_ = residency; }
            ctch1330::Residency Residency() { return residency_; }

            void FirstName(std::string first_name) { first_name_ = first_name; }
            std::string FirstName() { return first_name_; }

            void LastName(std::string last_name) { last_name_ = last_name; }
            std::string LastName() { return last_name_; }

        private: 
            std::string first_name_;
            std::string last_name_;
            int born_year_;
            bool is_active_ = true;
            int credits_earned_ = 0;
            ctch1330::Residency residency_ = ctch1330::Residency::kUnknown;
    };
}


