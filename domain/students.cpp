#include "students.h"
#include <iostream>

namespace ctch1330::domain{
    std::vector<Student> Students::students;

    int Students::AddStudent(Student student) 
    {
        student.id = students.size();
        students.push_back(student);
        return 0;
    }

    bool Students::UpdateStudent(const Student student) // passing by value
    {
        if( student.id >= students.size() )
        {
            // bad scenario
            std::cerr << "student id out of bounds" << std::endl;
            return false;
        }

        int index = student.id;
        students[index] = student;
        return true;

    }

    bool Students::GetStudentById(int id, Student& student) // passing by reference
    {
        if( id >= students.size() )
        {
            return false;
        }

        student = students[id];
        return true;

    }

    std::vector<Student> Students::SearchStudentByName(std::string first_name, std::string last_name)
    {
        std::vector<Student> results;

        // fill it up by iterating on entire student body
        for(Student student : students)
        {
            // student variable check it for fname lname match
            if( student.FirstName() == first_name && student.LastName() == last_name )
            {
                results.push_back(student);
            }
        }


        return results;

    }
}