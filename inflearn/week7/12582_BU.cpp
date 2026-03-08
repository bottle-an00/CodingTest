#include <iostream>

using namespace std;

const int INF = 1e9;
int N{},dp[1000004],next_X[1000004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    dp[1] = 0;
    for(int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;
        next_X[i] = i - 1;

        if(i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            next_X[i] = i / 2;
        }
        if(i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            next_X[i] = i / 3;
        }
    }

    cout << dp[N] << "\n";
    int idx = N;
    while(true){
        cout << idx << " ";
        if(idx == 1) break;
        idx = next_X[idx];
    }

    return 0;
}