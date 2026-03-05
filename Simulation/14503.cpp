#include <iostream>

using namespace std;
const int dy[4] = {0,1,0,-1};
const int dx[4] = {-1,0,1,0};

struct EgoStatus{
    int x;
    int y;
    int d;
};

int N, M, db[52][52];

void clean(int x, int y){
    // 현재 로봇의 위치를 청소 x ,y
    db[x][y] = 2;
}

bool check_arround(int x, int y){
    /*
    로봇의 현재 위치의 주면을 확인

    output:
        true : 2번수행
        false: 3번수행
    */
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        if(db[nx][ny] == 0) return false;
    }
    return true;
}

void move(EgoStatus& ego, int nd){
    /*
    새로운 로봇의 방향으로 이동
    */

    ego.x += dx[nd];
    ego.y += dy[nd];
}

bool check_direction(EgoStatus& ego ,int nd){
    /*
        output:
        true  -> 벽이 아니라 갈 수 있음
        false -> 벽이라 갈 수 없음
    */
    int nx = ego.x + dx[nd];
    int ny = ego.y + dy[nd];

    if(nx <0 || nx >= N || ny < 0 || ny >= M) return false;
    if(db[nx][ny] == 1) return false;

    return true;
}

bool is_clean(EgoStatus& ego ,int nd){
    /*
        output:
        true  -> 벽이 아니라 갈 수 있음
        false -> 벽이라 갈 수 없음
    */
    int nx = ego.x + dx[nd];
    int ny = ego.y + dy[nd];

    if(nx <0 || nx >= N || ny < 0 || ny >= M) return false;
    if(db[nx][ny] != 0) return false;

    return true;
}

void rotate_CC90(EgoStatus& ego){
    /*
    새로운 방향으로 로봇 회전
    */
   ego.d = (ego.d +3) % 4;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    EgoStatus ego;
    cin >> N >> M;
    cin >> ego.x >> ego.y >> ego.d;

    fill(&db[0][0], &db[0][0] + 52*52, -1);
    for(int i{}; i < N; ++i){
        for(int j{}; j < M; ++j){
            cin >> db[i][j];
        }
    }

    //main
    int cnt{};

    while(1){
        // 1번 수행
        if(db[ego.x][ego.y] == 0) {clean(ego.x, ego.y); cnt++;}
        // 2번 3번 결정
        if(check_arround(ego.x, ego.y)){
            //2번 수행
            if(!check_direction(ego, (ego.d + 2)% 4)){ // 못 간다면 작동 중지
                break;
            }else{
                move(ego,(ego.d + 2)% 4); //후진
            }

        }else{
            //3번 수행
            for(int i{}; i < 4; ++i){
                rotate_CC90(ego);
                if(is_clean(ego,ego.d)) {
                    move(ego,ego.d); // 빈칸 -> 이동
                    break;
                }
            }

        }
    }

    cout << cnt << "\n";
    return 0;
}