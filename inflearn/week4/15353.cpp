#include <iostream>
#include <string>
#include <vector>

using namespace std;
string sum_bignumber(string& bigger, string& smaller){
    int min_size = smaller.size();
    int max_size = bigger.size();
    vector<int> result;
    result.assign(max_size + 1,' ');

    int carry{};
    for(int i{}; i < min_size; ++i){
        int sum = (bigger[bigger.size() - i - 1] - '0' + smaller[smaller.size() - i - 1]- '0' + carry);
        int value = sum % 10;
        carry = sum / 10;

        result[i] = value;
        cout << result[i];
    }
    // for(int i = min_size; i < max_size; ++i){
    //     int sum = (bigger[bigger.size() - i - 1] - '0' + carry);
    //     int value = sum % 10;
    //     carry = sum / 10;
        
    //     result[i] = value;
    //     cout << result[i];
    // }
    string rresult;
    for(int i = max_size; i > 0; --i){
        rresult += to_string(result[i]);
    }
    return rresult;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    string A,B,result;
    cin >> A >> B;
    if(A.size() >= B.size()){
        result = sum_bignumber(A, B);
    }else{
        result = sum_bignumber(B,A);
    }
    cout << result;

    return 0;
}