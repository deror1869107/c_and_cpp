#include <iostream>
#include <cstdio>

using namespace std;

int tab[81]={10,12,13,14,15,16,17,18,19,20,21,23,24,25,26,27,28,29,30,31,32,34,35,36,37,38,39,40,41,42,43,45,46,47,48,49,50,51,52,53,54,56,57,58,59,60,61,62,63,64,65,67,68,69,70,71,72,73,74,75,76,78,79,80,81,82,83,84,85,86,87,89,90,91,92,93,94,95,96,97,98};
//an OP solution

int main()
{
	int n, num_2d;
	while(~scanf("%d", &n)){
		//num_2d = 10 + ((n - 1) % 81) + ((n - 1) % 81 + 9) / 10;
		num_2d = tab[(n - 1) % 81];
		for(int i = 0; i < (n - 1) / 81 + 2; i += 2){
			putchar(num_2d / 10 + '0');                 //putchar OP
			putchar(num_2d % 10 + '0');
		}
		if((n - 1) / 81 % 2 == 0){
			putchar(num_2d / 10 + '0'); 
			putchar('\n');
		} else {
			putchar('\n');
		}
	}
}
