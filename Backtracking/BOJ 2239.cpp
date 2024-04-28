// 백준 G4 스도쿠

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[10][10];
vector<pair<int, int>> todo;

bool can_progress(int x, int y, int number){
    for(int i=1; i<=9; i++){
        if(i == x)
            continue;

        if(number == board[i][y])
            return false;
    }

    for(int i=1; i<=9; i++){
        if(i == y)
            continue;

        if(number == board[x][i])
            return false;
    }

    for(int i=1; i<=3; i++){
        int posX = 3 * ((x-1) / 3), posY = 3 * ((y-1) / 3);

        for(int j=1; j<=3; j++){
            if(number == board[posX + i][posY + j])
                return false;
        }
    }
    return true;
}

void fill_sudoku(int x, int y, int idx){
    if(idx == todo.size()){
        for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++)
                cout<<board[i][j];
            cout<<"\n";
        }
        exit(0);
    }

    for(int i=1; i<=9; i++){
        if(can_progress(x, y, i)){
            board[x][y] = i;
            fill_sudoku(todo[idx+1].first, todo[idx+1].second, idx+1);
            board[x][y] = 0;
        }
    }
    return;
}

int main(){
    for(int i=1; i<=9; i++){
        string input; cin>>input;

        for(int j=1; j<=9; j++){
            board[i][j] = input[j-1] - '0';

            if(board[i][j] == 0)
                todo.push_back(make_pair(i, j));
        }
    }
    fill_sudoku(todo[0].first, todo[0].second, 0);
    return 0;
}
