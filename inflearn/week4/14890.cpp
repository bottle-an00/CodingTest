#include <iostream>
#include <vector>

using namespace std;

int N,L;
vector<vector<int>> data_DB;

bool check_possibility(int row, int diff, int curr, int next, int& mask){
    for(int i = 1; i <= L; ++i){
        int idx = curr + diff*i;
        
        if(diff < 0) idx += 1;

        if(mask & (1 << idx)) return false;
        if(idx < 0 || idx >= N) return false;
        int target = min(data_DB[row][curr], data_DB[row][next]);
        if(abs(target - data_DB[row][idx])) return false;

        mask ^= (1 << idx);
    }
    return true;
}

int solve_14890(){
    int impossible_count{};
    for(int i = 0; i < 2*N; ++i){
        int mask = 0;

        for(int j = 0; j < N-1; ++j){
            int curr = j;
            int next = j+1;
            
            int diff = data_DB[i][curr] -data_DB[i][next];
            if(abs(diff) > 1){
                ++impossible_count;
                break;
            } 

            if(diff == 0) continue;
            else{
                if(!check_possibility(i,diff, curr, next, mask)){
                    ++impossible_count;
                    break;
                }
            } 
        }
    }
    return 2*N - impossible_count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> L;
    data_DB.assign(2*N,vector<int>(N,0));
    for(int r = 0; r < N; ++r){
        for(int c =0; c< N; ++c){
            int e{};
            cin >> e;
            data_DB[r][c] = e;
            data_DB[c+N][r] = e;
        }
    }

    cout << solve_14890();
    return 0;
}