#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long M; 
    cin >> N >> M;

    vector<int> inputs(N);
    for (int i = 0; i < N; ++i) {
        cin >> inputs[i];
    }

    sort(inputs.begin(), inputs.end());

    int left = 0, right = N - 1;
    int count = 0;

    while (left < right) {
        long long sum = static_cast<long long>(inputs[left]) + inputs[right]; 
        if (sum == M) {
            ++count; 
            ++left;
            --right;
        } else if (sum < M) {
            ++left; 
        } else {
            --right; 
        }
    }

    cout << count << endl;
    
    return 0;
}
