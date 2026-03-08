#include <iostream>

using namespace std;
const int INF = 1e9;
int N{},K{},a[104],dp[10004];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) cin >> a[i];
    
    fill(dp, dp + K + 1, INF);
    dp[0] = 0; // 0원을 만드는 데는 동전 0개

    for (int i = 0; i < N; ++i) {
        for (int j = a[i]; j <= K; ++j) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }

    cout << (dp[K] == INF ? -1 : dp[K]);
    return 0;
}