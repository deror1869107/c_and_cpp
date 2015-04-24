#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input;
	vector<int> fact;
	fact.push_back(1);
	while(cin >> input){
		if(input > fact.size()){
			int num_temp = 0;
			int k = 0;
			for(int i = fact.size(); i < input; i++){
				k = i + 1;
				for(; k % 10 == 0;) k /= 10;	
				num_temp = k * fact[i - 1];
				for(; num_temp % 10 == 0;) num_temp /= 10;
				num_temp %= 100000;
				fact.push_back(num_temp);
			}
			for(int i = input; i < 1000; i *= 10) cout << ' ';
			cout << input << " -> " << num_temp % 10 << endl;
		} else {
			for(int i = input; i < 1000; i *= 10) cout << ' ';
			cout << input << " -> " <<  fact[input - 1] % 10  << endl;
		}
	}
	return 0;
}

