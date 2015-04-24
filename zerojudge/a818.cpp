#include <cstdio> 
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n;
	char s[20] = {'\0'};
	char ans[20] = {'\0'};
	while(cin >> n){
		int num[n], k;
		for(int i = 0; i < n; i++) cin >> num[i];
		cin >> s;
		cin >> k;
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < n; j++){
				ans[j] = s[num[j] - 1];
			}
			strcpy(s, ans);
		}
		cout << ans << endl;
	}
	return 0;
}

