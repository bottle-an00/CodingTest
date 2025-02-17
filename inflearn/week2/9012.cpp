#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T{};
    cin >> T;
    while(T--){
        string input;
        cin >> input;
        stack<char> s;
        for(int i = 0; i < input.size(); ++i){
            if(s.size() && s.top() - input[i] && input[i] == ')'){
                s.pop();
            }else{
                s.push(input[i]);
            }
        }
        if(s.size()) cout << "NO\n";
        else cout <<"YES\n";
    }
    return 0;
}