#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string input, bomb;
    cin >> input;
    cin >> bomb;

    stack<char> s;
    for(auto ch : input){
        s.push(ch);

        if(s.size() >= bomb.size() && s.top() == bomb[bomb.size()-1]){
            string target;
            for(auto e : bomb) {
                target += s.top();
                s.pop();
            }
            reverse(target.begin(),target.end());
            if(target != bomb) {
                for(auto e : target) s.push(e);
            } 
        }
    }
    string res;
    while(s.size()){
        res += s.top();
        s.pop();
    }
    reverse(res.begin(),res.end());
    cout << (res.size() ? res : "FRULA");
    return 0;
}
