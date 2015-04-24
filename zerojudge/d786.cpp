#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n = 0;
		float sum = 0;
		scanf("%d", &n);
		int t = n;
		while(t--){
			int num;
			scanf("%d", &num);
			sum += num;
		}
		printf("%0.2f\n", sum / n);
	}
	return 0;
}
