#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int map[N][N];
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) map[i][j] = 0;
	int t = -1;
	char c[1];
	while(t < 4){
		scanf("%c", &c);
		if(c[0] == '\n') ++t;
		map[t][c[0] - '0' - 1] = 1;
	}
	int sum = 0, point[4 * N + 2][2];
		for(int i = 0; i < 4 * N + 2; i++) for(int j = 0; j < 2; j++) point[i][j] = -1;
	for(int i = 0; i < N; i++){
		int line = 0, j;
		for(j = 0; j < N; j++) line += map[i][j];
		if(line == 4 || line == 0) {
			sum++;
			point[sum - 1][0] = 4 * i + 1;
			point[sum - 1][1] = 4 * i + 4;
		}
	}
	for(int j = 0; j < N; j++){
		int line = 0, i;
		for(int i = 0; i < N; i++) line += map[i][j];
		if(line == 4 || line == 0) {
			sum++;
			point[sum - 1][0] = 4 * 0 + j + 1;
			point[sum - 1][1] = 4 * 3 + j + 1;
		}
	}
	for(int i = 2; i < 2 * N - 3; i++){
		int line = 0;
		for(int j = 0; j < i + 1; j++) line += map[j][abs(i - j)];
		if(line == i + 1 || line == 0){
			sum++;
			int x = 0;
			if(i > 3) x = 3;
			point[sum - 1][0] = 4 * x + i + 1;
			point[sum - 1][1] = 4 * i + x + 1;
		}
	}
	for(int i =  2 * N - 3;; i > 2 i++){
		int line = 0;
		for(int j = 0; j < i + 1; j++) line += map[j][abs(i - j)];
		if(line == i + 1 || line == 0){
			sum++;
			int x = 0;
			if(i > 3) x = 3;
			point[sum - 1][0] = 4 * x + i + 1;
			point[sum - 1][1] = 4 * i + x + 1;
		}
	}
	printf("%d\n", sum);
	for(int i = 0; i < 4 * N + 2; i++){
		if(point[i][0] == -1) break;
		printf("(%0.lf,%d)", ceil((double)point[i][0] / 4), (point[i][0] - 1) % 4 + 1);
		printf("(%0.lf,%d)", ceil((double)point[i][1] / 4), (point[i][1] - 1) % 4 + 1);
		printf("\n");
	}
	return 0;
}
