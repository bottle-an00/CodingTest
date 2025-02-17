#include <iostream>
using namespace std;

bool find_six(string input){
    return input.find("666") != std::string::npos;
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    int target_num{},i{};
    while(i != N){
        ++target_num;
        if(find_six(to_string(target_num))) ++i;
    }
    cout << target_num << endl;
    return 0;
}
