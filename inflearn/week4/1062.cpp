#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N,K,max_learned = 0;
int used_wordlist{};
vector<int> wordDB;

void go(int wordlist, int mask, int num){
    if(num > K-5) return;

    int count{};

    for(auto word : wordDB){
        if((word & mask) == word) ++count;
    }
    max_learned = max(max_learned, count);

    int idx = wordlist & - wordlist;
    if(idx == 0) return;

    idx = log2(idx);
    wordlist &= ~(1 << idx);

    // idx를 사용하지 않는 경우
    go(wordlist, mask, num);
    // idx를 사용한 경우
    mask |= 1 << idx;
    go(wordlist, mask, num+1);
}

int solve_1062(){
    if(K < 5) return 0;

    int default_mask{};
    int defalut_idx[5] = {'a'-'a','c'-'a','i'-'a','t'-'a','n'-'a'}; 
    for(auto idx : defalut_idx){
        default_mask |= 1 << idx; 
        // 필수로 사용할 글자는 나중에 택해야하는 글자에서 제외
        used_wordlist &= ~(1 << idx);
    } 

    go(used_wordlist,default_mask,0);

    return max_learned;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    cin.ignore();

    for(int i = 0; i < N; ++i){
        string input;
        getline(cin,input);
        int word{};
        for(int j = 0; j < input.size(); ++j){
            // 알파벳을 idx로 하여 기록
            word |= (1 << (input[j] -'a')); 
            used_wordlist |= (1 << (input[j] -'a')); 
        }
        wordDB.push_back(word);
    }

    cout << solve_1062();

    return 0;
}