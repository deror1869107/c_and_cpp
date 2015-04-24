//
//  tioj1011.cpp
//  
//
//  Created by Apple on 2015/4/20.
//
//

#include <cstdio>

using namespace std;

int min(int a, int b)
{
    if(a < b) return a;
    else return b;
}

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}


int dp(int a, int b)
{
    if(a == b) return 0;
    return dp(max(a, b) / 2, min(a, b)) + 1;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", dp(a, b));
    return 0;
}
