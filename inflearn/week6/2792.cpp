#include <iostream>
#include <vector>
#include <limits>

using namespace std;
int N{},M{},max_j{},res{numeric_limits<int>::max()};
vector<int> v;

bool can_divide(int mid){
    int sum{};
    for(auto e: v){
        sum += e / mid + (e % mid ? 1 : 0);
    }
    if(sum > N) return false;
    else return true;
}

int main(){
    cin >> N >> M;
    v.assign(M,0);
    for(int i{}; i < M; ++i){
        cin >> v[i];
        max_j = max(max_j, v[i]);
    }

    int l{1}, r{max_j};
    while(l <= r){
        int mid = (l + r) / 2;
        if(can_divide(mid)){
            res = min(res,mid);
            r = mid -1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}