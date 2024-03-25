#include "date_time.h"
#include <time.h>

namespace ctch1330::domain
{
    DateTime DateTime::GetCurrentDateTime()
    {
        auto current_time = time(NULL);
		auto timeptr = localtime(&current_time);
        ctch1330::domain::DateTime current_date_time{timeptr->tm_year+1900, timeptr->tm_mon, timeptr->tm_mday};
		return current_date_time;        
    }

}