#include <iostream>
#include <vector>
#include <cstdio>

#define MAP(x) ((sieve[x>>5]>>(x&31))&1)
#define half_sqrt_MAX  46340 
#define half_MAX  46430 

using namespace std;

int main()
{   
    register unsigned int i, j, k;
    vector<int> prime;
    unsigned int sieve[1450];
    prime.push_back(2);
     
    for (i=1; i<half_sqrt_MAX; i++){
        if (MAP(i) == 0)
        {
            for (j=2*i*(i+1), k=2*i+1; j<half_MAX; j+=k)
                sieve[j>>5] |= 1<<(j&31);
     
            prime.push_back(i*2+1);
        }
    }
    
    int input, pow = 1;
    
    while(~scanf("%d",&input)){
    	for(i = 0; input > 1;){
    		if(prime[i] == 0){
    			cout << input << endl;
    			input = 0;
    		} else if(input % prime[i] == 0) {
    			input = input / prime[i];
    			if(input % prime[i] == 0){
    				pow++;
    			} else if(pow != 1) {
    				if(input != 1) cout << prime[i] << "^" << pow << " * ";
    				if(input == 1) cout << prime[i] << "^" << pow << endl;
    				pow = 1;
    			} else if(pow == 1){
    				if(input != 1) cout << prime[i] << " * ";
    				if(input == 1) cout << prime[i] << endl;
    			}
    		} else {
    			i++;
    		}
    	} 
	}
} 

