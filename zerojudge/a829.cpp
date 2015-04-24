//InDevelopment
#include <iostream>
#include <cstdio>
#include <map> 
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

typedef pair<int, int> PAIR;

struct CmpByValue{
	bool operator()(const PAIR& a, const PAIR& b){
		return a.second < b.second;
	}
};

int main()
{
	int n, D;
	scanf("%d %d", &n, &D);
	while(n){
		--n;
		int s;
		scanf("%d", &s);
		map<int, int> schedule_core, schedule_ram, schedule_bw;
		vector<int> core_t, ram_t, bw_t, core, ram, bw;
		while(s){
			--s;
			int t_d, t_s, t_h, r_core, r_ram, r_bw;
			int t_d_initialed = 0, t_s_initialed = 0, t_min = 30000, t_max;
			scanf("%d %d %d %d %d %d", &t_d, &t_s, &t_h, &r_core, &r_ram, &r_bw);
			for(int i = 0; i <= t_h; ++i){
				core_t.push_back(t_d * 24 + t_s + i);
				core.push_back(r_core);
				ram_t.push_back(t_d * 24 + t_s + i);
				ram.push_back(r_core);
				bw_t.push_back(t_d * 24 + t_s + i);
				bw.push_back(r_core);	
			}
		}
		vector<PAIR> schedule_core_vec(schedule_core.begin(), schedule_core.end());
		vector<PAIR> schedule_ram_vec(schedule_ram.begin(), schedule_ram.end());
		vector<PAIR> schedule_bw_vec(schedule_bw.begin(), schedule_bw.end());
		sort(schedule_core_vec.begin(), schedule_core_vec.end(), CmpByValue());
		sort(schedule_ram_vec.begin(), schedule_ram_vec.end(), CmpByValue());
		sort(schedule_bw_vec.begin(), schedule_bw_vec.end(), CmpByValue());
		vector<PAIR>::iterator it_core = schedule_core_vec.end();
		vector<PAIR>::iterator it_ram = schedule_ram_vec.end();
		vector<PAIR>::iterator it_bw = schedule_bw_vec.end();
		printf("%d %d %d", it_core->second, it_ram->second, it_bw->second);
		schedule_core.clear();
		schedule_ram.clear();
		schedule_bw.clear();
		schedule_core_vec.clear();
		schedule_ram_vec.clear();
		schedule_bw_vec.clear();
	}
	return 0;	
}

schedule_core[t_d * 24 + t_s + i] = r_core;
				schedule_ram[t_d * 24 + t_s + i] = r_ram;
				schedule_bw[t_d * 24 + t_s + i] = r_bw;
