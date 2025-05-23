#include <iostream>
#include <stack>
using ii = std::pair<int,int>;
using namespace std;

int N{};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> N;

    long long cnt{};   
    stack<ii> stk;
    for(int i{}; i < N; ++i){
        int e,same{1};
        cin >> e;

        if(stk.empty()){
            stk.emplace(e,1);
        }else{
            
            while(!stk.empty() && e >= stk.top().first){
                cnt += stk.top().second;

                if(stk.top().first == e){
                    same = stk.top().second + 1;
                }

                stk.pop();
            }
            
            if(!stk.empty()) ++cnt; 

            stk.emplace(e,same);
        }
    }

    cout << cnt;
    return 0;
}