#include <iostream>
#include <vector>
using namespace std;
int N{},M{},ret{};
vector<pair<int,int>> house, chicken;

int cal_chicken_distance(vector<pair<int,int>> added_chicken){
    int sum{};
    if(added_chicken.size() == 0) return __INT_MAX__;
    for(int i = 0; i < house.size(); ++i){
        int result{2*N},chicken_distance{};
        for(int j = 0; j < added_chicken.size(); j++){
            chicken_distance  = abs(house[i].first - added_chicken[j].first) 
            + abs(house[i].second - added_chicken[j].second);
            result = min(result, chicken_distance);
        }
        sum += result;
    }
    return sum;
}

void solve_15686(int idx, vector<pair<int,int>> added_chicken){
    if(idx == N || added_chicken.size() == M){
        if(added_chicken.size() > 0){
            ret = min(ret,cal_chicken_distance(added_chicken));
        }
        return;
    }
    solve_15686(idx + 1,added_chicken);
    
    added_chicken.push_back(chicken[idx]);
    solve_15686(idx + 1,added_chicken);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int input {};
            cin >> input;
            if(input == 2) chicken.emplace_back(i,j);
            if(input == 1) house.emplace_back(i,j);
        }
    }
    ret = __INT_MAX__;
    vector<pair<int,int>> chicken_status;
    solve_15686(0,chicken_status);
    cout << ret << endl;
    return 0;
}