#include <iostream>

using namespace std;

int main()
{
	int a[100], b[100];
	string BigNumA;
    string BigNumB;
    while(cin >> BigNumA >> BigNumB){
		for(int i = 0; i < 100; i++){
			if(BigNumA[i] != NULL){
				a[i] = BigNumA[i] - '0';
			} else {
				a[i] = 0;
			}
			if(BigNumB[i] != NULL){
				b[i] = BigNumB[i] - '0';
			} else {
				b[i] = 0;
			}
		}
		for(int i = 0; i < 100; i++){
			cout << a[i];
		}
	}
} 
