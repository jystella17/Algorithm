#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int dp[100][100][81]; 
char arr[100][100];
string word;

int n, m, k;

int y_ar[4] = { -1,0,1,0 };
int x_ar[4] = { 0,1,0,-1 };

int result = 0;

int solved(int y, int x, int cnt) {

	
	if (cnt == word.size())
		return 1;

	int& ret = dp[y][x][cnt];
	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < 4; i++) {
		int  c = k;
		int ny = y;
		int nx = x;
		while (c--) {
			ny +=  y_ar[i];
			nx +=  x_ar[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (arr[ny][nx] != word[cnt])
				continue;
			ret += solved(ny, nx, cnt + 1);
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> word;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int u = 0; u <= word.size(); u++)
				dp[i][j][u] = -1;



	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == word[0]) {
				result += solved(i, j, 1);
			}


	cout << result << endl;
	return 0;
}
