#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int reg[4] = {}, ram[8] = {}, arg1, arg2, arg3, N;
	char cmd[8] = {'\0'};
	for(int i = 0; i < 8; i++) scanf("%d", &ram[i]);
	scanf("%d", &N);
	while(N){
		N--;
		scanf("%s %d %d", &cmd, &arg1, &arg2);
		if(!strcmp(cmd, "LOAD")){
			reg[arg1] = ram[arg2];
		}
		if(!strcmp(cmd, "STORE")){
			ram[arg1] = reg[arg2];
		}
		if(!strcmp(cmd, "ADD")){
			scanf(" %d", &arg3);
			reg[arg1] = reg[arg2] + reg[arg3];
		}
		if(!strcmp(cmd, "MOVE")){
			reg[arg1] = reg[arg2];
		}
	}
	printf("%d\n%d\n", reg[0], ram[0]);

	return 0;
}
