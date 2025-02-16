#include <iostream>
using namespace std;

void solve_3474(int input){
    int result{};
    int divide_value{5};
    while(input >= divide_value){
        int number = input / divide_value;
        result += number;
        divide_value *= 5;
    }
    cout << result<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N{};
    cin >> N;
    for(int i = 0; i < N; ++i){
        int input;
        cin >> input;
        solve_3474(input);
    }
    return 0;
}