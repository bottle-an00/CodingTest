#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int damage[3] = {9, 3, 1};
int N;
int dp[61][61][61]; 

int solve_12869(int a, int b, int c) {
    a = max(0, a);
    b = max(0, b);
    c = max(0, c);

    if (a == 0 && b == 0 && c == 0) return 0;

    if (dp[a][b][c] != -1) return dp[a][b][c];

    dp[a][b][c] = __INT_MAX__; 

    vector<int> order = {0, 1, 2};
    do {
        dp[a][b][c] = min(dp[a][b][c], 1 + solve_12869(a - damage[order[0]], 
                                                        b - damage[order[1]], 
                                                        c - damage[order[2]]));
    } while (next_permutation(order.begin(), order.end()));

    return dp[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> N;
    vector<int> scv(3, 0);

    for (int i = 0; i < N; ++i) {
        cin >> scv[i];
    }

    cout << solve_12869(scv[0], scv[1], scv[2]) << "\n";
    return 0;
}
