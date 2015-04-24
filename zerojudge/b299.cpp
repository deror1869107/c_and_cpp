#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T, N, M, w, w_min;
	while(~scanf("%d", &T)){
		for(int j = 0; j < T; j++){
			scanf("%d %d", &N, &M);
			scanf("%d", &w);
			w_min = w;
			for(int i = 1; i < M; i++){
				cin >> w;
				if(w < w_min) w_min = w;
			}
			if(w_min < N){
				cout << "NOOOO!!! JACKY XX!" << endl;
			} else cout << "YEEES!!! INKER!" << endl;
		}
	}
	return 0;
}

