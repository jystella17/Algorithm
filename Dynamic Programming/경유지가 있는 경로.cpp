# Codetree G5 경유지가 있는 경로

#include <iostream>
using namespace std;

int dp[17][17];

int route_count(int start_x, int start_y, int end_x, int end_y){
    for(int i=start_x+1; i<=end_x; i++){
        for(int j=start_y+1; j<=end_y; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[end_x][end_y];
}

int main() {
    int n, m, k, answer = 0;
    cin>>n>>m>>k;
    fill(&dp[0][0], &dp[n+2][m+2], 1);

    if(k == 0)
        answer = route_count(1, 1, n, m);
    
    else{
        int via_x = k / m; int via_y = k % m;
        if(via_y == 0) via_y = m;
        else via_x += 1;
        
        answer += route_count(1, 1, via_x, via_y);
        dp[via_x][via_y] = 1;
        answer *= route_count(via_x, via_y, n, m);
    }

    cout<<answer<<"\n";
    return 0;
}
