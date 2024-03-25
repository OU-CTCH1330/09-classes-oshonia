#pragma once

namespace ctch1330::domain
{
    struct DateTime
    {
        int year;
        int month;
        int date;

        static DateTime GetCurrentDateTime(); 
    };
}