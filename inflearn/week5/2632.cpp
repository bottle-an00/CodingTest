#include <iostream>
#include <map>

using namespace std;

int S{},N{},M{},A[1001],B[1001],psum_A[2002],psum_B[2002];
map<int,int> Acnt, Bcnt;

void make(int n, int psum[], map<int, int> & mp){
    for(int interval = 1; interval <= n; interval++){
        for(int start = interval; start <= n + interval - 1; start++){
            int sum = psum[start] - psum[start - interval];
            mp[sum]++;
            if(interval == n) break;
        }
    }
}

int main(){
    cin >> S;
    cin >> M >> N;
    for(int m{1}; m <= M; ++m){
        cin >> A[m];
        psum_A[m] = psum_A[m-1] + A[m];
    }
    for(int i{M+1}; i < 2*M; ++i){
        psum_A[i] = psum_A[i-1] + A[i-M];
    }
    for(int n{1}; n <= N; ++n){
        cin >> B[n];
        psum_B[n] = psum_B[n-1] + B[n];
    }
    for(int i{N+1}; i < 2*N; ++i){
        psum_B[i] = psum_B[i-1] + B[i-N];
    }
    make(M, psum_A, Acnt);
    make(N, psum_B, Bcnt);
    int res = (Acnt[S] + Bcnt[S]);
    for(int i = 1; i < S; i++){
      res += (Acnt[i] * Bcnt[S - i]);
    }
    cout << res;
    return 0;
}