#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nanjangs(9);
    for(int i = 0; i < 9; ++i){
        cin >> nanjangs[i];
    } 
    
    set<int> res;
    bool is_answer {false};
    for(int j = 0; j < 8; ++j){
        for(int k = j+1; k < 9; ++k){
            if(is_answer) break;
            int sum{};

            for(int i = 0; i < 9; ++i){

                if(i == j || i == k) continue;
                sum += nanjangs[i];
                res.insert(nanjangs[i]);
            }

            if(sum == 100) is_answer = true;

            else res.clear();
        }
    }
    
    for(auto nanjang : res){cout << nanjang << endl;}

    return 0;
}