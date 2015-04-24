#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int n;
	while(~scanf("%d", &n)){
		vector<int> A;
		while(n){
			--n;
			int num;
			scanf("%d", &num);
			A.push_back(num);
		}
		int n_center;
		n_center = A.size() / 2 + A.size() % 2;
		sort(A.begin(), A.end());
		printf("A=%d", A[n_center - 1]);
		if(A.size() % 2 == 0 && A[n_center - 1] != A[n_center]) for(int i = A[n_center - 1] + 1; i <= A[n_center]; ++i) printf("¡B%d", i);
		printf("\n");
		A.clear();
	}
	return 0;
} 
