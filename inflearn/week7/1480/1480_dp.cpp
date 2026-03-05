#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, M, C, ans;
int dp[11][10000][21];
vector<int> a;

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

int go(int curr, int mask, int cap){
    if(curr == M) return 0;

    int& ret = dp[curr][mask][cap];
    if(ret != -1) return ret;
    ret = 0;

    for(int i{}; i < N; ++i){
        if(( (mask & (1 << i)) == 0) &&  a[i] <= cap){// 포함되지 않은 보석이라면..
            ret = max(ret, go(curr, mask | (1 << i) ,cap - a[i]) + 1);
        }
    }
    //새로운 배낭
    ret = max(ret, go(curr+1, mask, C));
    return ret;
}

int main(){
    cin >> N >> M >> C;
    memset(dp, -1, sizeof(dp));
    a.reserve(N);

    for(int i{}; i < N; ++i){
        int w;
        cin >> w;

        a.emplace_back(w);
    }

    ans = go(0, 0, C);
    cout << ans;
    return 0;
}