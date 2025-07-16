#include <iostream>
#include <vector>

using namespace std;
using ii = pair<int,int>;

int dice[10],res{};
vector<ii> status;// route, pos

vector<vector<int>> db = {
                        {10,13,16,19,25,30,35,40},
                        {20,22,24,25,30,35,40},
                        {30,28,27,26,25,30,35,40},
                        {40}
                        };

void go(int cnt, int score, vector<ii> cur_status){
    if(cnt == 10){
        res = max(res, score);
        return;
    }
    for(int i{}; i < 4; ++i){

        if(cur_status[i].first == 5) continue;//도착한 것들
        //new_pos
        int new_pos =  cur_status[i].second + dice[cnt];

        //new_status 설정
        ii new_status  = cur_status[i];
        if(cur_status[i].first == 0){
            if(new_pos > 20){ //도착
                new_status = {5,0};
            }
            else if (new_pos % 5 == 0){
                new_status = {new_pos/5,0};
            }
            else new_status.second = new_pos;
            
        }else{
            if(new_pos >= db[new_status.first-1].size()){//도착
                new_status = {5,0};
            }else{
                new_status.second = new_pos;
            }
        }

        bool same{false};
        //다른 말이랑 겹치는지 확인
        for(int j = 0; j < 4; ++j){
            if(i == j) continue;
            if(cur_status[j].first == 5 || new_status.first == 5) continue;
            if(cur_status[j].first && new_status.first){
                int d1 = db[cur_status[j].first-1][cur_status[j].second];
                int d2 = db[new_status.first-1][new_status.second];
                if(d1 == d2){
                    if(d1 == 30 && new_status.second != cur_status[j].second) continue;
                    same = true;
                    break;
                }
            }
            if(cur_status[j].first == new_status.first && cur_status[j].second == new_status.second){
                same = true;
                break;
            }

        }

        if(!same) {
            vector<ii> next_status = cur_status;
            next_status[i].first = new_status.first;
            next_status[i].second = new_status.second;
            if(new_status.first == 0){ 
                go(cnt+1,score + new_pos*2, next_status);
            }
            else if(new_status.first == 5)//이동한 말이 도착한 경우
                go(cnt+1,score,next_status);
            else 
                go(cnt+1,score + db[new_status.first-1][new_status.second],next_status);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    for(int i{}; i < 10; ++i){
        cin >> dice[i];
    }
    status.assign(4,ii(0,0));
    go(0,0,status);
    cout << res;
    return 0;
}