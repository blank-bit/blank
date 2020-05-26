// 实现日期类Date，它能正确表示年、月、日。
// 在代码中引入头文件 
// 它的内容如下：
// class Date{
//  public:
//        Date(int y =1996,int m=1,int d=1){};
//        int days(int year,int month){};
//        void NewDay();
//  void display()
//  {
//     cout<<year<<"-"<<moth<<"-"<<day<<endl;
//  }
//  private:
//       int year; //年
//       int month; //月
//       int day;  // 日
// }

// 需要实现构成函数Date(int y =1996,int m=1,int d=1)
// 在构造函数内依次判断输入的月和日是否合法
// 即月为1~12月中的一个 如果月不合法则输出Invalid month! 然后将月置为1。
// 如果天数不合法，则输出Invalid day! 然后将天数置为1。
// 例如 Date d(1993,13,32);
// 输出：
// Invalid month!回车
// Invalid day!回车
// 再调用 d.display()
// 输出：
// 1993-1-1

// 设计一个NewDay()成员函数，将当前Date表示的日期增加一天。
// 例如：Date d(1991,1,1);
//       d.NewDay();
//       d.display();
// 输出：
// 1991-1-2

// 设计一个days(int year, int month)成员函数,返回指定年月有多少天。
// 例如 d.days(1991,1)
// 返回：
// 31

// 在你的代码中必须实现以上三个方法，例如：
// #include "CDate.h"
// Date::Date(int y=1996,int m=1 ,int d=1){
//     ...
// }
// int  Date::days(int year,int month){
//     ...
// }
// void Date::NewDay(){
//   ...
// }

#include <iostream>
#include "CDate.h"

using namespace std;

Date::Date(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
        if (m > 12 || m < 1) 
        {
            cout << "Invalid month!" << endl;
            m = 1;
        }
        if (d > 31 || d < 1) 
        {
            cout << "Invalid day!" << endl;
            d = 1;
        }
    }
int Date::days(int year,int month)
    {
        if (year % 4 == 0 && month == 2)
        return 29;
        else if (month == 2)
        return 28;
        else if ((month % 2 == 0 && month < 8) || (month % 2 == 1 && month > 7))
        return 30;
        else if ((month % 2 == 1 && month < 8) || (month % 2 == 0 && month > 7))
        return 31;
    }
void Date::NewDay()
    {
        if (year % 4 == 0 && month == 2 && day == 29)
        {month++;  day = 1;}
        else if (month == 2 && day == 28)
        {month++; day = 1;}
        else if (((month % 2 == 0 && month < 8) || (month % 2 == 1 && month > 7)) && day == 30)
        {month++; day = 1;}
        else if (((month % 2 == 1 && month < 8) || (month % 2 == 0 && month > 7)) && day == 31 && month != 12)
        {month++; day = 1;}
        else if (month == 12 && day == 31)
        {month = 1; year++ ; day = 1;}
        else 
            day++;
}