// 백준 G3 인싸들의 가위바위보
// Backtracking + Implementation

#include <iostream>
using namespace std;

int n, k, answer;
int rcp[10][10]; // 가위바위보 상성
int play[3][20]; // 각 플레이어가 경기에서 내는 손동작
int win_cnt[3] = {0, }; // 각 플레이어가 이긴 횟수
int turn[3] = {0, }; // 각 플레이어가 경기에 참가한 횟수

bool is_already(int hand){
    for(int i=0; i<turn[0]; i++){
        if(play[0][i] == hand)
            return true;
    }
    return false;
}

void dfs(int player1, int player2){
    if(win_cnt[0] == k || answer == 1){ // 지우의 승리 횟수가 우승 조건을 달성한 경우
        answer=1;
        return;
    }
    
    //  경희 or 민호가 승리 횟수를 먼저 달성했거나
    // 지우가 모든 손동작을 냈지만 아직 우승자가 결정되지 않은 경우
    if(win_cnt[1] == k || win_cnt[2] == k || turn[0] > n){
        answer=0;
        return;
    }
    
    for(int i=1; i<=n; i++){ // 모든 손동작을 탐색하면서 지우가 이번 턴에 각 손동작을 낼 수 있는지 결정
        if(player1!=0 && player2!=0) // 이번 턴에 지우가 참가하지 않는다면
            // 더이상 탐색하지 않고 경희가 민호가 이번 턴에 낼 손동작에 관련된 정보만 처리하도록
            i=n; // 인덱스를 최대값으로 업데이트
        
        else{
            if(is_already(i)) // 지우가 현재 손동작을 낸 적이 있다면
                continue;
            
            play[0][turn[0]] = i; // 낸 적 없는 손동작이라면 이번 턴에 내도록 설정
        }
        
        // player1, player2 중 승자 결정
        int winner = 0;
        int hand1 = play[player1][turn[player1]]; // player1이 이번 턴에 내는 손동작 번호
        int hand2 = play[player2][turn[player2]]; // player2가 이번 턴에 내는 손동작 번호
        
        if(rcp[hand1][hand2] == 2)
            winner = player1;
        else if(rcp[hand1][hand2] == 0)
            winner = player2;
        else // 비기는 경우
            winner = (player1 < player2) ? player2 : player1;
            
        // Backtracking으로 다음 탐색 수행
        turn[player1]++;
        turn[player2]++;
        win_cnt[winner]++;
        
        dfs(winner, 3-(player1+player2));
        
        turn[player1]--;
        turn[player2]--;
        win_cnt[winner]--;
        
    }
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>rcp[i][j];
            
    for(int i=0; i<20; i++)
        cin>>play[1][i]; // 경희가 낼 손동작
    for(int i=0; i<20; i++)
        cin>>play[2][i]; // 민호가 낼 손동작
    
    dfs(0, 1); // 지우와 경희가 첫 번째 경기 시작
    cout<<answer<<"\n";

    return 0;
}
