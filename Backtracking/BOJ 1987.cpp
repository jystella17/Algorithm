// 백준 G4 알파벳
// 백트래킹 기본

#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int r, c, answer = 0;
char board[21][21];
bool visited[26] = {false, }; // 각 알파벳을 index에 매핑해서 해당 알파벳 방문 여부 저장

void dfs(int x, int y, int cnt){
    answer = max(answer, cnt);
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int next_alphabet = board[nx][ny] - 'A';
        
        if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(!visited[next_alphabet]){
                visited[next_alphabet] = true;
                dfs(nx, ny, cnt+1);
                visited[next_alphabet] = false;
            }
        }
    }
}

int main(){
    cin>>r>>c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cin>>board[i][j];
    }
    
    int alphabet = board[0][0] - 'A'; // 첫 번째 칸은 항상 방문
    visited[alphabet] = true;
    dfs(0, 0, 1);
    
    cout<<answer<<"\n";
    return 0;
}
