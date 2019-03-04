// https://www.hackerrank.com/challenges/day-of-the-programmer
#include <array>
#include <tuple>
#include <iomanip>
#include <iostream>

#define MONTH_COUNT 12

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

static int determine_february_length(int year)
{
    if (year < 1918) {
        return (year % 4 == 0) ? 29 : 28; // julian_calendar
    }

    if (year == 1918) {
        return 15; // transitional_calendar
    }

    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28; // gregorian_calendar
}

static std::tuple<int, int, int> calculate_date(int day, int year)
{
    std::array<int, MONTH_COUNT> days = {31, determine_february_length(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month = 0;
    for(; day - days[month] > 0; day -= days[month], ++month);

    return std::make_tuple(day, month + 1, year);
}

int main()
{
    int year;
    std::cin >> year;

    std::tuple<int, int, int> date = calculate_date(256, year);

    std::cout << std::setfill('0') << std::setw(2) << std::get<0>(date) << ".";
    std::cout << std::setfill('0') << std::setw(2) << std::get<1>(date) << ".";
    std::cout << std::get<2>(date) << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
