#include <iostream>
#include <limits>
#include <vector>

using namespace std;
int N{},M{},res{numeric_limits<int>::max()},max_l{numeric_limits<int>::min()};
vector<int> v;

bool check_possible(int mid){
    int left_money{mid}, cnt{1};
    for(auto e : v){
        if(mid  < e) return false;
        if(e > left_money) {
            left_money = mid -e;
            cnt++;
        }
        if(left_money >= e){
            left_money -= e;
        }
        if(cnt > M) return false;
    }
    return true;
}

int main(){
    cin >> N >> M;
    v.assign(N,0);
    for(int i{}; i < N; ++i){
        cin >> v[i];
        max_l = max(max_l,v[i]);
    }
    int l{1},r{max_l*M};
    while(l<=r){
        int mid = (l+r) / 2;
        if(check_possible(mid)){
            res = min(res,mid);
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}