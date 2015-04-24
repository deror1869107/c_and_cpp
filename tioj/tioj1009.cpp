//
//  tioj1009.cpp
//  
//
//  Created by Apple on 2015/4/20.
//
//

#include <cstdio>

using namespace std;

struct Time
{
    int hour, minute, second;
    Time(){hour = 0; minute = 0; second = 0;}
    Time(int a, int b, int c){
        hour = a;
        minute = b;
        second = c;
    }
    
    Time operator-(const Time &p)const{
        Time time = Time();
        time.second = second - p.second;
        time.minute = minute - p.minute;
        time.hour = hour - p.hour;
        if(time.second < 0){
            time.second += 60;
            time.minute--;
        }
        if(time.minute < 0){
            time.minute += 60;
            time.hour--;
        }
        if(time.hour < 0){
            time.hour += 24;
        }
        return time;
    }
};

void print(const Time &p)
{
    if(p.hour < 10) printf("0%d:", p.hour);
    else printf("%d:", p.hour);
    if(p.minute < 10) printf("0%d:", p.minute);
    else printf("%d:", p.minute);
    if(p.second < 10) printf("0%d", p.second);
    else printf("%d", p.second);
    printf("\n");
    return;
}

int main()
{
    Time time1, time2;
    scanf("%d:%d:%d", &time1.hour, &time1.minute, &time1.second);
    scanf("%d:%d:%d", &time2.hour, &time2.minute, &time2.second);
    Time ans = time2 - time1;
    print(ans);
    return 0;
}
