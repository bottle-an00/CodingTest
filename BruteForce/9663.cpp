#include <iostream>

using namespace std;
int N,cnt{};
bool col[15], diag1[30], diag2[30];

void dfs(int row){
    if(row == N){
        cnt++;
        return;
    }

    for(int i{}; i < N; ++i){
        if(col[i] || diag1[row + i] || diag2[row - i + N]) continue;

        col[i] = true; diag1[row + i] = true; diag2[row - i + N] = true;

        dfs(row+1);

        col[i] = false; diag1[row + i] = false; diag2[row - i + N] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;

    dfs(0);
    cout << cnt << "\n";

    return 0;
}