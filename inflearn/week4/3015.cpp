#include <iostream>
#include <stack>

using namespace std;

int N{};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> N;

    int cnt{};   
    stack<int> stk;
    for(int i{}; i < N; ++i){
        int e;
        bool flag = false;
        cin >> e;
        if(stk.empty()){
            stk.push(e);
        }else{
            while(!stk.empty() && e > stk.top()){
                stk.pop();
                cnt++;
                flag = true;
            }
            stk.push(e);
            if(!flag)cnt++;
        }
    }

    cout << cnt;
    return 0;
}