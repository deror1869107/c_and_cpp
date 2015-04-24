#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int c[6], ans = 0;
		double all = 1;
		for(int i = 0; i < 6; ++i){
			scanf("%d", &c[i]);
			all *= c[i];
		}
		all = sqrt(all);
		for(int i = 0; i < 6; ++i){
			for(int j = i + 1; j < 6; ++j){
				for(int k = j + 1; k < 6; ++k){
					if(c[i] * c[j] * c[k] == all) ans++;
				}
			}
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}
