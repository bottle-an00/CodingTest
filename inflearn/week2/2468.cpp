#include <iostream>
using namespace std;
int N{};
int map[104][104];
bool visited[104][104];
int  dx[4] = {-1,0,1,0}; int dy[4] = {0,-1,0,1};
int result{},max_result{};

void DFS(int x, int y, int height){
    visited[y][x] = true;

    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i]; int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N|| visited[ny][nx] == true) continue;
        if(visited[ny][nx] == false && map[ny][nx] > height)
            DFS(nx,ny,height);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int max_height{};
    for(int x = 0; x <N; ++x)
    {
        for(int y = 0; y <N; ++y)
        {
            cin >> map[y][x];
            max_height = max(max_height,map[y][x]);
        }
    }
    for(int height = 0; height <= max_height; ++height)
    {//노션에 tip을 살펴보면 반례를 생각하는 기준을 제시했는데 
    //이는 height에 적용될 수 있다. 코드를 작성하면서도 height의 최소를 고려해야하는가를 생각해보았는데 
    //상식적인 높이 0이 있기에 굳이 구할 필요가 없다고 생각하여 넘긴것이다. 
    //최소값 설정에 따른result의 초기값을 잘 설정해주어야 한다. 
    // ex) 만약 result =1로 초기화 하고 height =0이라면 본래는 result가 0이어야 하는데 1로 된다. 
        fill(&visited[0][0],&visited[0][0]+104*104,false);
        result = 0;
        for(int x = 0; x <N; ++x)
        {
            for(int y = 0; y <N; ++y)
            {
                if(map[y][x] > height && visited[y][x] == false) 
                {
                    DFS(x,y,height);
                    result++;
                }
            }
        }
        max_result = max(max_result, result);
    }
    cout << max_result;
    return 0;
}