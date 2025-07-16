#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N{},M{},res{numeric_limits<int>::max()},max_L{};
vector<int> v;

bool check_possible(int mid){
    int sum{},cnt{1};
    for(auto e : v){
        if(mid < e) return false;
        if(sum + e > mid){
            cnt++;
            sum = e;
        }else{
            sum += e;
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
        max_L += v[i];
    }

    int l{1},r{max_L};
    while(l <= r){
        int mid = (l + r) / 2;
        if(check_possible(mid)){
            res = min(res,mid);
            r = mid -1;
        }else{
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}