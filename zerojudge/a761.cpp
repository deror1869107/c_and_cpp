#include <iostream> //Strart 01:30 End 02:44
#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <iterator>

using namespace std;

typedef pair<int, int> PAIR;

int main()
{
	int N;
	scanf("%d", &N);
	map<int, vector<PAIR> > ram;
	while(N){
		N--;
		char str[10];
		scanf("%s", &str);
		if(str[0] == 'l'){
			int c, flag = 0;
			scanf("%d", &c);
			for(map<int, vector<PAIR> >::iterator it = ram.begin(); it != ram.end(); ++it){
				for(vector<PAIR>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1){
					if(c >= it1->first && c <= it1->second){
						printf("load from region %d\n", it->first);
						++flag;
						break;
					}	
	 			}
	 			if(flag != 0) break;
			}
			if(flag == 0) printf("fail to load from %d\n", c);
			flag = 0;
		}
		if(str[0] == 'm'){
			int region, a, b, flag = 0;
			scanf("%d %d %d", &region, &a, &b);
			for(map<int, vector<PAIR> >::iterator it = ram.begin(); it != ram.end(); ++it){
				for(vector<PAIR>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1){
					if((a <= it1->first && b >= it1->first) || (a <= it1->second && b >= it1->second) || (a <= it1->first && b >= it1->first) ||  (a >= it1->first && b <= it1->second)){
						printf("fail to create region %d, overlap with region %d\n", region, it->first);
						++flag;
						break;
					}
					
	 			}
	 			if(flag != 0) break;
			}
			if(flag == 0){
				ram[region].push_back(make_pair(a, b));
				printf("region %d created\n", region);
			}
		}
		if(str[0] == 's'){
			int d, flag = 0;
			scanf("%d", &d);
			for(map<int, vector<PAIR> >::iterator it = ram.begin(); it != ram.end(); ++it){
				for(vector<PAIR>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1){
					if(d >= it1->first && d <= it1->second){
						printf("store to region %d\n", it->first);
						++flag;
						break;
					}	
	 			}
	 			if(flag != 0) break;
			}
			if(flag == 0) printf("fail to store to %d\n", d);
			flag = 0;
		}
	}
	return 0;
}
