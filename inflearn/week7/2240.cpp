#include <iostream>

using namespace std;

int T{},W{},dp[1004][2][34], a[1004];

int dfs(int t, int tree, int cnt){
    if(cnt > W) return -1e9;
    if(t == T) return 0;

    int &res = dp[t][tree][cnt];
    if(res != -1) return res;

    res = max(dfs(t+1,tree,cnt),dfs(t+1,tree^1,cnt+1));
    res += (tree+1 == a[t] ? 1 : 0);

    return res;
}

int main(){
    cin >> T >> W;
    for(int t{}; t< T; ++t){
        cin >> a[t];
    }
    fill(&dp[0][0][0],&dp[0][0][0] + 1004*2*34 ,-1);
    cout << max(dfs(0,0,0),dfs(0,1,1));
    return 0;
}