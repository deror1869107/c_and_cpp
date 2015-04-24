#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define MAP(x) ((sieve[x>>5]>>(x&31))&1)
#define half_sqrt_MAX  46340 
#define half_MAX  46430 

using namespace std;

int main()
{   
    register unsigned int i, j, k;
    vector<int> prime;
    unsigned int sieve[1451];
    prime.push_back(2);
     
    for (i=1; i<half_sqrt_MAX; i++){
        if (MAP(i) == 0)
        {
            for (j=2*i*(i+1), k=2*i+1; j<half_MAX; j+=k)
                sieve[j>>5] |= 1<<(j&31);
                
            prime.push_back(i*2+1);
        }
    }
    int input;
    while(~scanf("%d", &input)){
    		int flag = 0, input_sqrt = sqrt(input) + 1;
    		for(int i = 0; i < prime.size(); i++){
    			if(input == prime[i]){
    				puts("質數");
    				flag++;
    				break;
    			} else if(input % prime[i] == 0){
    				puts("非質數");
    				flag++;
    				break;
    			} else if(input_sqrt < prime[i]){
    				break;
    			}
    		}
    		if(flag == 0) puts("質數");
	}
    return 0;
}
