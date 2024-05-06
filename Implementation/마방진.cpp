// BOJ 2045 마방진 (G3)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int total_sum = 0;
int board[3][3];
vector<int> sum; // 차례대로 1행 합, 2행 합, 3행 합, 1열 합, 2열 합, 3열 합, 우하단 방향 대각선 합, 우상단 방향 대각선 합
vector<pair<int, int>> to_determine;

void find_sum(){
    for(int i=0; i<3; i++){
        int tmp = 0;

        for(int j=0; j<3; j++)
            tmp += board[i][j];

        total_sum = max(total_sum, tmp);
        sum.push_back(tmp);
    }

    for(int j=0; j<3; j++){
        int tmp = 0;

        for(int i=0; i<3; i++)
            tmp += board[i][j];

        total_sum = max(total_sum, tmp);
        sum.push_back(tmp);
    }

    int tmp = 0;
    for(int i=0; i<3; i++){
        tmp += board[i][i];
    }
    total_sum = max(total_sum, tmp);
    sum.push_back(tmp);

    tmp = 0;
    for(int i=0; i<3; i++){
        tmp += board[2-i][i];
    }
    total_sum = max(total_sum, tmp);
    sum.push_back(tmp);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];

            if(board[i][j] == 0)
                to_determine.push_back(make_pair(i, j));
        }
    }

    find_sum();

    // 대각선 3개가 모두 빈칸인 경우
    if(sum[6] == 0 || sum[7] == 0){
        total_sum = (sum[0] + sum[1] + sum[2]) / 2;

        int idx = 0;
        for(auto tbd: to_determine){
            board[tbd.first][tbd.second] = (total_sum - sum[idx]);
            idx++;
        }
    }

    else{
        for(auto tbd: to_determine) {
            int x = tbd.first, y = tbd.second;

            // 행을 기준으로 계산
            if (count(&board[x][0], &board[x][3], 0) == 1)
                board[x][y] = (total_sum - sum[x]);

                // 2개 이상의 0이 포함된 행이 존재하는 경우 열을 기준으로 계산
            else
                board[x][y] = (total_sum - sum[y+3]);

            sum[x] += board[x][y];
            sum[y+3] += board[x][y];
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
