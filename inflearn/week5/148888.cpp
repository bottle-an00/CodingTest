#include <iostream>
#include <limits>
using namespace std;

int N, db[12], op[4];
long long min_res = numeric_limits<long long>::max();
long long max_res = numeric_limits<long long>::min();

void go(int status[4], int idx, long long result){
    if(idx == N - 1){
        min_res = min(min_res, result);
        max_res = max(max_res, result);
        return;
    }

    for(int i = 0; i < 4; ++i){
        if(status[i] == 0) continue;

        int tmp[4];
        for(int j = 0; j < 4; ++j) tmp[j] = status[j];
        tmp[i]--;

        long long next = result;
        if(i == 0) next = result + db[idx+1];
        else if(i == 1) next = result - db[idx+1];
        else if(i == 2) next = result * db[idx+1];
        else {
            if(db[idx+1] == 0) continue;
            if(result < 0)
                next = -(-result / db[idx+1]);
            else
                next = result / db[idx+1];
        }
        
        go(tmp, idx+1, next);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> db[i];
    for(int i = 0; i < 4; ++i) cin >> op[i];

    go(op, 0, db[0]);
    cout << max_res << '\n' << min_res;
    return 0;
}
