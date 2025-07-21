#include <iostream>

using namespace std;
using ii = pair<int,int>;

int N{},K{},dp[102][100002];
ii a[102];
int dfs(int idx, int k){
    if (idx == N || k == 0) return 0;

    int &res = dp[idx][k];
    if(res != -1) return res;

    int res2{};
    if(k >= a[idx].first){
        res2 = dfs(idx +1, k- a[idx].first) + a[idx].second;
    } 

    return res = max(dfs(idx+1,k), res2);
}
int main(){
    cin >> N >> K;
    for(int i{}; i < N; ++i){
        cin >> a[i].first >> a[i].second;
    }
    fill(&dp[0][0],&dp[0][0]+102*100002,-1);
    cout << dfs(0,K);
    return 0;
}