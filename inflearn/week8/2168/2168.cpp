#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, W, dp[1004][1004], px[1004], py[1004];

int diff(int a, int b){
    return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int getSum(int a, int b){
    if(a == W+1 || b == W+1) return 0;
    int& ret = dp[a][b];
    if(ret != -1) return ret;

    int next = max(a,b) + 1;
    return ret = min(getSum(next,b) + diff(a,next) , getSum(a,next) + diff(b,next));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> W;

    px[0] = 1; py[0] = 1;
    px[1] = N; py[1] = N;
    for(int i{2}; i < W+2; ++i){
        cin >> px[i] >> py[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << getSum(0,1) << '\n';

    int a{0}, b{1};
    for(int i{2}; i < W+2; ++i){
        int cost1 = diff(a,i) + getSum(i,b);
        int cost2 = diff(b,i) + getSum(a,i);

        if(cost1 <= cost2){
            cout << "1" << '\n';
            a = i;
        }else{
            cout << "2" << '\n';
            b = i;
        }
    }
    return 0;
}
