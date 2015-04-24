#include <iostream>
#include <cstdio>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		map<int, int> fries;
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			int c;
			scanf("%d", &c);
			fries[c]++;
		}
		for(map<int, int>::iterator it = fries.begin(); it != fries.end(); ++it){
			if(it->second > 1){
				fries[it->first * 2]++;
			} 
		} 
		printf("%d\n", fries.size());
	}
}
