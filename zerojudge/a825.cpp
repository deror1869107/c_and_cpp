#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int m;
	scanf("%d", &m);
	int num[m]; 
	for(int i = 0; i < m; ++i) scanf("%d", &num[i]);
	sort(num, num + m);
	reverse(num, num + m);
	int a = 0, b = 0;
	for(int i = 0; i < m; ++i){
		if(a <= b) a = num[i] + a * 10;
		else b = num[i] + b * 10;
	}
	printf("%d", a * b);
} 
