//
//  tioj1006.cpp
//  
//
//  Created by Apple on 2015/4/19.
//
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct BigNum
{
    int a[60], size;
    BigNum(){fill(a, a + 60, 0); size = 0;}
    BigNum(char *c){
        fill(a, a + 60, 0);
        size = strlen(c);
        for(int c_size = strlen(c), i = 0; i < c_size; ++i){
            a[i] = c[c_size - i - 1] - '0';
        }
    }
    
    void operator=(const BigNum &p){
        for(int i = 0; i < size; ++i) a[i] = p.a[i];
        size = p.size;
    }
    
    bool operator<=(const BigNum &p){
        for(int i = max(size, p.size); i >= 0; --i){
            if(a[i] != p.a[i]) return a[i] <= p.a[i];
        }
        return true;
    }
    
    BigNum operator<<(int x)const{
        BigNum re = BigNum();
        for(int i = 0; i < size; ++i) re.a[i + x] = a[i];
        re.size = size + x;
        return re;
    }
    
    void operator-=(const BigNum &p){
        for(int i = 0; i < size; ++i){
            a[i] -= p.a[i];
            if(a[i] < 0){
                a[i] += 10;
                a[i + 1]--;
            }
        }
    }
    
    BigNum operator/(const BigNum &p)const{
        BigNum re = BigNum();
        BigNum t = *this;
        re.size = max(size - p.size, 0) + 1;
        
        for(int i = size - p.size; i >= 0; --i){
            while((p << i) <= t){
                t -= (p << i);
                re.a[i]++;
            }
        }
        return re;
    }
};

void print(BigNum const &p)
{
    int i = p.size - 1;
    while(!p.a[i] && i > 0) --i;
    while(i >= 0) printf("%d", p.a[i--]);
    printf("\n");
}


int main()
{
    char s[60], r[60];
    scanf("%s", s);
    scanf("%s", r);
    BigNum ans = BigNum(s) / BigNum(r);
    print(ans);
    int a[10];
}
