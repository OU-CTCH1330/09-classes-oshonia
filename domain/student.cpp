#include "student.h"
#include <stdexcept>

namespace ctch1330::domain
{
    Student::Student(int id, std::string first_name, std::string last_name, int born_year) : 
        id{id},
        first_name_{first_name},
        last_name_{last_name}
    {
        if (born_year < 0 || born_year > DateTime::GetCurrentDateTime().year )
        {
            throw std::invalid_argument("born year can't be ngative");
        }        
        born_year_ = born_year;
    }

    std::string Student::GetStudentInformation()
    {
        return std::to_string(id) + ". " + first_name_ + " " + last_name_ + " " + std::to_string( Age() );
    }

    int Student::AddCredits(int new_credits)
    {
        return credits_earned_ += new_credits;
    }



}