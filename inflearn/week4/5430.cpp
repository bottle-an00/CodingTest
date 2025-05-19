#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
using namespace std;

int T{},N{};
string p,num_list; 
deque<int> num_deque;

string solve_5430(queue<char> func_list){
    int orientation = 0;

    while(!func_list.empty()){
        char func = func_list.front();
        func_list.pop();

        if(func == 'R'){// 뒤집기
            orientation = 1 - orientation;
        }else{//가장 첫번째 제거
            if(num_deque.size() == 0) return "error";

            if(orientation) num_deque.pop_back(); // 뒤집힌 상태
            else num_deque.pop_front(); 
        }
    }
    //결과
    string result = "[";
    while(!num_deque.empty()){
        if(orientation){
            result += to_string(num_deque.back());
            num_deque.pop_back();
        }else{
            result += to_string(num_deque.front());
            num_deque.pop_front();
        }
        if(!num_deque.empty()) result += ",";
    }
    result += "]";

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    
    cin >> T;    
    cin.ignore();

    for(int t{}; t < T; ++t){
        num_deque.clear();
        queue<char> func_list;        

        cin >> p;
        for(int i = 0; i < p.size(); ++i){
            func_list.push(p[i]);
        }
        cin >> N;
        cin.ignore();
        cin >> num_list;
        num_list = num_list.substr(1,num_list.size()-2);

        stringstream ss(num_list);
        string num;
        while (getline(ss, num, ',')) {
            num_deque.emplace_back(stoi(num,nullptr,10));
        }
        cout << solve_5430(func_list) << "\n";
    }

    return 0;
}