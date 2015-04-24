//
//  tioj1005.cpp
//  
//
//  Created by Apple on 2015/4/15.
//
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int GCD(int a,int b)
{
    int temp;
    while(a%b)
    {
        temp=a;
        a=b;
        b=temp%a;
    }
    return b;
}

int mod_vec(vector<int>& a)
{
    int output = 0;
    for(int i = 0; i < a.size(); ++i){
        for(int j = i + 1; j < a.size(); ++j){
            if(GCD(a[i], a[j]) != 1) output++;
        }
    }
    return output;
}

int main()
{
    int N;
    cin >> N;
    while(N){
        int ans_sum = 0, ans_n = 0;
        vector<int> vec;
        for(int i = 0; i < N; ++i){
            int now;
            cin >> now;
            vec.push_back(now);
        }
        ans_sum += mod_vec(vec);
        ans_n += (N * (N - 1)) / 2;
        printf("%.6f", sqrt(double(ans_n) * 6 / ans_sum));
        vec.clear();
        cin >> N;
    }
}

