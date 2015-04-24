#include <iostream>     //~5mins
#include <cstdio>

using namespace std;

double m[50][26] = {0};

double mountain(int n, int next)
{
	if(m[n][next] != 0) return m[n][next];
	else if(next == n){
		m[n][next] = 1;
		return m[n][next] ;
	} else if(next == 0){
		m[n][next] = mountain(n - 1, 1);
		return m[n][next];
	} else {
		m[n][next] = mountain(n - 1, next + 1) + mountain(n - 1, next - 1);
		return m[n][next];
	}
}

int main()
{
	int N;
	//mountain(8, 0);
	while(~scanf("%d", &N)){
		printf("%0.lf\n", mountain(2 * N, 0));
	}
	return 0;
} 
