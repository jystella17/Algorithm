// 백준 G3 사다리 조작
// DFS, BFS, 백트래킹 응용 연습하기

#include <iostream>
#include <vector>
using namespace std;

int n, m, h, target;
int answer = 987654321;
bool ladder[31][11] = {false, };

bool is_ladder(){
    for(int i=1; i<=n; i++){
        int current = i;
        for(int j=1; j<=h; j++){
            // 현재 위치에 가로선이 있고 옆의 세로줄로 이동 가능한 경우
            if(ladder[j][current] == true && current+1 <= n)
                current++;
            
            else if(ladder[j][current-1] == true && current-1 >= 1)
                current--;
        }
        
        if(current != i)
            return false;
    }
    return true;
}

void dfs(int horizontal, int vertical, int cnt){
    if(cnt == target){
        if(is_ladder())
            answer = cnt;
            
        return;
    }
    
    for(int i=horizontal; i<=h; i++, vertical=1){
        for(int j=vertical; j<n; j++){
            // 이미 해당 위치에 사다리가 있는 경우
            if(ladder[i][j] || ladder[i][j-1] || ladder[i][j+1])
                continue;
            
            ladder[i][j] = true;
            dfs(i, j, cnt+1);
            ladder[i][j] = false;
        }
    }
}

int main(){
    cin>>n>>m>>h;
    
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        
        ladder[a][b] = true;
    }
    
    // 가로선을 i개 추가할 때, 사다리가 원하는 대로 조작되는지 판단 
    for(int i=0; i<4; i++){
        target = i;
        dfs(1, 1, 0);
        
        if(answer != 987654321){
            cout<<answer<<"\n";
            return 0;
        }
    }
    
    // 가로선을 4개 이상 추가해야 하거나, 아예 조작이 불가능한 경우
    cout<<-1<<"\n";
    return 0;
}
