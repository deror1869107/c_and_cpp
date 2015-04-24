#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	long int N, M, all = 0;
	list<long int> A;
	scanf("%d %d", &N, &M);
	long int i = N;
	while(i){
		--i;
		long int num;
		scanf("%d", &num);
		A.push_back(num);
		all += num;
	}
	if(all < M){
			printf("GGGGGZ\n");
	} else {
		while(all >= M){
			if(A.front() <= A.back() && all - A.front() >= M){
				all -= A.front();
				A.pop_front();
				--N;
				if(all - A.back() >= M){
					all -= A.back();
					A.pop_back();
					--N;
				}
			}
			else if(A.front() > A.back() && all - A.back() >= M){
				all -= A.back();
				A.pop_back();
				--N;
				if(all - A.front() >= M){
					all -= A.front();
					A.pop_front();
					--N;
				}
			} else break;
		}
		printf("%d\n", N);
	}
	return 0;
}
