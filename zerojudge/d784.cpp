#include <iostream> //AM11:00~AM11:10 like ®ç¦Ë­]2013pc5
#include <cstdio>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	while(N--){
		int n;
		scanf("%d", &n);
		int mr[100] = {0};
		for(int i = 0; i < n; ++i) scanf("%d", &mr[i]);
		int score = 0, score_max = 0;
		for(int i = 0; i < n; ++i){
			score += mr[i];
			if(score < 0){
				score = 0;
			}
			if(score > score_max) score_max = score;
		}
		if(score == 0){
			score_max = -10001;
			for(int i = 0; i < n; ++i){
				if(mr[i] > score_max) score_max = mr[i];
			}
		}
		printf("%d\n", score_max);
	}
	return 0;
} 
