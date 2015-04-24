#include <iostream>
#include <cstdio>
#include <vector> 

using namespace std;

int main()
{
	int i, j, k;
	vector<int> cnum;
	for(int i = 1; i <= 10; i++){
		for(int j = i + 1; j <= 10; j++){
			for(int k = j + 1; k <= 10; k++){
				cnum.push_back(i * j + j * k + k * i);
			}
		}
	}
	while(scanf("%d", &k) != EOF){
		int l = 0;
		for(int n = 1; n <= k; n++){
			if(n == cnum[l]){
				l++;
				k++;
			}
		}
		printf("%d\n", k);
	}
	return 0;
} 
