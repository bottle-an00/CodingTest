#include <iostream>
#include <string>
using namespace std;

int pre{1};
int find_six(string input){
    int count{0};
    for(int i = input.size()-1; i >= 0; --i){
        if(input[i] == '6') ++count;
        else break;
    }
    return count;
} 
string solve_1436(int N){
    string base = "666";
    string next = base;
    int i = 1;
    while(i < N){
        int count = find_six(to_string(pre));
        next = to_string(pre) + base;
        string next4post = next.substr(0, next.size() - count);
        int post{},post_i{};
        while(count != 0 && to_string(post).size() <= count){
            if(i + post_i == N ) break;
            next = next4post + to_string(post);
            ++post; ++post_i;
        }
        if(i == N) break;
        ++i; ++pre;
        i += (count) ? post_i-1 : post_i;
    }
    return next;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N{};
    cin >> N;
    string result = solve_1436(N);
    cout << result;
    return 0;
}
