#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int num[n];
	for(int i = 0; i < n; i++) scanf("%d", &num[i]);
	int ans;
	scanf("%d", &ans);
	int num1 = 0, num2 = 0, num3 = 0;
	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			//for (int k = 1; k < 4; ++k){
				//for(int l = 0; l < 4; ++l){
					for(int m = 0; m <= i; ++m) num1 += num[m] + num1 * 10;
					for(int o = i + 1; o <= j; ++o) num2 += num[o] + num2 * 10;
					for(int p = j + 1; p < n; ++p) num3 += num[p] + num3 * 10;
					printf("%d %d %d\n", num1, num2, num3);
					num1 = 0;
					num2 = 0;
					num3 = 0;
				//}
			//}
		}
	}
}
