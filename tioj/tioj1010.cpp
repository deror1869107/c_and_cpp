//
//  tioj1010.cpp
//  
//
//  Created by Apple on 2015/4/20.
//
//

#include <cstdio>
#include <cstring>

using namespace std;

int min(int a, int b)
{
    if(a < b) return a;
    else return b;
}

int main()
{
    char p[1001], q[1001], prefix[1001] = "";
    scanf("%s", p);
    scanf("%s", q);
    int len = min(strlen(p), strlen(q));
    int ans = 0;
    for(int i = 0; i < len; ++i){
        prefix[i] = p[i];
        int flag = 0;
        for(int j = 0; j < i + 1; ++j){
            if(prefix[j] != q[strlen(q) - i + j - 1]){
                flag = 1;
                break;
            }
        }
        if(flag == 0) ans = i + 1;
    }
    printf("%d\n", ans);
}
