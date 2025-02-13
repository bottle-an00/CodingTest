#include <iostream>
#include <string>
#include <vector>
#include <format>
using namespace std;
vector<char> vowels = {'a','e','i','o','u'};
bool is_vowels(char target){
    for(int i = 0; i < vowels.size(); ++i){
        if(target == vowels[i]){
            return true;
        }
    }
    return false;
}
bool check_same(char prev, char curr){
    if(prev == curr){
        if(prev == 'o' || prev == 'e') return false;
        return true;
    }
    return false;
}
bool solve_4659(string input){
    bool is_acceptable{true}, vowel_exist{false};
    int count{0};
    char prev{' '};
    for(int i = 0; i < input.size(); ++i){
        bool is_vowel = is_vowels(input[i]);
        if(is_vowel)
        {
            vowel_exist = true;
            is_vowels(prev) ? count += -1 : count = -1;
        }else{
            is_vowels(prev) ? count = 1 : count += 1;
        }
        if(prev != ' ' && check_same(prev,input[i])) 
        {
            is_acceptable = false;
        }
        prev = input[i];
        if(abs(count) > 2) is_acceptable = false;
    }
    if(!vowel_exist) is_acceptable = false;
    return is_acceptable;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    bool exit{false};
    while(1){
        cin >> input;
        if(input == "end") return 0;
        if(solve_4659(input)){
            cout << format("<{}> is acceptable.",input) << endl;
        }else{
            cout << format("<{}> is not acceptable.",input) << endl;
        }
    }
    return 0;
}