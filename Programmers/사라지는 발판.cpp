#include <vector>
using namespace std;

int N,M;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

bool inRange(int y, int x) {
    return 0<= y && y < N && 0 <= x && x < M;
}

// can't move
bool isFinished(vector<vector<int>>& board, int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(inRange(ny,nx) && board[ny][nx])
            return false;
    }
    return true;
}

// {canWin, turn}
pair<bool, int> solve(vector<vector<int>>& board, int y1, int x1, int y2, int x2) {
    // base case
    if(isFinished(board, y1, x1)) return {false, 0};
    if(y1==y2 && x1==x2) return {true, 1};
    
    bool canWin = false;
    int minTurn = 1e9, maxTurn = 0;
    
    for(int i=0; i<4; i++) {
        int ny = y1+dy[i];
        int nx = x1+dx[i];
        if(!inRange(ny,nx) || !board[ny][nx]) continue;
        
        // dfs
        board[y1][x1] = 0;
        pair<bool, int> res = solve(board, y2, x2, ny, nx);
        board[y1][x1] = 1;

        if(!res.first) {
            canWin = true;
            minTurn = min(minTurn, res.second);
        }
        else if(!canWin) {
            maxTurn = max(maxTurn, res.second);
        }
    }
    
    int turn = canWin ? minTurn : maxTurn;
    return {canWin, 1 + turn};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size(), M = board[0].size();

    return solve(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}
