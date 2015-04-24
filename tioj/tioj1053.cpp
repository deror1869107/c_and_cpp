//
//  tioj1053.cpp
//  
//
//  Created by Apple on 2015/4/20.
//
//

#include <cstdio>

using namespace std;

int main()
{
    int p, q;
    scanf("%d %d", &p, &q);
    if(!((p % q) && (q % p))) printf("Y\n");
    else printf("N\n");
    return 0;
}
