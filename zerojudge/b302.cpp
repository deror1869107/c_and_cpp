#include <iostream>
#include <cstdio>

using namespace std;

long long int fib[1000000];

void fib_initial()
{
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i < 1000000; ++i){
		fib[i] = fib[i - 2] + fib[i - 1];
		fib[i] %= 100000007;
	}
}

long long int fibonacci(int n)
{
	long long int ans;
	if(n <= 999999){
		return fib[n];
	}
	if(n % 2 == 0) {
		ans = fibonacci(n / 2 + 1) * fibonacci(n / 2) + fibonacci(n / 2) * fibonacci(n / 2 - 1);
		ans %= 100000007;
		return ans;
	} else {
		ans = fibonacci((n - 1) / 2 + 1) * fibonacci((n - 1) / 2 + 1) + fibonacci((n - 1) / 2) * fibonacci((n - 1) / 2);
		ans %= 100000007;
		return ans;
	}
}

int main()
{
	fib_initial();
	unsigned int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		printf("%d\n", fibonacci(N + 1));
	}
	return 0;
}

