#include <iostream>
using ll = long long;
using namespace std;
int N{};
ll dp[31][31];
ll go(int H, int W){
    if(H == 0 && W == 0) return 1;
    if(dp[W][H]) return dp[W][H];

    ll &res = dp[W][H];
    if(W > 0) res += go(H+1,W-1);
    if(H > 0) res += go(H-1,W);

    return res;
}
int main(){
    while(1){
        cin >> N;
        if(N == 0) break;
        fill(&dp[0][0],&dp[0][0] + 31*31,0);
        cout << go(0,N) << "\n";
    }
    return 0;
}
