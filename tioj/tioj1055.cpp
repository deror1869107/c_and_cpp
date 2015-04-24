//
//  tioj1055.cpp
//  
//
//  Created by Apple on 2015/4/20.
//
//

#include <cstdio>

using namespace std;

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    if(A >= B){
        for(; A >= B; --A){
            for(int i = 0; i < A; ++i) putchar('*');
            putchar('\n');
        }
    } else {
        for(; A <= B; ++A){
            for(int i = 0; i < A; ++i) putchar('*');
            putchar('\n');
        }
    }
    return 0;
}
