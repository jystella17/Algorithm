// 2025 프로그래머스 코드챌린지 1차 예선 지게차와 크레인 (Lv.2)
// Simulation + DFS

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

string map[52][52];

void internal_to_external(int x, int y){
    bool recursion = false;

    // 입력 받은 칸이 창고 외부와 한 칸이라도 연결되어 있다면
    if(map[x-1][y] == "*" || map[x][y-1] == "*" || map[x+1][y] == "*" || map[x][y+1] == "*"){
        map[x][y] = "*"; // 해당 칸도 창고 외부로 변경
        recursion = true;
    }
    
    if(recursion){ // 입력 받은 칸이 창고 외부 = 인접한 4칸 중 컨테이너가 위치하지 않는 빈 칸은 모두 창고 외부
        // 인접한 4개의 칸 중 컨테이너가 위치하지 않지만 창고 외부로 표기되지 않은 칸(창고 내부의 빈 칸으로 표기된 칸) => 창고 외부로 업데이트
        if(map[x-1][y] == "?"){
            map[x-1][y] = "*";
            internal_to_external(x-1, y);
        }
        
        if(map[x][y-1] == "?"){
            map[x][y-1] = "*";
            internal_to_external(x, y-1);
        }
    
        if(map[x+1][y] == "?"){
            map[x+1][y] = "*";
            internal_to_external(x+1, y);
        }
    
        if(map[x][y+1] == "?"){
            map[x][y+1] = "*";
            internal_to_external(x, y+1);
        }
    }
}

// 지게차로 외부에서 접근 가능한 컨테이너만 꺼내는 경우
void single_req(string query, int n, int m){
    queue<pair<int, int>> candidate;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] != query) continue;

            // 꺼내려는 종류의 컨테이너이면서, 창고 외부와 1면 이상 연결된 컨테이너인 경우
            if(map[i-1][j] == "*" || map[i][j-1] == "*" || map[i+1][j] == "*" || map[i][j+1] == "*"){
                candidate.push(make_pair(i, j));
            }
        }
    }

    // 각 칸의 상태를 도중에 변경하면, 지게차로 꺼낼 수 없는 컨테이너가 잘못 꺼내질 가능성 존재
    // 따라서 꺼낼 수 있는 컨테이너의 위치를 별도로 저장한 후, 마지막에 처리
    while(!candidate.empty()){
        int x = candidate.front().first;
        int y = candidate.front().second;
        candidate.pop();
        
        map[x][y] = "*";
        // 컨테이너를 꺼내고 남은 빈 칸이 창고 외부와 연결되어 있다면, 해당 칸도 창고 외부로 변경
        internal_to_external(x, y);
    }
}

// 크레인으로 한 종류의 모든 컨테이너를 꺼내는 경우
void multiple_req(string query, int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] == query){
                map[i][j] = "?"; // 컨테이너를 꺼내고 남은 빈 칸은 우선 창고 내부의 빈 공간인 것으로 가정
                internal_to_external(i, j); // 창고 외부와 연결된 칸이라면 해당 칸도 창고 외부로 변경
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n = storage.size();
    int m = storage[0].size();

    // 창고를 둘러싼 외부 공간을 1칸씩 *로 초기화
    for(int i=0; i<=n+1; i++){
        map[i][0] = "*";
        map[i][m+1] = "*";
    }
    for(int j=0; j<=m+1; j++){
        map[0][j] = "*";
        map[n+1][j] = "*";
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            map[i][j] = storage[i-1][j-1];
    
    for(auto req: requests){
        if(req.size() == 1) single_req(req, n, m);
        else multiple_req(string(1, req[0]), n, m);
    }
    
    // 전체 map을 돌면서 빈 칸이 아닌 칸 수 세기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] == "*" || map[i][j] == "?") continue;
            answer++;
        }
    }
    
    return answer;
}
