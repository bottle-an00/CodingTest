#include <iostream>
#include <stack>
#include <string>

using namespace std;

int ans{0}, tmp{1};
char prev_letter;

int main(){
    string input_str;
    stack<char> s;
    cin >> input_str;
    int size = input_str.size();
    for(int i{0}; i < size; ++i){
        char letter = input_str[i]; 
        if(letter == '(') {tmp*=2; s.emplace(letter);} 
        if(letter == '[') {tmp*=3; s.emplace(letter);}
        if(letter == ')') {
            if(!s.empty() && s.top() == '('){
                if(prev_letter == '(') ans += tmp; 
                tmp /= 2;
                s.pop();
            }else{
                ans = 0; 
                break;
            }
        } 
        if(letter == ']') {
            if(!s.empty() && s.top() == '['){
                if(prev_letter == '[')ans += tmp; 
                tmp /= 3;
                s.pop();
            }else{
                ans = 0; 
                break;
            }
        }
        prev_letter = letter;
    }
    if(s.empty()) cout << ans << "\n";
    else cout << "0" << "\n"; 

    return 0;
} 