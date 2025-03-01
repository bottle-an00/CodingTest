#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int N, m[4], DB[16][5], result{INT_MAX};
vector<int> result_case;

int get_result(int input) {
    int sum[5] = {0};
    for (int i = 0; i < N; ++i) {
        if (input & (1 << i)) {
            for (int j = 0; j < 5; ++j) {
                sum[j] += DB[i][j];
            }
        }
    }
    for (int n = 0; n < 4; ++n) {
        if (sum[n] < m[n]) return INT_MAX;
    }
    return sum[4];  
}

void solve_19942() {
    for (int i = 1; i < (1 << N); ++i) {
        int r = get_result(i);
        if (r == INT_MAX) continue;  

        vector<int> combination;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) combination.push_back(j + 1);
        }

        if (result > r) {
            result = r;
            result_case = combination;
        } 
        else if (result == r && combination < result_case) {
            result_case = combination;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < 4; ++i) cin >> m[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> DB[i][j];
        }
    }

    solve_19942();

    if (result == INT_MAX) {
        cout << -1 << "\n";
    } else {
        cout << result << "\n";
        for (int x : result_case) {
            cout << x << " ";
        }
    }

    return 0;
}
