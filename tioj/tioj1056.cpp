//
//  tioj1056.cpp
//  
//
//  Created by Apple on 2015/4/20.
//
//

#include <cstdio>

using namespace std;

int main()
{
    char map[9];
    for(int i = 0; i < 3; ++i){
        scanf("%s", map + i * 3);
    }
    int circle = 0, cross = 0, flag = 0;
    for(int i = 0; i < 9; ++i){
        if(map[i] != 'O' && map[i] != 'X' && map[i] != '.'){
            flag = 1;
            break;
        } else if(map[i] == 'O') circle++;
        else if(map[i] == 'X') cross++;
    }
    if(flag == 0){
        if(circle - cross != 1 && circle - cross != 0) flag = 1;
    }
    int circle_line = 0, cross_line = 0;
    for(int i = 0; i < 3; ++i){
        if(map[i * 3] == 'O' && map[i * 3 + 1] == 'O' && map[i * 3 + 2] == 'O') circle_line++;
        if(map[i * 3] == 'X' && map[i * 3 + 1] == 'X' && map[i * 3 + 2] == 'X') cross_line++;
        if(map[i] == 'O' && map[i + 3] == 'O' && map[i + 6] == 'O') circle_line++;
        if(map[i] == 'X' && map[i + 3] == 'X' && map[i + 6] == 'X') cross_line++;
    }
    if(map[0] == 'O' && map[4] == 'O' && map[8] == 'O') circle_line++;
    if(map[0] == 'X' && map[4] == 'X' && map[8] == 'X') cross_line++;
    if(map[2] == 'O' && map[4] == 'O' && map[6] == 'O') circle_line++;
    if(map[2] == 'X' && map[4] == 'X' && map[6] == 'X') cross_line++;
    if(circle_line * cross_line != 0) flag = 1;
    if(flag == 0) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}
