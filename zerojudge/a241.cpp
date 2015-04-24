#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int m;
	scanf("%d", &m);
	while(m){
		int n, ans = 0;
		scanf("%d", &n);
		for(int j = n; j >= 1; j /= 10){
			for(int i = j; i >= 2; ans++) i /= 2;
			for(int i = j; i >= 5; ans++) i /= 5;
			if(j / 10 > 0) ans++;                
		}
		printf("%d\n", ans);
		m--;
	}
	return 0;
}
