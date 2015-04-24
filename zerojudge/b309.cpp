#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

typedef pair<int, int> PAIR;

struct CmpByValueMax{
	bool operator()(const PAIR& a, const PAIR& b){
		return a.second > b.second;
	}
}; 

int main()
{
	char c;
	char db[7][10] = {"Saber", "Lancer", "Archer", "Rider", "Caster", "Assassin", "Berserker"};
	map<int, int> alphabet;
	while(c = getchar() ){
		if(c == EOF) break; 
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
			if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
			++alphabet[(c - 'a') % 7];
		}
	}
	vector<PAIR> alphabet_vec(alphabet.begin(), alphabet.end());
	sort(alphabet_vec.begin(), alphabet_vec.end(), CmpByValueMax());
	vector<PAIR>::iterator it = alphabet_vec.begin();
	int first_servant = it->first;
	int max = it->second;
	for(vector<PAIR>::iterator it = alphabet_vec.begin(); it != alphabet_vec.end(); ++it){
		if(it->second == max && it->first < first_servant) first_servant = it->first;
		else if(it->second != max) break;
	}
	printf("%s\n", db[first_servant]);
	//for(vector<PAIR>::iterator it = alphabet_vec.begin(); it != alphabet_vec.end(); ++it) cout << it->first << " " << it->second << endl;
	return 0;
}
