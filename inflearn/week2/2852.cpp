#include <iostream>
#include <string>
#include <compare>
#include <vector>
using namespace std;
vector<pair<int,int>> scoreDB(3,{0,0});//{득점 스코어,최근 득점 시간(sec)}, 
/*
0 ---> trash 비기는 것
1 ---> team 1
2 ---> team 2
*/
int prev_winning_team{};
int prev_scored_time{};
int to_sec(string time){
    int min = stoi(time.substr(0,2)); 
    int sec = stoi(time.substr(3,2)); 
    return min * 60 + sec;
}
int game_status(){
    strong_ordering result(scoreDB[1].first <=> scoreDB[2].first);
    if(is_gt(result)) return 1;
    if(is_lt(result)) return 2; 
    return 0; 
}
void winning_time(int status, int current_time, bool end_flag){
    scoreDB[prev_winning_team].second += current_time - prev_scored_time;
    prev_scored_time = current_time;
    prev_winning_team = status;
}
string to_minsec(int sec){
    string sec_result = (sec%60 < 10 ? "0" :"") + to_string(sec%60);
    string min_result = (sec/60 < 10 ? "0" :"") + to_string(sec/60);
    return min_result + ":" + sec_result;
}
void solve_2852(int scored_team, string currnet_time, bool end_flag){
    int currnet_time_sec = to_sec(currnet_time);
    ++scoreDB[scored_team].first;
    int status = game_status();
    winning_time(status,currnet_time_sec,end_flag);
}
void game_over(){
    scoreDB[prev_winning_team].second += 48 * 60 - prev_scored_time;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N{};
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i){
        int scored_team{}; 
        string current_time{};
        cin >> scored_team >> current_time;
        solve_2852(scored_team, current_time,(i == N-1)? true : false);
    }
    game_over();
    cout << to_minsec(scoreDB[1].second) << "\n";
    cout << to_minsec(scoreDB[2].second) << "\n";
    return 0;
}
