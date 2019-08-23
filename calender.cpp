#include <iostream>
#define MONTH 12
#define DAY31 31
#define DAY30 30
#define DAY29 29
#define DAY28 28

class Date
{
    int year;
    int month;
    int day;

public:
    void set_date(int _year, int _month, int _date);
    void add_day(int inc);
    void add_month(int inc);
    void add_year(int inc);
    void show_date();

    Date(int _year, int _month, int _day)
    {
        year = _year;
        month = _month;
        day = _day;
    }
};
void Date::set_date(int _year, int _month, int _day)
{
    year = _year;
    month = _month;
    day = _day;
}

void Date::add_day(int inc)
{

    int month_day[MONTH] = {DAY31, DAY28, DAY31, DAY30, DAY31, DAY30, DAY31, DAY31, DAY30, DAY31, DAY30, DAY31};
    int index_month = month;
    int index_day = day;

    if (month_day[index_month] >= inc + day)
    {
        day = index_day + inc;
        return;
    }
    else
    {
        add_month(1);
        index_day = 1;
        inc = inc + day - month_day[index_month - 1] - 1;
        index_month++;
    }

    while (true)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            month_day[1] = DAY29; // 윤년
        }
        else
        {
            month_day[1] = DAY28;
        }

        if (inc + index_day >= month_day[index_month - 1])
        {
            add_month(1);
            inc = inc - month_day[index_month - 1];
        }
        else if (inc + index_day < month_day[index_month - 1])
        {
            day = index_day + inc;
            break;
        }

        index_month++;
        if (index_month > 12)
        {
            index_month -= 12;
            add_year(1);
        }
    }
}
void Date::add_month(int inc)
{
    add_year((inc + month - 1) / 12);
    month = month + inc % 12;
    month = (month == 12) ? 12 : month % 12;
}
void Date::add_year(int inc)
{
    year += inc;
}
void Date::show_date()
{
    std::cout << year << "/" << month << "/" << day << std::endl;
}

int main()
{

    Date date(2012, 3, 15);

    date.show_date();
    date.add_day(50);
    date.show_date();
    date.add_day(40);
    date.show_date();
    return 0;
}