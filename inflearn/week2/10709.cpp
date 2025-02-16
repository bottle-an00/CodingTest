#include <iostream>
#include <string>

using namespace std;

void solve_10709(string input){
    int prev_cloud_location = -1;
    string result{};
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == 'c'){
            prev_cloud_location = i;
            result += "0 ";
        }else{
            prev_cloud_location < 0 ? result += "-1 " : result += to_string(i - prev_cloud_location) + " ";
        }
    }
    cout << result << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H{},W{};
    cin >> H >> W;
    cin.ignore();
    for(int i = 0; i < H; ++i){
        string input;
        cin >> input;
        solve_10709(input);
    }
    return 0;
}