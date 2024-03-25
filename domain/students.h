#pragma once

#include <vector>
#include "student.h"

namespace ctch1330::domain{
    class Students
    {
        public:

            /// @brief add new student to "database"
            /// @param student student to be added
            /// @return id of added student
            static int AddStudent(Student student); 

            /// @brief update student to "database"
            /// @param student student to be modified
            /// @return true if successful, otherwise false
            static bool UpdateStudent(const Student student);

            /// @brief search db for student by id
            /// @param id id of the student to be searched
            /// @return student object if found, null otherwise
            static bool GetStudentById(int id, Student& student);

            /// @brief search student by first and last name
            /// @param first_name first name of a student
            /// @param last_name last name of a student
            /// @return vector of students that match, empty vector if no match
            static std::vector<Student> SearchStudentByName(std::string first_name, std::string last_name);

            /// @brief get student body size
            /// @return student body size
            static int GetStudentBodySize() { return students.size(); }

            /// @brief clear student body of all entrie
            static void Reset() { students.clear(); }            

            Student operator[](int index) { return students[index]; }

        private:
        
            // mockup of database data
            static std::vector<Student> students;
    };
}