#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N, K;
vector<pair<int,ll>> db_walk;
vector<pair<int,ll>> db_bycircle;

vector<ll> dp, nxt;
ll ans;

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

int main(){
    fast_io();

    cin >> N >> K;

    for(int i{};i < N; ++i){
        int t1,t2;
        ll c1,c2;
        cin >> t1 >> c1 >> t2 >> c2;

        db_walk.emplace_back(t1,c1);
        db_bycircle.emplace_back(t2,c2);
    }
    const ll NINF = -(1LL << 60);
    dp.assign(K + 1, NINF);
    nxt.assign(K + 1, NINF);
    dp[0] = 0;
    for(int i{}; i < N; ++i){
        fill(nxt.begin(), nxt.end(), NINF);

        for(int time{}; time <= K; ++time){
            if(dp[time] == NINF) continue;

            int walk_time = time + db_walk[i].first;
            if(walk_time <= K) nxt[walk_time] = max(nxt[walk_time], dp[time] + db_walk[i].second);

            int bycircle_time = time + db_bycircle[i].first;
            if(bycircle_time <= K) nxt[bycircle_time] = max(nxt[bycircle_time], dp[time] + db_bycircle[i].second);
        }
        dp.swap(nxt);
    }

    for(int time{}; time <= K; ++time){
        ans = max(ans, dp[time]);
    }
    cout << ans << '\n';
    return 0;
}