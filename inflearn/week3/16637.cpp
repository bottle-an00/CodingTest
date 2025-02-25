#include <iostream>
#include <stack>
#include <string>
#include <climits>
using namespace std;
string equation;
int N{},result{INT_MIN};
int calculate(int a, char op, int b){
    if(op == '+')return a+b;
    if(op == '*')return a*b;
    if(op == '-')return a-b;
    return 0;
}
void solve_16337(int idx, int currnet_value){
    if(idx >= N){
        result = max(result, currnet_value);
        return;
    }
    char op = (idx == 0)? '+' : equation[idx-1];
    int num = calculate(currnet_value,op, equation[idx] - '0');
    solve_16337(idx + 2, num);
    
    if(idx +2 < N){
        int bracket_value = calculate(equation[idx]-'0', equation[idx+1],equation[idx+2]-'0');
        solve_16337(idx+4, calculate(currnet_value, op, bracket_value));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    cin >> equation;
    solve_16337(0,0);
    cout << result << endl;
    return 0;
}