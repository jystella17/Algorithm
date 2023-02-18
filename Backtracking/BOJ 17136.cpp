// 백준 G2 색종이 붙이기
// Backtracking + Implementation

#include <iostream>
#include <algorithm>
using namespace std;

int answer = 987654321;
int papers[5] = {5, 5, 5, 5, 5};
int board[10][10];

bool is_zero(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(board[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool in_range(int x, int y, int size){
    if(x+size < 10  && y+size < 10)
        return true;
    
    return false;
}

bool can_attach(int x, int y, int size){
    for(int i=x; i<=x+size; i++){
        for(int j=y; j<=y+size; j++){
            if(board[i][j] == 0)
                return false;
        }
    }
    return true;
}

void update(int x, int y, int size, int content){
    for(int i=x; i<=x+size; i++)
        for(int j=y; j<=y+size; j++)
            board[i][j] = content;
}

void dfs(int cnt){ // cnt == 현재까지 붙인 색종이 개수
    // 모든 종이에 0이 적혀 있어 색종이를 붙일 필요가 없는 경우
    if(is_zero()){
        answer = min(answer, cnt);
        return;
    }
    
    if(answer < cnt) // 현재 붙어있는 색종이 개수가 필요한 색종이의 최소 개수인 경우
        return;
        
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(board[i][j] == 1){ // 색종이를 붙일 수 있는 칸이 발견되면
                for(int k=4; k>=0; k--){ // 크기가 큰 색종이부터 붙일 수 있는지 확인
                    // 해당 크기의 색종이가 남아있고 & 색종이가 board 범위 내에 있고 & 
                    // 색종이를 붙일 종이에 모두 1이 적혀있는 경우
                    if(papers[k]>0 && in_range(i, j, k) && can_attach(i, j, k)){
                        update(i, j, k, 0); // 색종이를 붙인 구역은 모두 0으로 업데이트 (다른 색종이를 붙이지 못하도록)
                        papers[k]--; // 해당 색종이를 사용했으므로 재고 -1
                        
                        dfs(cnt+1);
                        
                        update(i, j, k, 1); // 원상복구
                        papers[k]++;
                    }
                }
                return; // 모든 종류의 색종이에 대해 부착 여부를 검사했다면 함수 종료
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cin>>board[i][j];
    
    dfs(0);
    
    if(answer == 987654321)
        answer = -1;
        
    cout<<answer<<"\n";
    return 0;
}
