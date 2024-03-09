// 코드트리 정수 사각형 최장 증가 수열
// Tabulation

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 0;
int map[502][502], dp[502][502];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

priority_queue<pair<int, pair<int, int>>> spot_list;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];

            dp[i][j] = 1;
            spot_list.push(make_pair(-map[i][j], make_pair(i, j)));
        }
    }

    while(!spot_list.empty()){
        int val = -spot_list.top().first;
        int cx = spot_list.top().second.first;
        int cy = spot_list.top().second.second;

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n || val <= map[nx][ny])
                continue;

            dp[cx][cy] = max(dp[nx][ny] + 1, dp[cx][cy]);
            answer = max(dp[cx][cy], answer);
        }
        spot_list.pop();
    }

    cout<<answer<<"\n";
    return 0;
}
