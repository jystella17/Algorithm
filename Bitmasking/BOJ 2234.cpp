#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[51][51] = { 0, };
int visited[51][51] = { 0, };
int two_arr[2600] = { 0, };
int n, m;
int one = 0, two = 0, three = 0;
int y_ar[4] = { 0,-1,0,1 };
int x_ar[4] = { -1,0,1,0 };
int bfs(int y, int x) {
	int two_count = 1;
	queue <pair<int, int>> que;
	que.push(make_pair(y, x));
	visited[y][x] = one;

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y_ar[i];
			int nx = cx + x_ar[i];
			if (ny >= 0 && ny < m && nx >= 0 && nx < n)
				if (visited[ny][nx] == 0 && (((1 << i) & arr[cy][cx]) == 0)) {
					visited[ny][nx] = one;
					two_count++;
					que.push(make_pair(ny, nx));
				}
		}
	}
	return two_count;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (visited[i][j] == 0) {
				one++;
				two_arr[one] = bfs(i, j);
				if (two_arr[one] > two)
					two = two_arr[one];
			}
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			
			for (int k = 0; k < 4; k++) {
				
				if (((1 << k) & arr[i][j]) != 0){
					
					int ny = i + y_ar[k];
					int nx = j + x_ar[k];
					if (ny >= 0 && ny < m && nx >= 0 && nx < n) {
						
						if(visited[i][j] != visited[ny][nx])
							three = max(three, two_arr[visited[i][j]] + two_arr[visited[ny][nx]]);
						
					}
					
				}
			}
			
		}
	
	cout << one << endl;
	cout << two << endl;
	cout << three << endl;
	return 0;
}
