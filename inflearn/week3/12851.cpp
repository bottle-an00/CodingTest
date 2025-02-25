#include <iostream>
#include <climits>
using namespace std;
int visited[1000004], N, K,result{INT_MAX},count;
void solve_12581(int current){
    visited[current] =1;
    if(current == K){
        if(result > current_t){
            result = current_t;
            count =0;
        }
        if (current_t == result) ++count;
        return;
    }
    int next = max(0,current - 1);
    if(visited[next] == 0) solve_12581(next,current_t+1);
    next = min(1000004,current + 1);
    if(visited[next] == 0) solve_12581(next,current_t+1);
    next = min(1000004, current * 2);
    if(visited[next] == 0) solve_12581(next,current_t+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    fill(&visited[0],&visited[0]+1000004,0);
    solve_12581(N,0);
    cout << result << "\n";
    cout << count << "\n";
    return 0;
}