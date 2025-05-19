#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int R{},C{}, dataDB[6][6], bitmap[6][6];
// 1이면 세로, 0이면 가로

void make_bitmap(int mask){
    fill(&bitmap[0][0], &bitmap[0][0] + 6*6 ,0);
    for(int i{}; i < R*C; ++i){
        
        int r = i / C;
        int c = i % C;

        bitmap[r][c] = mask & (1 << i) ? 1 : 0;
        
    }
}

int get_total(){
    int result{};
    // [적절히 초기화 해주지 않을 경우 result값이 임의로 설정된다. -> 아마 추측건데 시스템의 버퍼에 남은 값으로 설정된 것으로 보임]
    // int result;
    // cout << "result " << result <<endl;
    for(int r{}; r < R; ++r){
        int cnt{};
        for(int c{C-1}; c >=0; --c){
            if(bitmap[r][c] == 1) cnt = 0;
            else{
                int value{dataDB[r][c]};
                for(int i{}; i < cnt; ++i){
                    value *= 10;
                }
                cnt++;
                result += value; 
            }
        }

    }

    for(int c{}; c < C; ++c){
        int cnt{};
        for(int r{R-1}; r >=0; --r){
            if(bitmap[r][c] == 0) cnt = 0;
            else{
                int value{dataDB[r][c]};
                for(int i{}; i < cnt; ++i){
                    value *= 10;
                }
                cnt++;
                result += value; 
            }
        }

    }
    return result;
}


int solve_14391(){
    int max_total{};

    for(int mask{}; mask < (1 << R*C); ++mask){//bitmasking을 경우의 수로 활용 (brute force)

        make_bitmap(mask);

        int total = get_total();

        max_total = max(max_total, total);
    }

    return max_total;
}

int main(){
    cin >> R >> C;

    cin.ignore();
    for(int r{}; r < R; ++r){
        string x;
        getline(cin,x);
        for(int c{}; c< C; ++c){
            dataDB[r][c] = static_cast<int>(x[c] -'0');
        }
    }

    cout << solve_14391();
    return 0;
}