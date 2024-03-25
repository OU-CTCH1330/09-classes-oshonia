#include "class_roster.h"

using namespace ctch1330;
    
vector<string> ctch1330::roster = 
{ 
    "Giorgi", 
    "Franco", 
    "Umberto", 
    "Nino", 
    "Jean-Luc"	
};

vector<string> ctch1330::menu_real = 
{
    "1. Display roster",
    "2. Add a student",
    "3. Delete a student",
    "4. Exit" 
};

vector<string> ctch1330::menu_mock = {};

vector<string> ctch1330::GetMenuFromDatabase()
{
    return (rand() % 2) ?
    menu_real
    : menu_mock;
}