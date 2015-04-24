#include <iostream>
#include <cstdio>

using namespace std;

int reproduce(int M, int t_i, int t_f, int X, int Y, int Z, char flag)
{
	if(flag == 'm'){
		if(t_i + Y <= t_f) return reproduce(M * Z, t_i + Y, t_f, X, Y, Z, 'i') + reproduce(M, t_i + Y, t_f, X, Y, Z, 'm');
		else return M;
	}
	if(flag == 'i'){
		if(t_i + X <= t_f) return reproduce(M, t_i + X, t_f, X, Y, Z, 'm');
		else return M;
	}
}

int main()
{
	int M, N, W, X, Y, Z;
	while(~scanf("%d %d %d %d %d %d", &M, &N, &W, &X, &Y, &Z)){
		printf("%d\n", reproduce(M, 0, W, X, Y, Z, 'm') + reproduce(N, 0, W, X, Y, Z, 'i'));
	}
	return 0;
} 
