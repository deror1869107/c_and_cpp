//
//  a695.cpp
//  
//
//  Created by Apple on 2015/3/6.
//
//

#include <cstdio>
#include <vector>
#include <iterator>

#define sqrt_MAX 46341

using namespace std;

void factor(int n, vector<int>& prime)
{
    for(int i = 0; i < prime.size(); ++i){
        if(n == prime[i]){
            printf("%d\n", n);
            return;
        } else if(n % prime[i] == 0){
            factor(n / prime[i], prime);
            return;
        } else if(i == prime.size() - 1){
            printf("%d\n", n);
            return;
        }
    }
}

int main()
{
    unsigned int sieve[sqrt_MAX] = {0};
    vector<int> prime;
    
    for(int i = 2; i <= sqrt_MAX; ++i){
        if(sieve[i] == 0){
            prime.push_back(i);
            for(int j = i * i; j <= sqrt_MAX; j += i){
                sieve[j] = 1;
            }
        }
    }
    //for(vector<int>::iterator it = prime.begin(); it != prime.end(); ++it) printf("%d\n", *it);
    int n;
    scanf("%d", &n);
    factor(n, prime);
    return 0;
}
