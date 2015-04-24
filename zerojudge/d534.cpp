#include <iostream>  //PM01:52~PM 02:23~PM 02:34
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c, d;
	while(~scanf("%d %d %d %d", &a, &b, &c, &d)){
		int map[2][2] = {0};
		int flag = 0;
		for(int i = 0; i <= min(a, c); i++){
			map[0][0] = i;
			map[1][0] = c - map[0][0];
			map[1][1] = b - map[1][0];
			map[0][1] = d - map[1][1];
			if(map[0][1] == a - map[0][0]){
				int val[4] = {map[0][0], map[0][1], map[1][0], map[1][1]};
				sort(val, val + 4);
				if(val[0] == 0 && val[1] == 1 && val[2] == 2 && val[3] == 3){
					printf("%d %d\n", map[0][0], map[0][1]);
					printf("%d %d\n", map[1][0], map[1][1]);
					break;
				} else flag++;
			} else flag++;
		}
		if(flag == min(a, c) + 1) printf("No solutions.\n");
	}
	return 0;
}
