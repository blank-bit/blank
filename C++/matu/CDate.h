#include <iostream>
using namespace std;
class Date {
   public:
    Date(int y = 1996, int m = 1, int d = 1){};
    int days(int year, int month){};
    void NewDay();
    void display() { cout << year << "-" << month << "-" << day << endl; }

   private:
    int year;   //年
    int month;  //月
    int day;    // 日
};