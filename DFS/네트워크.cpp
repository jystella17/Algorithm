// 프로그래머스 LV.3 네트워크

#include <string>
#include <vector>
using namespace std;

bool visited[200];

void dfs(vector<vector<int>> &computers, int start){
    visited[start] = true;
    
    for(int i=0; i<computers.size(); i++){
        if(start == i) // computers[i][i]는 자기 자신이므로 제외
            continue;
        
        if(!visited[i] && computers[start][i])
            dfs(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){ // 각 컴퓨터에 대해 탐색
        if(!visited[i]){ // 해당 컴퓨터를 아직 한 번도 탐색하지 않았다면(지금까지 네트워크에 연결된 적 없는 컴퓨터)
            answer++; // 네트워크 개수 1개 추가
            dfs(computers, i);
        }
    }
    
    return answer;
}
