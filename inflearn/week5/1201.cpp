#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N{},M{},K{},cnt{},idx{};
    vector<int> res;

    cin >> N >> M >> K;
    if(N > M*K || N < M+K-1) {
        cout << "-1"; 
        return 0;
    }
    for(int i{1}; i <= M; ++i){
        int k_b = K; 
        if(cnt)k_b = min(K, (N-cnt)/(M-i+1));
        idx += k_b;
        for(int j{}; j < k_b; ++j){
            res.push_back(idx - j);
            cnt++;
        }
    }
    for(auto e : res){
        cout << e << " ";
    }
    return 0;
}