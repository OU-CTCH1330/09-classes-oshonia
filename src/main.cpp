#include <iostream>
#include "class_roster.h" 

using namespace ctch1330;

int main()
{
	cout << endl << "Welcome to CTCH LMS v 0.03, Year " << current_year << endl;

	while (true)
	{
		int user_selection = 0;
		vector<string> menu;

		try
		{
			menu = GetMenuFromDatabase();
			RenderMainMenu(menu);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
			continue;
		}		
		
		try
		{
			user_selection = GetUserSelection(menu.size());
		}
		catch(const runtime_error& e)
		{
			cerr << e.what() << endl;
			continue;
		}
		
		DispatchSelectedOperation(user_selection);

	}
	
	return 0;
}