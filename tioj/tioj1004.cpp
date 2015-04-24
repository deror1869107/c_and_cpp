#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> jew;
	cin >> n;
	for(int i = 1; i <= n; ++i) jew.push_back(i);
	while(jew.size() != 1){
		jew.erase(++jew.begin());
		rotate(jew.begin(), ++jew.begin(), jew.end());
	}
	cout << jew.front();
}
