#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N{},len{},lis[104];
vector<pair<int,int>> v;

int main(){
    scanf("%d",&N);
    for(int i{}; i < N; ++i){
        int a{},b{};
        scanf("%d %d",&a,&b);
        v.emplace_back(a,b);
    }
    sort(v.begin(),v.end());

    for(int i{}; i < N; ++i){
        auto it = lower_bound(lis,lis+len,v[i].second);
        if(*it == 0) len++;
        *it = v[i].second;
    }
    printf("%d", N-len);

    return 0;
}
