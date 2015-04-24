#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int M, N, W, X, Y, Z;
	while(~scanf("%d %d %d %d %d %d", &M, &N, &W, &X, &Y, &Z)){
		int ans = M;
		for(int i = X + Y; i <= W; i += X + Y){
			M = N * Z;
			ans += M;
		}
		M = N;
		for(int i = X; i <= W; i += X + Y){
			M = N * Z;
			ans += M;
		}
		printf("%d\n", ans); 
	}
	return 0;
}
