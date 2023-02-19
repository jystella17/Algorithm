#include <iostream>
#include <algorithm>
using namespace std;

int n, white_bishop, black_bishop;
int board[10][10];
bool diagonal_upper[20],diagonal_under[20];

void dfs(int x, int y, int cnt, bool flag){
	if(y >= n){
		x++;
		if(y % 2 == 1)
			y = 0;
		else
			y = 1;
	}

	if(x == n){
		if(!flag)
			black_bishop = max(black_bishop, cnt);
		else
			white_bishop = max(white_bishop, cnt);
        
		return;
	}
    
	if(board[x][y] == 1 && !diagonal_upper[x+y] && !diagonal_under[x-y+n]){
		diagonal_upper[x+y] = true;
		diagonal_under[x-y+n] = true;
        
		dfs(x, y+2, cnt+1, flag);
        
		diagonal_upper[x+y] = false;
		diagonal_under[x-y+n] = false;
	}
	
    dfs(x, y+2, cnt, flag);
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> board[i][j];

	dfs(0,0,0,0);
	dfs(0,1,0,1);

	cout<<black_bishop + white_bishop<<"\n";
	return 0;
}
