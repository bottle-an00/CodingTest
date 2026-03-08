#include <iostream>
#include <unordered_map>
#include <queue>
#include <tuple>

using namespace std;
int A, B, C, D;

unordered_map<int, unordered_map<int, int>> dist;

int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        int d = dist[a][b];

        if (a == C && b == D) return d;

        pair<int, int> next[6] = {
            {A, b}, {a, B}, {0, b}, {a, 0},
            (a + b <= B) ? make_pair(0, a + b) : make_pair(a - (B - b), B),
            (a + b <= A) ? make_pair(a + b, 0) : make_pair(A, b - (A - a))
        };

        for (auto [na, nb] : next) {
            if (dist[na][nb] == 0 && !(na == 0 && nb == 0)) {
                dist[na][nb] = d + 1;
                q.push({na, nb});
            }
        }
    }

    return -1;
}

int main() {
    cin >> A >> B >> C >> D;
    int ret = bfs();
    cout << ret << '\n';
}
