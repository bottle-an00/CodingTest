#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int N{},M{};
const int dx[4] = {-1,0,1,0};
const int dy[4] = { 0, -1, 0, 1};
bool visited[54][54]={false};
vector<pair<int,int>> land;

int BFS(pair<int,int> s){
    int count{};
    visited[s.first][s.second] = true;
    queue<pair<int,int>> que;
    que.push(s);
    while(!que.empty()){
        auto [ux,uy] = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if(visited[nx][ny]) continue;
            count ++;
            que.emplace(ux,uy);
        }
    }
    return count;
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            string input{};
            cin >> input;
            if(input == "L") land.emplace_back(i,j);
        }
    }
    for(int i = 0; i < land.size(); ++i){
        fill(&visited[0][0],visited[0][0]*54,false);
    }
}