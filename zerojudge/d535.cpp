#include <iostream> //Start 03:41 End 03:52
#include <cstdio>
#include <cstring>

using namespace std; 

int main()
{
	char input[30] = {'\0'};
	while(~scanf("%s", &input)){
		int len = strlen(input);
		int flag = 0;
		if(len < 10 || len > 30) flag++;
		for(int i = 0; i < len / 2; i++){
			if(input[i] != input[len - 1 - i]){
				flag++;
				break;
			}
		}
		for(int i = 0; i < len - 1; i++){
			if((input[i] - '0') * 2 < (input[i + 1] - '0')){
				flag++;
				break;
			}
		}
		int even = 0;
		for(int i = 0; i < len; i++) if((input[i] - '0') % 2 == 0) even++;
		if(even == 0) printf("0");
		if(flag != 0) printf("INCORRECT\n");
		else{
			for(int i = 0; i < len; i++) if((input[i] - '0') % 2 == 0) printf("%c", input[i]);
			printf("\n");
		}
	}
	return 0;
}
