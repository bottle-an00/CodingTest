#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const int  INF = INT_MAX; 

int N, dp[100002][5][5], ans;
vector<int> a;

int cal_cost(int prev, int curr){
    int result = abs(prev - curr);
    if(result == 0) return 1;
    else{
        result %= 2;
        if(result == 0){
            return ((prev == 0) ? 2 : 4);
        }else{
            return ((prev == 0) ? 2 : 3);
        }
    }
    return -1;
}

int go(int idx, int l_foot, int r_foot){
    if(idx == N) return 0;

    int& ret = dp[idx][l_foot][r_foot];
    if(ret != INF) return ret;

    int cost = cal_cost(l_foot, a[idx]);
    //move left
    if(cost != -1) ret = min(ret, go(idx + 1, a[idx], r_foot) + cost);

    cost = cal_cost(r_foot, a[idx]);
    //move right
    if(cost != -1) ret = min(ret, go(idx + 1, l_foot, a[idx]) + cost);

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(1){
        int e;
        cin >> e;

        if(e == 0) break;
        a.emplace_back(e);
    }
    N = a.size();
    fill(&dp[0][0][0], &dp[0][0][0] + 100002*5*5 , INF);

    ans = go(0,0,0);
    cout << ans << "\n";

    return 0;
}