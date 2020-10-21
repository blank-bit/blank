// 实现时钟类Clock,(24小时制，0~23)

// 实现构造函数Clock(int h,int m, int s)
// 构造函数设置时、分、秒。设置前先判断传入的时分秒是否合法，如果不合法将其设置为0
// 例如 Clock c(25,61,-1);
//       c.ShowTime();
// 输出：
// Now:0:0:0

// 实现SetAlarm 成员函数，设置闹钟设置时同样要判断传入的时分秒是否合法,但闹钟的时分秒可以为负数，表示关闭闹钟

// 实现run成员函数，将现在的时间秒数加一 ，然后检查闹钟时间是否到 ，如果闹钟触发，则输出"Plink!plink!plink!..."
// 例如：
// Clock c(2,3,4);
// c.SetAlarm(2,3,5);
// c.run();
// 输出：
// Plink!plink!plink!...回车

// 在你的代码中需实现上述三个方法，例如：
// #include "Clock.h"
// Clock::Clock(int h,int m, int s){
// ...
// }
// void Clock::SetAlarm(int h,int m, int s){
// ...
// }

// void Clock::run(){
//   ...
// }

#include <iostream>
#include <cstdlib>
#include "Clock.h"

bool IsRhour(int hour)
{
    if(hour > 23 || hour < 0)
        return false;
    else 
        return true;
}

bool IsRmin(int minute)
{
    if(minute > 60 || minute < 0)
        return false;
    else 
        return true;
}

bool IsRsec(int second)
{
    if(second > 60 || second < 0)
        return false;
    else 
        return true;
}


Clock::Clock(int h,int m, int s)
{
    hour = h;
    minute = m;
    second = s;
    if(!IsRhour(hour)) hour = 0;
    if(!IsRmin(minute)) minute = 0;
    if(!IsRsec(second)) second = 0;
}
void Clock::SetAlarm(int h,int m,int s)
{
    Ahour = h;
    Aminute = m;
    Asecond = s;
    if(hour > 23) hour = 0;
    if(minute > 60) minute = 0;
    if(second > 60) second = 0;
}

void Clock::run()
{
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
    if (second == Asecond && minute == Aminute && hour == Ahour) {
        cout << "Plink!plink!plink!..." << endl;
    }
}

