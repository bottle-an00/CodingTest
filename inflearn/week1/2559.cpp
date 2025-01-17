#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> per_sum(N+1,0);//1부터 시작
    for(int i = 1 ; i < N+1; ++i){
        int s;
        cin >> s;
        per_sum[i] = per_sum[i-1] + s;

    }

    int max_res =INT_MIN;
    for(int i = K; i < N+1; ++i){
        int sum = per_sum[i] - per_sum[i-K];
        max_res = max(sum, max_res);
    }
    cout << max_res;

    return 0;
}