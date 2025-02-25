#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int visited[61][61][61],N;
struct scv{
    int a,b,c;
}; 

void BFS(int a, int b, int c){
    queue<scv> que;
    a = max(0,a);
    b = max(0,b);
    c = max(0,c);
    que.push({a,b,c});
    visited[a][b][c] = 0;

    while(que.size()){
        int order[3] = {1,3,9};
        auto [ca,cb,cc] = que.front();
        que.pop();
        do{
            int na = max(0,ca-order[0]);
            int nb = max(0,cb-order[1]);
            int nc = max(0,cc-order[2]);
            if(visited[na][nb][nc] != -1) continue;
            visited[na][nb][nc] = visited[ca][cb][cc] + 1;
            que.emplace(na,nb,nc);
            
        }while(next_permutation(order,order+3));
    }
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    fill(&visited[0][0][0], &visited[0][0][0] + 61*61*61, -1);
    int hp[3] = {0};
    for(int i = 0; i < N; ++i){
        cin >> hp[i];
    }
    BFS(hp[0],hp[1],hp[2]);
    cout << visited[0][0][0] << "\n";
    return 0;
}