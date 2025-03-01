#include <iostream>
#include <string>
using namespace std;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
bool visited[6][6];
int result{},R,C,K, map[6][6];
void solve_1189(int x, int y, int cnt){
    if(cnt > K) return;
    if(cnt == K && x == 0 && y == C - 1){
        ++result;
        return;
    }
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;
        if(map[nx][ny]  != 'T' && !visited[nx][ny]){
            visited[nx][ny] = true;
            solve_1189(nx,ny,cnt+1);
            visited[nx][ny] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> K;
    cin.ignore();

    for(int i = 0; i < R; ++i){
        string input;
        cin >> input;
        for(int j = 0; j < C; ++j){
            map[i][j] = input[j];
        }
    }
    visited[R-1][0] = true;
    solve_1189(R-1,0,1);
    cout << result << endl;
    return 0;
}