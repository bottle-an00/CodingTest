#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int N{},M{},K{},a[10][10],board[10][10],dead[10][10];
map<int,int> tree[10][10];

const int dr[8] = {-1,-1,-1,
                    0,    0,
                    1,1,1 };

const int dc[8] = {-1,0,1,
                   -1,  1,
                   -1,0,1};

int count_lived_tree(){
    int cnt{};

    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            for(auto e : tree[r][c]){
                cnt += e.second;
            }
        }
    }

    return cnt;
}

void do_spring() {
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            vector<pair<int,int>> temp;
            for(auto& e : tree[r][c]){
                temp.emplace_back(e.first, e.second);
            }

            sort(temp.begin(), temp.end());

            map<int,int> new_tree;
            for(auto& e: temp){
                int age = e.first, count = e.second;
                int need = age * count;
                if(count){
                    if(board[r][c] >= need){
                        board[r][c] -= need;
                        new_tree[age + 1] += count;
                    } else {
                        int can_live = board[r][c] / age;
                        board[r][c] -= age * can_live;
                        new_tree[age + 1] += can_live;

                        int dead_num = count - can_live;
                        dead[r][c] += (age / 2) * dead_num;
                    }
                }
            }

            tree[r][c] = new_tree;
        }
    }
}

void do_summer(){
    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            board[r][c] += dead[r][c];
        }
    }
}

void do_autumn(){
    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            for(auto& e : tree[r][c]){
                if(e.second && e.first % 5 == 0){
                    for(int i{}; i < 8; ++i){
                        int nr = r + dr[i], nc = c + dc[i];
                        if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                        tree[nr][nc][1] += 1 * e.second;
                    }
                }
            }
        }
    }
}

void do_winter(){
    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            board[r][c] += a[r][c];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            board[r][c] = 5;
            dead[r][c] = 0;
        }
    }

    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            cin >> a[r][c];
        }
    }
    for(int i{}; i < M; ++i){
        int x{},y{},age{};
        cin >> x >> y >> age;
        tree[--x][--y][age]++;
    }

    while(K--){

        do_spring();
        do_summer();
        do_autumn();
        do_winter();
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < N; ++c){
                dead[r][c] = 0;
            }
        }
    }

    cout << count_lived_tree();
    return 0;
}