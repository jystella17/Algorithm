#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> v = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0},
    {10, 13, 16, 19, 25, 30, 35, 40, 0},
    {20, 22, 24, 25, 30, 35, 40, 0},
    {30, 28, 27, 26, 25, 30, 35, 40, 0}};

int a[10], ans;

void go(int seq) {
    pii pos[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    bool isEnd[4] = {false};
    int score = 0;

    for (int i = 0; i < 10; ++i) {
        int n = seq & 3; // 00, 01, 10, 11
        seq /= 4;
        if (isEnd[n]) return;

        auto &[r, c] = pos[n];
        c += a[i];
        if (c >= v[r].size() - 1) {
            c = v[r].size() - 1;
            isEnd[n] = true;
        } else if (r == 0 && (c == 5 || c == 10 || c == 15)) {
            r = c / 5;
            c = 0;
        }
		
        for (int m = 0; m < 4; ++m) {
            if (isEnd[n]) break;
            if (n == m) continue;
            if (pos[n] == pos[m]) return;

            const auto &[r1, c1] = pos[m];
            if (v[r][c] == 25 || v[r][c] == 35 || v[r][c] == 40) {
                if (v[r][c] == v[r1][c1]) return;
            }
            if (v[r][c] == 30 && v[r1][c1] == 30) {
                if (r == 3 || r1 == 3) continue;
                return;
            }
        }
        score += v[r][c];
    }
    ans = max(ans, score);
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < (1 << 20); ++i) { // 4^10
        go(i);
    }
    cout << ans;
    return 0;
}
