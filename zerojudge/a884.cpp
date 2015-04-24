#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int m;
	scanf("%d", &m);
	while(m--){
		char str1[10001], str2[10001], ans[10001];
		scanf("%s %s", &str1, &str2);
		int flag = 0;
		for(int i = 0; i < 10001; i++){
			if(str1[i] - flag >= str2[i]){
				ans[i] = str1[i] - str2[i] - flag + '0';
				flag = 0;
			} else {
				ans[i] = str1[i] - str2[i] + 10 - flag + '0';
				flag = 1;
			}
		}
		if(flag == 1) printf("-");
		printf("%s\n", ans);
	}
}
