#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
bool visited[11][11];
int map[11][11],result{INT_MAX},N;

int is_possible(pair<int,int> point){
    if(visited[point.first][point.second]) return false;
    for(int i = 0; i < 4; ++i){
        int nx = point.first + dx[i];
        int ny = point.second + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >=N || visited[nx][ny]) return false;
    }
    return true;
}
int set_visited(pair<int,int> point, bool val){
    int sum {map[point.first][point.second]};
    for(int i = 0; i < 4; ++i){
        int nx = point.first + dx[i];
        int ny = point.second + dy[i];
        visited[nx][ny] = val;
        sum += map[nx][ny];
    }
    return sum;
}
void solve_14620(int cnt, int sum){
    if(sum >= result) return;
    if(cnt == 3){
        result = min(result, sum);
        return;
    }
    for(int i = 1; i < N - 1; ++i){
        for(int j = 1; j < N - 1; ++j){
            if(is_possible({i,j})) {
                int dsum = set_visited({i,j},true);
                solve_14620(cnt + 1, sum + dsum);
                set_visited({i,j},false);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> map[i][j];
        }
    }
    solve_14620(0,0);
    cout << result << endl;
    return 0;
}