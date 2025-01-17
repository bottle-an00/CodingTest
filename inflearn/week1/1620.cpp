#include <bits/stdc++.h>
using namespace std;

string arr[100004];
int N, M;
unordered_map<string, int> pocketmon; 
string problem;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        string input;
        cin >> input;
        arr[i] = input;
        pocketmon[input] = i;
    }

  
    for (int i = 0; i < M; ++i) {
        cin >> problem;

        if (isdigit(problem[0])) {
            cout << arr[stoi(problem)] << '\n'; 
        } else {
            cout << pocketmon[problem] << '\n'; 
        }
    }

    return 0;
}
