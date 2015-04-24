//
//  b330.cpp
//  
//
//  Created by Apple on 2015/3/6.
//
//

#include <cstdio>

using namespace std;

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j >= 1; j /= 10){
            if(j % 10 == x) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
