#include <iostream>

using namespace std;
int N, ans{};
bool col[15], diag1[30], diag2[30];

void BFS(int row){
    if(row == N) { ans++; return;}

    for(int c{}; c < N; ++c){
        if(col[c] | diag1[row + c] | diag2[row -c + N]) continue;

        col[c] = true; diag1[row+c] = true; diag2[row - c + N] = true;

        BFS(row+1);

        col[c] = false; diag1[row+c] = false; diag2[row - c + N] = false;
    }

    return;
}

int main(){
    cin >> N;

    BFS(0);
    cout << ans << "\n";

    return 0;
}