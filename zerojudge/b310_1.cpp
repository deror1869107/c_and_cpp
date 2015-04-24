#include <iostream>                              //deque¨Â¿Y•[ß¿ 
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	float N, M, all = 0;
	vector<float> A;
	scanf("%f %f", &N, &M);
	while(N--){
		float num;
		scanf("%f", &num);
		A.push_back(num);
		all += num;
	}
	if(all < M){
			printf("GGGGGZ\n");
	} else {
		deque<float> A_deque;
		float sum = 0, ans = 0, ans_min = M;
		for(int i = 0; i < A.size(); i++){
			if(sum < M){
				A_deque.push_back(A[i]);
				sum += A[i];
				ans++;
			} else {
				if(ans < ans_min) ans_min = ans;
				sum -= A_deque.front();
				A_deque.pop_front();
				ans--;
				i--;
			}
		}
		printf("%.0f\n", ans_min);
	}
	return 0;
}
