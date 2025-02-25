#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> scv;
int damage[3] = {9,3,1}, N, result{__INT_MAX__};
bool is_all_dead(vector<int> scvs){
    for(auto u : scvs){
        if(u > 0 ) return false;
    }
    return true;
}
void solve_12869(vector<int> scv, int count = 0){
    do{
        vector<int> damaged_scv;
        int i{};
        if(count > result) break;
        if(is_all_dead(scv)){
            result = min(result, count);
            break;
        }
        for(auto e : scv){
            damaged_scv.push_back(e - damage[i++]);
        }
        sort(damaged_scv.begin(),damaged_scv.end(),[](int a, int b){return a > b;});
        solve_12869(damaged_scv,count + 1);
    }while(prev_permutation(scv.begin(),scv.end()));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int hp;
        cin >> hp;
        scv.push_back(hp);
    }
    sort(scv.begin(),scv.end(),[](int a, int b){return a > b;});
    solve_12869(scv);
    cout << result << "\n";
    return 0;
}