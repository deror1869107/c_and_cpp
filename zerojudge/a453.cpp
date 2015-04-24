#include <iostream>
#include <cstdio>

using namespace std;

bool isQ(int num)
{
	if(num < 0) return false;
	for(int i = 0; i <= 2236; ++i){
		if(num == i * i) return true;
	}
	return false;
} 

int main()
{
	int M;
	scanf("%d", &M);
	while(M--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(isQ(b * b - 4 * a * c)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
