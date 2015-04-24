#include <cstdio>

using namespace std;

unsigned long long int record[16][16][91] = {};

unsigned long long int light(int i, int n, int m)
{
	if(record[i][n][m] != 0) return record[i][n][m];
	else if(m == 0) record[i][n][m] = 1;
	else if(i < n) record[i][n][m] = light(0, n, m - 1) + light(i + 1, n, m - 1); 
	else if(i == n) record[i][n][m] = light(0, n, m - 1);
	return record[i][n][m];
}

int main()
{
	int n, m;
	while(~scanf("%d %d", &n, &m)){
		printf("%lu\n", light(0, n, m));
	}
	return 0;
}

