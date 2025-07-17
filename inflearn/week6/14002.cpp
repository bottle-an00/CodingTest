#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N{},a[1004], lis[1004],cnt[1004],len{};
vector<int> v;
int main(){
    scanf("%d",&N);
    int num{};
    fill(&lis[0],&lis[0]+N,0);
    fill(&cnt[0],&cnt[0]+N,-1);
    for(int i{}; i < N; ++i){
        scanf("%d",&num);
        a[i] = num;
        auto it = lower_bound(lis,lis+len,num);
        if(*it == 0) len++;
        *it = num;

        cnt[i] = it-&lis[0];
    }

    printf("%d\n",len);
    for(int i{N-1}; i >= 0; --i){
        if(cnt[i] == len-1){
            v.push_back(a[i]);
            len--;
        }
    }
    reverse(v.begin(),v.end());
    for(auto e : v){
        printf("%d ", e);
    }
    return 0;
}