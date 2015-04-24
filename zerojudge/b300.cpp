//InDevelopment
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<string, int> PAIR;  
struct CmpByValue {  
  bool operator()(const PAIR& lhs, const PAIR& rhs) {  
    return lhs.second < rhs.second;  
  }  
};

int time_minus(char time1[8], char time2[8])
{
	return (1000 * (time1[0] - time2[0]) + 100 * (time1[1] - time2[1]) + 10 * (time1[2] - time2[2]) + (time1[3] - time2[3])) * 12 + (10 * (time1[5] - time2[5]) + (time1[6] - time2[6]));
}

bool time_compare(char time1[8], char time2[8])
{
	if((1000 * (time1[0] - time2[0]) + 100 * (time1[1] - time2[1]) + 10 * (time1[2] - time2[2]) + (time1[3] - time2[3])) * 12 + (10 * (time1[5] - time2[5]) + (time1[6] - time2[6])) > 0) return true;
	return false;
}

int main()
{
	int build, damage, money_initial, city_money, city_income, plus, last_money, city_money_total = 0, money_delta = 0;
	char time[8], old_time[8], last_time[8], city_name[20], status[6];
	map<string, int> city, account;
	scanf("%s %d", &time, &money_initial);
	account[time] = money_initial;
	strcpy(old_time, time);
	while(~scanf("%s", &city_name)){
		if(!strcmp(city_name, "----")) break;
		scanf(" %d",  &city_money);
		city[city_name] = city_money;
		city_money_total += city_money;
	}
	scanf("%d %d", &build, &damage);
	while(~scanf("%s", &time)){
		if(!strcmp(time, "----")) break;
		scanf(" %s %s", city_name, status);
		if(strcmp(time, old_time)){
			account[time] = account[old_time] + (city_money_total + money_delta) * time_minus(time, old_time);
			strcpy(last_time, old_time);
			strcpy(old_time, time);
			plus = city_money_total + money_delta;
			money_delta = 0;
		}
		if(!strcmp(status, "BUILT")){
			city_income = build;
			city[city_name] += city_income;
			money_delta += city_income;
		}
		if(!strcmp(status, "BOOST")){
			city_income = build * build;
			city[city_name] += city_income;
			money_delta += city_income;
		}
		if(!strcmp(status, "DAMAGE")){
			if(city[city_name] < damage){
				city_income = city[city_name] * (-1);
			} else {
				city_income = damage * (-1);
			}
			city[city_name] += city_income;
			money_delta += city_income;
		}
		if(!strcmp(status, "RUIN")){
			city_income -= city[city_name];
			city[city_name] += city_income;
			money_delta += city_income;
		}
	}
	scanf("%s", &time);
	if(account[time] == 0) account[time] = (time_minus(time, last_time)) * plus + account[last_time] ;
	printf("%s %d\n", time, account[time]);
	vector<PAIR> city_vec(city.begin(), city.end());
	sort(city_vec.begin(), city_vec.end(), CmpByValue());
	for(vector<PAIR>::iterator it = city_vec.begin(); it != city_vec.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
} 
