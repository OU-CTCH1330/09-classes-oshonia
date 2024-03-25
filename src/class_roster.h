#pragma once

#include <vector>
#include <string>
using namespace std;

//include "std_lib_facilities.h"

namespace ctch1330
{
	constexpr int current_year = 2050;
	constexpr int max_class_size = 6;

	void RenderMainMenu(vector<string> menu);
	void DisplayRoster(vector<string> roster);
	vector<string> AddStudent(vector<string> roster, int max_class_size);
	vector<string> DeleteStudent(vector<string> roster);
	void WaitForUser();
	int GetUserSelection(int max);
	void PrintInvalidFunctionSelectionWarning();
	void DispatchSelectedOperation(int user_selection);
	int GetUserInputWithinIntegerRange(int min, int max);
	tuple<bool, string> ValidateUserInputWithinIntegerRange(const int min, const int max, const int user_input);
	void PrintInvalidFunctionSelectionWarning(int max_function_count);

	extern vector<string> roster;
	extern vector<string> menu_real;

	// please ignore this code for now, it's only designed to imitate database connection and problems
	#pragma region menu_mock

	extern vector<string> menu_mock;

	vector<string> GetMenuFromDatabase();

	#pragma endregion
}
