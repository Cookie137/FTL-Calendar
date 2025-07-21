#include <iostream>
using namespace std;

// function №1
// По номеру года определить, високосный он или нет.
bool IsLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

// function №2
// По номеру года определить количество дней в году (365 или 366).
int GetDaysInYear(int year) {
    if (IsLeapYear(year)) {
        return 366;
    }
    return 365;
}

// function №3
// По номеру года и номеру месяца определить количество дней в месяце.
int GetDaysInMonth(int year, int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (IsLeapYear(year)) {
        return 29;
    }
    return 28;
}

// function №4
// Дана дата (день, месяц и год). Определить, сколько дней прошло до нее, начиная с 1 января данного года.
int GetDaysSinceStartThisYear(int year, int month, int day) {
    int result = 0;
    for (int i = 1; i < month; i++) {
        result += GetDaysInMonth(year, i);
    }
    result += day - 1;
    return result;
}

// function №5
// Дана дата (день, месяц и год). Определить, сколько дней прошло до нее, начиная с 1 января 1-го года.
int GetDaysSinceChristBirthToYear(int year, int month, int day) {
    int result = 0;
    for (int i = 1; i < year; i++) {
        result += GetDaysInYear(i);
    }
    result += GetDaysSinceStartThisYear(year, month, day);
    return result;
}

// function №6
// Даны две даты (день, месяц и год для каждой). Определить, сколько дней прошло между ними.
int GetDaysBetweenTwoDates(int year_1, int month_1, int day_1, int year_2, int month_2, int day_2) {
    int days_1, days_2;
    days_1 = GetDaysSinceChristBirthToYear(year_1, month_1, day_1);
    days_2 = GetDaysSinceChristBirthToYear(year_2, month_2, day_2);
    return abs(days_1 - days_2);
}

// function №7
// Даны две даты (день, месяц и год для каждой) и день недели первой даты (в виде целого числа от 1 до 7 или от 0 до 6).
// Требуется определить день недели второй даты. Вторая дата может быть как позже, так и раньше первой.
int GetWeekdayOfDateByWeekdayAnotherDate(int year_1, int month_1, int day_1, int year_2, int month_2, int day_2, int weekday_1) {
    // weekday = [0, 6];
    int weekday_2, days_1, days_2;
    days_1 = GetDaysSinceChristBirthToYear(year_1, month_1, day_1);
    days_2 = GetDaysSinceChristBirthToYear(year_2, month_2, day_2);
    if (days_1 == days_2) {
        return weekday_1;
    } else if (days_1 > days_2) {
        weekday_2 = (weekday_1 + (7 - (GetDaysBetweenTwoDates(year_1, month_1, day_1, year_2, month_2, day_2) % 7))) % 7;
    } else if (days_1 < days_2) {
        weekday_2 = (weekday_1 + GetDaysBetweenTwoDates(year_1, month_1, day_1, year_2, month_2, day_2)) % 7;
    }
    return weekday_2;
}

int main()
{
    cout << GetWeekdayOfDateByWeekdayAnotherDate(2022, 2, 23, 1, 1, 1, 2) << endl;
    return 0;
}