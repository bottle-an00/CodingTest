#include <iostream>
#include <string>
using namespace std;
int R,C,result{0};
const int MAX{21},dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
char map[MAX][MAX];
bool visited[MAX][MAX], alphabet[26]{false};
void DFS(int x, int y, int t){
    result = max(result,t);
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny]) continue;
        if(alphabet[map[nx][ny]-'A']) continue;
        alphabet[map[nx][ny]-'A'] = true;
        visited[nx][ny] = true;
        DFS(nx, ny, t + 1);
        alphabet[map[nx][ny]-'A'] = false;
        visited[nx][ny] = false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> R >> C;
    cin.ignore();
    for(int r = 0; r < R; ++r){
        string input;
        getline(cin, input);
        for(int c = 0; c < C; ++c){
            map[r][c] = input[c];
        }
    }
    alphabet[map[0][0]-'A'] = true;
    DFS(0,0,1);
    cout << result << "\n";
    return 0;
}