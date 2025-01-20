#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int get_minimum(int N){
    ll res = 1;
    int count = 1;
    while(1){
        if(res % N == 0) break;
        res = (res*10+1) % N;
        count++;
    }
    return count;
}
int main(){
    string N{};
    while(getline(cin,N)){
        cout << get_minimum(stoi(N)) << endl;
    }
    return 0;
}