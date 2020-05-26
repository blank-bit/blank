#include <iostream>

#include "CDate.h"
using namespace std;

bool Isleapyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}
bool Isbigmonth(int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12) {
        return true;
    } else {
        return false;
    }
}
Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
    if (month < 1 || month > 12) {
        cout << "Invalid month!" << endl;
        month = 1;
    }
    if ((Isbigmonth(month) && day > 31) ||
        (!Isbigmonth(month) && day > 30 && month != 2) || day < 1) {
        cout << "Invalid day!" << endl;
        day = 1;
    }
    if (month == 2) {
        if (Isleapyear(year) && (day > 29 || day < 1)) {
            cout << "Invalid day!" << endl;
            day = 1;
        } else if (day > 28 || day < 1) {
            cout << "Invalid day!" << endl;
            day = 1;
        }
    }
};
void Date::NewDay() {
    day++;
    if (Isbigmonth(month) && day == 32 && month != 12) {
        month++;
        day = 1;
    } else if (month == 12 && day == 32) {
        year++;
        month = 1;
        day = 1;
    } else if (!Isbigmonth(month) && day == 31 && month != 2) {
        month++;
        day = 1;
    } else if (month == 2) {
        if (Isleapyear(year) && day == 30) {
            month++;
            day = 1;
        } else if (day == 29) {
            month++;
            day = 1;
        }
    }
}
int Date::days(int year, int month) {
    if (month == 2) {
        if (Isleapyear(year)) {
            return 29;
        } else {
            return 28;
        }
    }
    if (Isbigmonth(month)) {
        return 31;
    } else {
        return 30;
    }
}