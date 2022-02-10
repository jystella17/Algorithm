#include <iostream>
#include <string>
#include <algorithm>
#define INF 31313131

using namespace std;

int main(){ // Floyd Warshall
    int n, m, answer = 0;
    int cost[101][101];
    cin>>n>>m;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cost[i][j] = (i==j ? 0:INF); // 전체 인접행렬에 대해 출발도시와 도착 도시가 같은 경우 cost 0, 다른 경우 최대값인 INF로 초기화
    
    for(int i=0; i<m; i++){
        int start, end, fee;
        cin>>start>>end>>fee;
        
        cost[start][end] = min(cost[start][end], fee); // A 도시에서 B 도시로 가는 노선이 하나 이상일 수 있음
        // min으로 이미 저장된 값과 현재 값 중 작은 것을 저장 (가장 저렴한 노선)
    }
    
    for(int k=1; k<=n; k++) // 경유 도시 번호
        for(int i=1; i<=n; i++) // 출발 도시 번호
            for(int j=1; j<=n; j++) // 도착 도시 번호
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cost[i][j]==INF ? cout<<'0'<<' ':cout<<cost[i][j]<<' '; // INF, 즉 A -> B로 가는 노선이 없는 경우 0, A==B 인 경우 어차피 0이 출력되므로 조건문에서 고려할 필요 없음
            
        cout<<endl;
    }
    return 0;
}
