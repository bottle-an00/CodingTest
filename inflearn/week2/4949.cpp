#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool is_match(char e, char target){
    if(e == ')') return target == '(';
    return target == '[';
}
bool check(string input){
    stack<char> s;
    for(char e : input){
        if(e == '(' || e == '['){
            s.push(e);
        }else if(e == ')' || e == ']'){
            if(!s.empty() && is_match(e,s.top())){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    while(true){
        string input;
        getline(cin,input);
        if(input[0] == '.') break;
        if(check(input)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}