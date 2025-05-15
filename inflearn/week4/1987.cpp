#include <iostream>
#include <string>

using namespace std;

int R,C,max_dist={};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
char input_data[21][21] = {};
int dist[21][21] = {1};

void DFS(int ux, int uy, int record){
    
    for(int i{}; i < 4; ++i){
        int vx = ux + dx[i];
        int vy = uy + dy[i];

        if(vx < 0 || vx >= C || vy < 0 || vy >= R) continue;


        if(record & (1 << static_cast<int>(input_data[vy][vx] -'A'))) continue;

        dist[vy][vx] = dist[uy][ux] +1;
        record |= 1 << static_cast<int>(input_data[vy][vx] - 'A');

        DFS(vx,vy, record);

        record &= ~(1 << static_cast<int>(input_data[vy][vx] - 'A'));
        dist[vy][vx] = 0;
    }
    max_dist = max(max_dist, dist[uy][ux]);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    cin >> R >> C;
    cin.ignore();

    for(int i{}; i < R; i++){
        string input_str;
        getline(cin,input_str);
        for(int j{}; j < C; j++){
            input_data[i][j] = input_str[j];
        }
    }

    dist[0][0] = 1;
    int record = (1 << static_cast<int>(input_data[0][0]- 'A'));
    DFS(0,0,record);;
    cout << max_dist << endl;
    return 0;
}