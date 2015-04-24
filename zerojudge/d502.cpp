#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int c1, c2, c3, c4;
	while(~scanf("%d %d %d %d", &c1, &c2, &c3, &c4)){
		int ans = 0;
		if(c4 != 0){
			ans += c4;
			c4 = 0;
		}
		if(c2 / 8 > 0){
			ans += c2 / 8;
			c2 %= 8;
		}
		if(c3 != 0){
			ans += c3;
		}
		if(c2 > 0){
			ans += 1;
			c1 -= (64 - c2 * 8);
		}
		if(c1 >= 37 * c3){
			c1 -= 37 * c3;
			ans += ceil((double)c1 / 64);
		}
		printf("%d\n", ans);
	}
	return 0;
}
