// 코드트리 정수 사각형 최장 증가 수열
// Memoization 풀이

#include <iostream>
#include <algorithm>
using namespace std;

int n, answer = 0;
int map[502][502], dp[502][502];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int find_LIS(int x, int y){
    if(dp[x][y] > 0) // 이미 LIS 값을 구한 좌표라면 해당 값 리턴
        return dp[x][y];

    int result = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <= 0 || nx > n || ny <= 0 || ny > n || map[nx][ny] <= map[x][y])
            continue;

        dp[x][y] = max(find_LIS(nx, ny) + 1, dp[x][y]);
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            answer = max(find_LIS(i, j), answer);

    cout<<answer + 1<<"\n";
    return 0;
}
