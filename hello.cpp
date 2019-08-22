#include <iostream>
#define MONTH 12

enum
{
    DAY31,
    DAY30,
    DAY28,
};
int monthCheck[MONTH] = {DAY31, DAY28, DAY31, DAY30, DAY31, DAY30, DAY31, DAY31, DAY30, DAY31, DAY30, DAY31};

class Date
{
    int year;
    int month;
    int day;

public:
    void set_date(int _year, int _month, int _day) {}
    void day_change(int _day, int numberOfDay)
    {
        day = _day > numberOfDay ? (_day % numberOfDay) : (_day);
    }
    void add_day(int inc)
    {
        int _month = month - 1;
        int _day = day + inc;
        if (monthCheck[_month] == DAY31)
        {
            day_change(_day, 31);
        }
        else if (monthCheck[_month] == DAY30)
        {
            day_change(_day, 30);
        }
        else
        {
            day_change(_day, 28);
        }
    }
    void add_month(int inc) {}
    void add_year(int inc) {}
    void get_date()
    {
        std::cout << year << "/" << month << "/" << day << std::endl;
    }
};

int main()
{

    Date date;
    date.set_date(2012, 2, 28);

    date.get_date();
    return 0;
}