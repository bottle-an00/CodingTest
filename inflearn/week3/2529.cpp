#include <iostream>
#include <string>
#include <climits>
using namespace std;

string input, result;
bool visited[10]{false};
long long max_{LONG_LONG_MIN},min_{LONG_LONG_MAX},k;

void DFS(int u){
    int step = result.size();
    if(step == k + 1){
        max_ = max(max_, stoll(result));
        min_ = min(min_, stoll(result));
        return;
    }
    for(int i = 0; i < 10; ++i){
        if(visited[i]) continue;
        if((input[step-1] == '>' && u > i) || (input[step-1] == '<' && u < i)){
            visited[i] = true;
            string tmp = result;
            result = result + to_string(i);
            DFS(i);
            result = tmp;
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> k;
    for(int i = 0; i < k; ++i){
        char n;
        cin >> n;
        input += n;
    }
    for(int i = 0; i < 10; ++i){
        result += to_string(i);
        visited[i] = true;
        DFS(i);
        result.pop_back();
        visited[i] = false;
    }

    if(to_string(max_).size() < k + 1) cout << "0"+to_string(max_) << "\n";
    cout << max_ << "\n";
    if(to_string(min_).size() < k + 1) cout << "0"+to_string(min_) << "\n";
    else cout << min_ << "\n";
    
    return 0;
}