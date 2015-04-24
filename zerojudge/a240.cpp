#include <iostream>
#include <vector>
#include <cstdio> 

using namespace std;

int main()
{
	int sum_reccuring_dec = 0;
	vector<int> decimal;
	decimal.push_back(0);
	for(int div = 100; div != 10; div *= 10){                 //計算1/17循環小數 
		if(div < 17){
			decimal.push_back(0); 
		} else {
			decimal.push_back(div / 17);
			sum_reccuring_dec += div / 17;
			div = div - (div / 17) * 17;
		}
	}
	/*for(int i = 0; i < decimal.size(); ++i){               //顯示1/17循環小數 
		cout << decimal[i];
	}
	cout << endl;*/
	int m;
	scanf("%d", &m);
	while(m){
		int n, ans1 = 0, ans2 = 0;
		scanf("%d", &n);
		n--;
		ans1 = decimal[n % 16];                              //1/17是16位循環小數 
		ans2 += (n / 16) * sum_reccuring_dec;
		for(int j = 0; j <= (n % 16); j++){
			ans2 += decimal[j];
		}
		printf("%d %d\n", ans1, ans2);
		m--;
	}
	return 0;
} 
