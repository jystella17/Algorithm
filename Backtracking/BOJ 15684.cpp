#include<iostream>
#include<algorithm>
using namespace std;
 
int N, M, H;
int map[32][12];
int ans;
 
bool go() {
    for (int X = 1; X <= N; X++) {
        int ch = X;
        for (int Y = 1; Y <= H; Y++) {
            if (map[Y][ch] == 1) {
                ch++;
            }
            else if (map[Y][ch - 1] == 1) {
                ch--;
            }
        }
        if (ch != X) {
            return false;
        }
    }
    return true;
}
 
void dfs(int dep,int x,int y) {
    if (ans <= dep) return;
    if (go()) {
        ans = dep;
        return;
    }
    if (dep == 3) return;
 
    for (int Y = y; Y <= H; Y++) {
        for (int X = x; X <= N; X++) {
            if (map[Y][X] == 0 && map[Y][X - 1] == 0 && map[Y][X + 1] == 0) {
                map[Y][X] = 1;
                dfs(dep + 1, X, Y);
                map[Y][X]=0;
            }
        }
        x = 1;
    }
}
 
int main() {
    ans = 10000000;
    cin >> N >> M >> H;
    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }
    ans = 4;
    dfs(0,1,1);
    if (ans == 4)
        cout << "-1";
    else
        cout << ans;
}
