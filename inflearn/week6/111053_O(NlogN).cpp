#include <iostream>
#include <algorithm>
using namespace std;
int N{},lis[1004],num{},len{};

int main(){
    cin >> N;
    fill(&lis[0],&lis[0]+N,0);

    for(int i{}; i < N; ++i){
        cin >> num;
        auto it = lower_bound(lis,lis + len, num);
        if(*it == 0) len++;
        *it = num;
    }
        
    cout << len;
    return 0;
}