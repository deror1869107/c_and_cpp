#include <iostream> //AM10:14~10:25FT //InDevelopment 
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

typedef pair<float, float> PAIR;

struct CmpByValue{
	bool operator()(const PAIR& a, const PAIR& b){
		return a.second < b.second;
	}
};

float time1;

struct CmpByTime{
	bool operator()(const PAIR& a, const PAIR& b){
		return a.first + a.second * time1 < b.first + b.second * time1;
	}
};

int main()
{
	int N;
	scanf("%d", &N);
	vector<PAIR> fort;
	while(N--){
		float a, b;
		scanf("%f %f", &a, &b);
		fort.push_back(make_pair(a, b));
	}
	float ans = 0;
	sort(fort.begin(), fort.end(), CmpByValue());
	for(vector<PAIR>::iterator it = fort.begin(); it != fort.end(); ++it){
		if(it->second == 0){
			ans += it->first;
			fort.erase(it);
		} else break;
	}
	//for(vector<PAIR>::iterator it = fort.begin(); it != fort.end(); ++it) printf("%0.f %0.f\n", it->first, it->second);
	time1 = 0;
	while(fort.size() != 0){
		sort(fort.begin(), fort.end(), CmpByTime());
		vector<PAIR>::iterator it = fort.begin();
		//for(vector<PAIR>::iterator it = fort.begin(); it != fort.end(); ++it) printf("%0.f %0.f\n", it->first, it->second);
		ans += it->first + it->second * time1;
		time1 += it->first + it->second * time1;
		fort.erase(it);
		
	}
	for(; ans > 100000007; ans -= 100000007){
	}
	printf("%0.f\n", ans);
}
