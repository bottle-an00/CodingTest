#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void solve_17298(const vector<int>& inputs) {
    int n = inputs.size();
    vector<int> NGE(n, -1);  
    stack<int> s;  
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= inputs[i]) {
            s.pop();
        }
        if (!s.empty()) {
            NGE[i] = s.top();
        }
        s.push(inputs[i]);
    }
    for (int e : NGE) {
        cout << e << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N{};
    cin >> N;
    vector<int> input;
    for(int i = 0; i < N; ++i){
        int num{};
        cin >> num;
        input.push_back(num);
    }
    solve_17298(input);
    return 0;
}