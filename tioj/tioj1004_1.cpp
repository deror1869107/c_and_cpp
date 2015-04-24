//
//  tioj1004_1.cpp
//  
//
//  Created by Apple on 2015/4/16.
//
//

#include <cstdio>

using namespace std;

int main()
{
    int n;
    int a = 1;
    scanf("%d", &n);
    while(n > (a >> 1)){
        n = n - (a >> 1);
        a = a << 1;
    }
    printf("%d\n", (n << 1) - 1);
}

/*
 1
 1
 3
 1
 3
 5
 7
 1
 3
 5
 7
 9
 11
 13
 15
 1
 3
 ...
*/