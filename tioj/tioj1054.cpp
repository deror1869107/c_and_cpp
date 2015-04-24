//
//  tioj1054.cpp
//  
//
//  Created by Apple on 2015/4/20.
//
//

#include <cstdio>

using namespace std;

char day[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
    char inputDay[10];
    int inputNum;
    scanf("%s", inputDay);
    scanf("%d", &inputNum);
    int inputDay_num;
    if(inputDay[0] == 'M') inputDay_num = 1;
    else if(inputDay[0] == 'T'){
        if(inputDay[1] == 'u') inputDay_num = 2;
        else inputDay_num = 4;
    } else if(inputDay[0] == 'W') inputDay_num = 3;
    else if(inputDay[0] == 'F') inputDay_num = 5;
    else if(inputDay[0] == 'S'){
        if(inputDay[1] == 'u') inputDay_num = 7;
        else inputDay_num = 6;
    }
    int ans = (inputDay_num + inputNum) % 7;
    printf("%s\n", day[ans]);
    return 0;
}
