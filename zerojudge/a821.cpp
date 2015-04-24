#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, R;
	string team;
	vector<string> win;
	vector<string> lose;
	while(cin >> N >> R){
		string winteam, loseteam;
		for(int i = 0; i < R; i++){
			cin >> winteam >> loseteam;
			win.push_back(winteam);
			lose.push_back(loseteam);
		}
		//sort(win.begin(), win.end());
		//sort(lose.begin(), lose.end());
		for(vector<string>::iterator it = win.begin(); it != win.end(); it++){
			team = *it;
			vector<string>::iterator it1 = find(lose.begin(), lose.end(), team);
			if(it1 != lose.end()) {
				continue;
    		} else {
    			cout << team << endl;
    			break;
    		}
    	}
	}	
}
