#include <bits/stdc++.h>
using namespace std;
struct TestInfo{
    int N;
    long long M;
    vector<long long> a;
    int count{};

    TestInfo(int N_, long long M_): N(N_), a(N_,0), M(M_){}
};

void combi(int idx, vector<int>& v, TestInfo& TI){
    if(v.size() == 2){
        long long x = TI.a[v[0]];
        long long y = TI.a[v[1]];
        if(x + y == TI.M){
            ++TI.count;
        }  
        return;
    }
    for(int i = idx+1; i < TI.N; ++i){
        v.push_back(i);
        combi(i,v,TI);
        v.pop_back();
    }
}

int main(){
    int N{};
    long long M{};
    cin >> N;
    cin >> M;
    TestInfo TI(N,M);

    for(int i = 0; i <N; ++i){
        cin >> TI.a[i];
    }

    vector<int> v;
    combi(-1,v,TI);

    cout << TI.count << endl;
    return 0;
}