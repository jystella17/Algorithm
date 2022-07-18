#include <iostream>
#include <string>

using namespace std;

int n,m;
int minimum = 2e9;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
string board[21];

int dfs(int cnt, int x1, int y1, int x2, int y2){
    if(cnt > 10)
        return -1;
    
    for(int i=0; i<4; i++){
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];
        
        if(nx1 >= 0 && nx1 < m && ny1 >= 0 && ny1 < n && nx2 >= 0 && nx2 < m && ny2 >= 0 && ny2 < n){
            if(board[ny1][nx1] == '#' && board[ny2][nx2] == '#')
                dfs(cnt+1, x1, y1, x2, y2);
            
            if(board[ny1][nx1] == '#')
                dfs(cnt+1, x1, x2, nx2, ny2);
            
            if(board[ny2][nx2] == '#')
                dfs(cnt+1, nx1, ny1, x2, y2);
            
            if(board[ny1][nx1] != '#' && board[ny2][nx2] != '#')
                dfs(cnt+1, nx1, ny1, nx2, ny2);
        }
        
        else if((nx1 < 0 || nx1 >= m || ny1 < 0 || ny1 >= n) && (nx2 < 0 || nx2 >= m || ny2 < 0 || ny2 >= n))
            return -1;
        
        else{
            //if(minimum > cnt + 1)
            //    minimum = cnt + 1;
            return cnt + 1;
        }
    }
}

int main(){
    cin>>n>>m;
    
    int c1x, c1y, c2x, c2y;
    int num = 0;
    for(int i=0; i<n; i++){
        cin>>board[i];
        
        for(int j=0; j<m; j++){
            if(board[i][j] == 'o' && num == 0){
                c1x = i, c1y = j;
                num++;
            }
            
            if(board[i][j] == 'o' && num == 1){
                c2x = i, c2y = j;
            }
        }
    }
    
    int ans = dfs(0, c1x, c1y, c2x, c2y);
    cout<<ans<<endl;
    
    return 0;
}
