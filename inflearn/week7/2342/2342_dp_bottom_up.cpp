#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
const int  INF = INT_MAX;

int N, dp[5][5],ndp[5][5], ans{INF};
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
    fill(&dp[0][0], &dp[0][0] + 5*5 , INF);
    int l_foot, r_foot;

    dp[0][0] = 0;
    for(int x : a){
        fill(&ndp[0][0], &ndp[0][0] + 5*5 , INF);

        for(int l{}; l < 5; ++l){
            for(int r{}; r < 5; ++r){
                if(dp[l][r] == INF) continue;

                //move_left
                ndp[x][r] = min(ndp[x][r], dp[l][r] + cal_cost(l,x));
                //move_right
                ndp[l][x] = min(ndp[l][x], dp[l][r] + cal_cost(r,x));

            }
        }

        swap(dp,ndp);
    }

    ans = *min_element(&dp[0][0], &dp[0][0] + 5*5);

    cout << ans << "\n";

    return 0;
}