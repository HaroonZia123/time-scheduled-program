#include<iostream>
#include<string>
using namespace std;
//ADT foe Time
class tme //class for time storing
{
public:
    int hour;
    int minute;
    int second;
    int day;
    int month;
    int year;
    //Constructer
    tme(int h = 0, int m = 0, int s = 0, int d = 0, int mon = 0, int y = 0)
    {
        hour = h;
        minute = m;
        second = s;
        day = d;
        month = mon;
        year = y;
    }
    std::string tstring(tme* t) //for converting day month and year to string
    {
        return to_string(t->day) + "/" + to_string(t->month) + "/" + to_string(t->year);
    }
    std::string tostring(tme* t) //for converting hour minuteand sec to string
    {
        return to_string(t->hour) + ":" + to_string(t->minute) + ":" + to_string(t->second);
    }
    tme* duration(tme* end, tme* start) //for calculating duration b/w start and end time
    {
        // returns duration between start and end in a time form
        tme* t = new  tme();
        t->second = end->second - start->second;
        int minute_borrow = 0;
        if (t->second < 0)//when start sec greater than end sec
        {
            t->second += 60;
            minute_borrow = 1;
        }
        int hour_borrow = 0;
        t->minute = end->minute - minute_borrow - start->minute;//get minutes of duration
        if (t->minute < 0)//when start minute greater than end min
        {
            t->minute += 60;
            hour_borrow = 1;
        }
        t->hour = end->hour - hour_borrow - start->hour;//get hour of durartion 
        return t;
    }
};

