#include <iostream>

using namespace std;

int slice[50] = {0};

int cut(int n)
{
	if(slice[n] == 0) {
		if(n == 0) slice[n] = 1;
		else if(n == 1) slice[n] = 2;
		else if(n == 2) slice[n] = 4;
		else slice[n] = (cut(n - 1) + n);
	}
	return slice[n];
}

int main()
{
	int n;
	cin >> n; 
	cout << cut(n) << endl;
	return 0;
} 
