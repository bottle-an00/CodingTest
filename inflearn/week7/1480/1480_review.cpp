#include <iostream>
#include <vector>

using namespace std;
int N, M, C, ans;
int dp[14][10000][21];
vector<int> a;

int go(int curr, int mask, int cap){
    if(curr == M) return 0;
    int &ret = dp[curr][mask][cap];
    if(ret != -1) return ret;
    ret = 0;
    for(int i{}; i < N; ++i){
        if(((mask & (1 << i)) == 0) && a[i] <= cap){
            ret = max(ret, go(curr, mask | (1 << i), cap - a[i]) + 1);
        }
    }

    ret = max(ret, go(curr+1, mask, C));

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> C;
    fill(&dp[0][0][0], &dp[0][0][0] + 14*10000*21, -1);
    a.reserve(N);

    for(int i{}; i < N; ++i){
        int w;
        cin >> w;
        a.emplace_back(w);
    }

    ans  = go(0,0,C);
    cout << ans << "\n";

    return 0;
}