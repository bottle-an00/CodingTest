#include <iostream>
#include <map>

using namespace std;
int N{},M{},res{};
map<int,int> a;

int main(){
    cin >> N >> M;
    int tmp{};
    for(int i{};i < N; ++i){
        cin >> tmp; a[tmp]++;
    }
    for(int i{};i < M; ++i){
        cin >> tmp; a[tmp]++;
    }
    for(auto it : a){
        if(it.second == 1) res++;
    }
    cout << res;
    return 0;
}
