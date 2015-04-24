#include <iostream>

using namespace std;

int main()
{
	int x, y, ans = 0;
	while(cin >> x >> y){
		int map[x][y], initial[3], next[2];
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				cin >> map[j][i];
			}
		}
		cin >> initial[0] >> initial[1] >> initial[2];
		if(initial[2] == 1){
			next[0] = -1;
			next[1] = 1;
			initial[0] += 1;
		}
		if(initial[2] == 2){
			next[0] = 1;
			next[1] = 1;
		}
		if(initial[2] == 3){
			next[0] = 1;
			next[1] = -1;
			initial[1] += 1;
		}
		if(initial[2] == 4){
			next[0] = -1;
			next[1] = -1;
			initial[0] += 1;
			initial[1] += 1;
		}
		for(int i = 0; i < 3;){
			if(initial[0] + next[0] == 0 || initial[1] + next[1] == 0 || initial[0] + next[0] == x + 2 || initial[1] + next[1] == y + 2){
				i++;
				if(initial[0] + next[0] == 0 || initial[0] + next[0] == x + 2) next[0] = next[0] * (-1);
				if(initial[1] + next[1] == 0 || initial[1] + next[1] == y + 2) next[1] = next[1] * (-1);
			}
			ans += map[(initial[0] * 2 + next[0]) / 2][(initial[1] * 2 + next[1]) / 2];
			initial[0] += next[0];
			initial[1] += next[1];
		}
		cout << ans << endl;
	}
}
