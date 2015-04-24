#include <cstdio>

using namespace std;

int main()
{
	int n, ans = 1;
	scanf("%d", &n);
    while(n){
        ans += n--;
    }
	printf("%d", ans);
	return 0;
} 
