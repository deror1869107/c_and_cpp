#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

typedef pair<int, int> PAIR;

struct CmpByIndex{
	bool operator()(const PAIR& a, const PAIR& b){
		return a.first < b.first;
	}
};

int main()
{
	int m;
	scanf("%d", &m);
	while(m){
		int n, n_min = 0;
		vector<PAIR> abs_formula;
		scanf("%d", &n);
		while(n){
			int a, x;
			scanf("%d %d", &a, &x);
			abs_formula.push_back(make_pair(x / a, a));
			n_min += a;
			n--;
		}
		n_min = n_min / 2 + n_min % 2;
		sort(abs_formula.begin(), abs_formula.end(), CmpByIndex());
		//for(vector<PAIR>::iterator it = abs_formula.begin(); it != abs_formula.end(); it++) cout << it->first << " " << it->second << endl;  //¿é¥Xabs_formula
		int i = 0, x_min;
		for(vector<PAIR>::iterator it = abs_formula.begin(); it != abs_formula.end(); it++){
			i += it->second;
			if(i >= n_min){
				x_min = it->first;
				break;
			}
		}
		int ans = 0;
		for(vector<PAIR>::iterator it = abs_formula.begin(); it != abs_formula.end(); it++){
			ans += abs((x_min - it->first) * it->second);
		}
		printf("%d\n", ans);
		m--;
	}
	return 0;
}
