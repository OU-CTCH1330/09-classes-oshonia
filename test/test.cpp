#include <iostream>
#include "catch_amalgamated.hpp"
#include "../domain/student.h"
#include "../domain/students.h"
#include "../src/constants.h"

#include <vector>

#define CONFIG_CATCH_MAIN

using Student = ctch1330::domain::Student;
using Students = ctch1330::domain::Students;

ctch1330::domain::Student giorgi{0, "giorgi", "shonia", 1976};
ctch1330::domain::Student olga{1, "olga", "shonia", 1974};

// this is a sanbox case. 
TEST_CASE("scratch", "[scratch]")
{

	SECTION("sandbox 1")
	{
		// you can put your code in this block. you can 
		// run it by launching "Test an individual test" task
		// or debug by selecting "Debug an individual test" from debug dropdown.
		// In both cases select "scratch" when asked

		// purpose here is to provide a place to quickly test small ideas and code

		std::vector<Student> student_body { giorgi, olga };

		std::vector<Student*> roster;
		// roster[0] = &student_body[0];
		roster.push_back(&student_body[0]);
		student_body[0].FirstName("ggg");
		std::cout << roster[0]->GetStudentInformation() << std::endl;
		
	}

}	

// this test case is for Student class, you dont have to do anything here for assignment 09.
TEST_CASE("individual student tests", "[student]")
{

	SECTION("initiation")
	{
		REQUIRE( giorgi.GetStudentInformation() == "0. giorgi shonia 48" );
	}

	SECTION("credits")
	{
		giorgi.Credits(0);
		giorgi.AddCredits(3);
		giorgi.AddCredits(2);
		REQUIRE( giorgi.Credits() == 5 );
	}

	SECTION("inactivity")
	{
		giorgi.Inactivate();
		REQUIRE( giorgi.IsActive() == false );
	}

	SECTION("residency")
	{
		giorgi.Residency(ctch1330::Residency::kStateResident);
		REQUIRE( giorgi.Residency() == ctch1330::Residency::kStateResident );
	}

}	

// this is the test case for assignment 09
// target class is Students
TEST_CASE("students body tests", "[students]")
{   
	// setup. test_case is executed executed individually for each SECTION below
	// thus this three lines are pre-executed before each section
	// the result is clean environment, so impact of previous sections does not contaminate the next
	Students::Reset();
	Students::AddStudent(giorgi);
	Students::AddStudent(olga);	

	// each section contains tests for a single target function. 
	// for instance target function of this section is AddStudent()
	SECTION("test AddStudent()")
	{
		REQUIRE( Students::GetStudentBodySize() == 2 );

		Students students;
		REQUIRE( students[0].GetStudentInformation() == "0. giorgi shonia 48" );
	}	

	// notice, this section tests update functionality twice. 
	// once for "positive path", adding a valid update
	// the second time for negative path, for trying (and failing) an invalid update
	SECTION("test UpdateStudent()")
	{
		int student_id = 1;
		Student student{student_id, "masha", "shonia", 2006};
		bool result = Students::UpdateStudent(student);
		REQUIRE( result == true );	// update reports successful

		Student new_student;
		bool result2 = Students::GetStudentById(student_id, new_student);
		REQUIRE( new_student.GetStudentInformation() == "1. masha shonia 18" );	// update was indeed successful

		// need to test a negative test
		int student_body_size = Students::GetStudentBodySize();
		Student nonexistent_student{student_body_size, "na", "na", 2000};
		bool result3 = Students::UpdateStudent(nonexistent_student);
		REQUIRE( result3 == false );	// update reports failed

	}

	// notice id search is using "pass by reference"
	// lecture for assignment review has a discussion for this
	SECTION("test GetStudentById()")
	{
		Student student;
		bool result = Students::GetStudentById(0, student);
		REQUIRE( result == true );
		REQUIRE( student.GetStudentInformation() == "0. giorgi shonia 48" );
	}

	// search by name should be able to retrieve (all) matches to first and last name submitted
	// this means looping through the entire student body and collecting all matching students. 
	SECTION("test SearchStudentByName()")
	{
		auto students = Students::SearchStudentByName("olga", "shonia");
		REQUIRE( students.size() == 1 );
		REQUIRE( students[0].id == 1 );
	}	
}
