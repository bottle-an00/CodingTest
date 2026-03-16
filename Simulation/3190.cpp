#include <iostream>
#include <deque>

using namespace std;
using ii = pair<int,int>;
using ic = pair<int,char>;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

int N, K, L, current_time{1}, apple_db[102][102], snake_db[102][102], time_db[102];
deque<ic> time_stack;

struct Snake{
    deque<ii> snake_loc;

    // 0 -> 서, 1-> 북, 2-> 동, 3-> 남
    int direction = 2;
};


void rotate(Snake& s, char new_direction){
    if(new_direction == 'L')
        s.direction = (s.direction + 3) % 4;
    else if(new_direction == 'D')
        s.direction = (s.direction + 1) % 4;
    return;
}

bool stretch_snake(Snake& s){
    ii head = s.snake_loc.front();
    int nx = head.second + dx[s.direction];
    int ny = head.first + dy[s.direction];

    if(nx < 0 | nx >= N | ny < 0 | ny >= N) return true;
    if(snake_db[ny][nx]) return true;
    s.snake_loc.emplace_front(ny,nx);

    snake_db[ny][nx] = 1;
    return false;
}

void shrink_snake(Snake& s){
    ii tail = s.snake_loc.back();

    s.snake_loc.pop_back();
    snake_db[tail.first][tail.second] = 0;
}

bool is_apple(Snake& s){
    ii head = s.snake_loc.front();
    if(apple_db[head.first][head.second]) {
        apple_db[head.first][head.second] = 0;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fill(&apple_db[0][0], &apple_db[0][0]+102*102, 0);
    fill(&snake_db[0][0], &snake_db[0][0]+102*102, 0);

    cin >> N;
    cin >> K;
    for(int i{}; i < K; ++i){
        int y, x;
        cin >> y >> x;
        apple_db[--y][--x] = 1;
    }

    cin >> L;
    for(int i{}; i < L; ++i){
        int t; char c;
        cin >> t >> c;
        time_stack.emplace_back(t,c);
    }

    //main_logic
    Snake snk;
    snk.snake_loc.emplace_front(0,0);
    snake_db[0][0] = 1;
    while(1){

        if(stretch_snake(snk)) break;
        if(!is_apple(snk)){
            shrink_snake(snk);
        }

        ic time_info = time_stack.front();
        if(current_time == time_info.first){
            rotate(snk, time_info.second);
            time_stack.pop_front();
        }
        current_time++;
    }
    cout << current_time << "\n";
    return 0;
}
