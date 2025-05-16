#include <iostream>
#include <string>
#include <vector>
using namespace std;

int M{},S{};
int check_func(string str){
    vector<string> list = {"add", "remove", "check", "toggle", "all" ,"empty"};
    for(int i = 0; i < list.size(); ++i){
        if(str == list[i]) return i;
    }
    return -1;
}

void add(int x){
    S |= 1 << x;
}

void remove(int x){
    S &= ~(1 << x);
}

void check(int x){
    if(S & (1 << x)) cout << "1\n";
    else cout << "0\n";
}

void toggle(int x){
    if(S & (1 << x)) S &= ~(1 << x);
    else S |= 1 << x;
}

void all(){
    S = (1 << 25) -1;
} 

void empty(){
    S = 0;
}

void solve_11723(string str, int x){
    int idx = check_func(str);
    if(idx == -1) cout <<"Invalid Function Name\n";
    switch(idx){
        case 0:
            add(x);
            break;
        case 1:
            remove(x);
            break;
        case 2:
            check(x);
            break;
        case 3:
            toggle(x);
            break;
        case 4:
            all();
            break;
        case 5:
            empty();
            break;
        default:
            cout << "Invalid idx!\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> M;
    cin.ignore();
    for(int i = 0; i < M; ++i){
        int x{};
        string str;
        cin >> str;
        if(str != "all" && str != "empty") {
            cin >> x; 
        }
        solve_11723(str,x);
    }
        
    return 0;
}