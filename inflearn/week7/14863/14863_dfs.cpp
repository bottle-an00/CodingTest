#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N, K;
vector<pair<int,ll>> db_walk;
vector<pair<int,ll>> db_bycicle;
vector<vector<ll>> dp;
ll ans;

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

void go(int here, int time, ll sum){
    if(time > K) return;

    if(dp[here][time] >= sum) return;
    dp[here][time] = sum;

    if(here == N){
        ans = max(ans, sum);
        return;
    }

    go(here + 1, time + db_bycicle[here].first , sum + db_bycicle[here].second);
    go(here + 1, time + db_walk[here].first, sum+ db_walk[here].second);
    return;
}

int main(){
    fast_io();

    cin >> N >> K;
    dp.assign(N + 1, vector<ll>(K + 1, -1));

    for(int i{}; i < N; ++i){
        int t1, t2;
        ll c1,c2;
        cin >> t1 >> c1 >> t2 >> c2;
        db_walk.push_back({t1,c1});
        db_bycicle.push_back({t2,c2});
    }

    go(0,0,0);

    cout << ans << '\n';

    return 0;
}
