#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

struct Score {
    int score;
    double percentage;
    Score(int s, double p) : score(s), percentage(p) {}
};

bool isPrime[19];

void initPrime() {
    for (int i = 2; i <= 18; ++i) isPrime[i] = true;
    for (int i = 2; i * i <= 18; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= 18; j += i) {
            isPrime[j] = false;
        }
    }
}

double combination(int n, int r) {
    double res = 1.0;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;

    double pA = a / 100.0;
    double pB = b / 100.0;

    initPrime();

    vector<Score> distA, distB;

    for (int i = 0; i <= 18; ++i) {
        double prob = combination(18, i) * pow(pA, i) * pow(1 - pA, 18 - i);
        distA.emplace_back(i, prob);
    }

    for (int j = 0; j <= 18; ++j) {
        double prob = combination(18, j) * pow(pB, j) * pow(1 - pB, 18 - j);
        distB.emplace_back(j, prob);
    }

    double answer = 0.0;

    for (auto& A : distA) {
        for (auto& B : distB) {
            if (isPrime[A.score] || isPrime[B.score]) {
                answer += A.percentage * B.percentage;
            }
        }
    }

    cout << fixed << setprecision(10) << answer << '\n';
    return 0;
}
