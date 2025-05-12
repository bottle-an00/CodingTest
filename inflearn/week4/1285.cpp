#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N{};
vector<int> input_bit;

void solve_1285(vector<int>& data)
{
    //bitmask를 활용 -> 경우의 수로 접근
    int min_sum = N*N;

    for(int mask{} ;mask < N; mask++){
        vector<int> tmp(N*N, -1);
        tmp = data;

        //각 경우의 수에 따라 행 flip
        for(int i{}; i < N; ++i){
            if(mask & (1 << i)){
                //flip
                for(int j{}; j < N; j++){
                    tmp[i*N + j] = 1 - tmp[i*N +j];
                }
            }
        }

        int total{};
        for(int i{}; i < N; ++i){//각 열에 대해 
            int sum{};
            for(int j{}; j < N; ++j){
                sum += tmp[j*N + i];
            }
            total += min(sum, N-sum);
        }
        min_sum = min(min_sum, total);
    }
    cout << min_sum;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cin.ignore();
    input_bit.assign(N*N ,-1);

    for(int i = 0; i < N; ++i){
        string input_str;
        getline(cin,input_str);
        for(int j = 0; j < N; ++j){
            input_bit[i*N + j] = (input_str[j] == 'H'? 0 : 1);
        }
    }

    solve_1285(input_bit);
    return 0;

}