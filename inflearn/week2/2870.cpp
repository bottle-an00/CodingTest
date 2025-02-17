#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool is_word(char target){
    return target >= 'a' && target <= 'z';
}
vector<string> solve_2870(string input, vector<string>& vec){
    string buffer{};
    bool flag = 0;
    for(int i = 0; i < input.size(); ++i){
        if(!is_word(input[i])){
            if(flag && buffer[0] == '0') buffer ="";
            buffer += input[i];
            flag = 1;
            if(i == input.size()-1) vec.push_back(buffer);
        }else{
            if(flag){
                flag = 0;
                vec.push_back(buffer);
                buffer="";
            }
        }
    }
    return vec;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N{};
    cin >> N;
    vector<string> result;
    for(int i = 0; i < N; ++i){
        string input;
        cin >> input;
        solve_2870(input,result);
    }
    sort(result.begin(),result.end(),[](string a, string b){
        if (a.size() != b.size()) return a.size() < b.size();  // 길이가 짧은 순서
        return a < b;  // 같은 길이면 문자열 비교 (사전순 == 숫자 크기 비교)
    });
    for(auto e : result){
        cout << e << endl;
    }
    return 0;
}
