#include "students.h"
#include <iostream>

namespace ctch1330::domain{

    // this initializes statis member that is declared in header file
    std::vector<Student> Students::students;

    int Students::AddStudent(Student student)
    { 
        student.id = Students::students.size();
        students.push_back(student);

        return 0;
    }

    bool Students::UpdateStudent(const Student student) 
    {
        if ( student.id >= students.size() )
        {
            // such messages typically would be logged
            std::cerr << "student id out of bounds" << std::endl;
            return false;
        }
        
        int index = student.id;
        students[index] = student;
        return true;
    }

    bool Students::GetStudentById(int id, Student& student) 
    {
        if ( id >= students.size() )
        {
            return false;
        }

        student = students[id];
        return true;        
    }

    std::vector<Student> Students::SearchStudentByName(std::string first_name, std::string last_name) 
    {
        std::vector<Student> results;
        for (Student student : students)
        {
            if ( student.FirstName() == first_name && student.LastName() == last_name)
            {
                results.push_back(student);
            }
            
        }

        return results;
        
    }




}