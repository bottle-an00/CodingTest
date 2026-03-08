#include <iostream>

using namespace std;
int N, K, cnt{}, upper_convey[102], convey_status[202], robots[102];

bool is_done(){
    int defacts{};
    for(int i{}; i < 2*N; ++i){
        if(convey_status[i] == 0) defacts++;
    }
    return (defacts >= K) ? true : false ;
}

void move_convey(){
    for(int i{}; i < N; ++i){
        upper_convey[i] = (cnt+i) % (2*N);
        if(i == N-1) robots[i] = 0;
        robots[i+1] = 1;
        robots[i] = 0;
    }
}

void update_robots(){
    for(int i{N-1}; i >= 0; ++i){
        if(!robots[i]) continue;
        if(robots[i+1]) continue; // 0: 비었음 1: 로봇 존재
        if(!convey_status[upper_convey[i+1]]) continue;

        robots[i+1] = 1;
        robots[i] = 0;
        convey_status[upper_convey[i+1]]--;
    }
}

void add_robot(){
    if(convey_status[upper_convey[0]]) {
        robots[0] = 1;
        convey_status[upper_convey[0]]--;
    }
}

int main(){
    
    cin >> N >> K;
    for(int i{}; i < 2*N; ++i){
        cin >> convey_status[i];
    }

    while(1){
        if(is_done())break;

        //step1
        move_convey();
        //step2
        update_robots();
        //step3
        add_robot();

        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}