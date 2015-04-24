#include <iostream> //Strart 01:30 End 02:44
#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

using namespace std;

typedef pair<int, int> PAIR;

struct FindSecond {
    FindSecond(int i) : toFind(i) { }
    int toFind;
    bool operator() 
        ( const PAIR &p ) {
            return p.second==toFind;
    }
};

int main()
{
	int N;
	scanf("%d", &N);
	vector<PAIR> ram;
	while(N){
		N--;
		char str[10];
		scanf("%s", &str);
		if(str[0] == 'l'){
			int c;
			scanf("%d", &c);
			vector<PAIR>::iterator it = find_if(ram.begin(), ram.end(), FindSecond(c));
			if(it == ram.end()) printf("fail to load from %d\n", c);
			else printf("load from region %d\n", it->first);
		}
		if(str[0] == 'm'){
			int region, a, b, flag = 0, region_exist = 0;
			scanf("%d %d %d", &region, &a, &b);
			for(int i = a; i <= b; i++){
				vector<PAIR>::iterator it = find_if(ram.begin(), ram.end(), FindSecond(i));
				if(it == ram.end()) ++flag;
				if(it != ram.end()) region_exist = it->first;
			}
			if(flag == b - a + 1){
				for(int i = a; i <= b; i++) ram.push_back(make_pair(region, i));
				printf("region %d created\n", region);
			}
			if(flag != b - a + 1){
				printf("fail to create region %d, overlap with region %d\n", region, region_exist);
			}
		}
		if(str[0] == 's'){
			int d;
			scanf("%d", &d);
			vector<PAIR>::iterator it = find_if(ram.begin(), ram.end(), FindSecond(d));
			if(it == ram.end()) printf("fail to store to %d\n", d);
			else printf("store to region %d\n", it->first);
		}
	}
	return 0;
}
