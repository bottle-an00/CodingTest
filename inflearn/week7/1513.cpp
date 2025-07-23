#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ii = pair<int,int>;
using ll = long long;

int N{}, M{}, C{},a[52][52];
vector<ii> games;
ll dp[52][52][52][52];
void show_db(int cnt){
    for(int r{1}; r <= N; ++r){
        cout << endl;
        for(int c{1}; c <= M; ++c){
            cout << setw(2) <<dp[r][c][2][0] << " ";
        }
    }
    cout << endl;
}

ll dfs(int cr, int cc, int cnt, int prev_idx){
    if(cr > N || cc > M) return 0;
    if(cr == N && cc == M){
        if(cnt == 0 && a[cr][cc] == 0) return 1;
        if(cnt == 1 && a[cr][cc] > prev_idx) return 1; // 도착지점에 오락실
        return 0;
    }

    ll &res = dp[cr][cc][cnt][prev_idx];
    if(res != -1) return res;

    res = 0;
    if(a[cr][cc]){
        if(prev_idx < a[cr][cc]){
            res += (dfs(cr+1,cc, cnt-1, a[cr][cc]) + dfs(cr,cc+1, cnt-1, a[cr][cc]))% 1000007;
        }
    }else{
        res += (dfs(cr+1,cc, cnt, prev_idx) + dfs(cr,cc+1, cnt, prev_idx))%1000007;
    }
    return res;
}

int main(){
    cin >> N >> M >> C;

    games.assign(C,ii());
    fill(&dp[0][0][0][0],&dp[0][0][0][0] + 52*52*52*52, -1);
    fill(&a[0][0],&a[0][0] + 52*52, 0);

    for(int i{1}; i <= C; ++i){
        int r{},c{};
        cin >> r >> c;
        a[r][c] = i;
    }
    for(int i{C}; i >=0; --i){
        cout << dfs(1,1,i,0) << " ";
    }

    return 0;
}