#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, map[10][10], h[3][20];
int win[3] = { 0, }, cnt[3] = { 0, };
bool check[10] = { false, };
int ans = 0;

bool checkHistory(int num){
	for (int i = 0; i < cnt[0]; i++)
		if (h[0][i] == num)
			return true;

	return false;
}

void dfs(int p1, int p2){

	if (win[1] == k || win[2] == k)
		return;

	if (win[0] == k){
		cout << 1;
		exit(0);
		return;
	}

	for (int i = 1; i <= n; i++){
		if (p1 != 0 && p2 != 0)
			i = n;
		else{
			if (checkHistory(i))
				continue;

			h[0][cnt[0]] = i;
		}
		
		int res = map[h[p1][cnt[p1]]][h[p2][cnt[p2]]];
		int winner;

		if (res == 2) winner = p1;
		else if (res == 1) winner = p1 > p2 ? p1 : p2;
		else winner = p2;

		cnt[p1]++;
		cnt[p2]++;
		win[winner]++;
		dfs(winner, 3 - (p1 + p2));
		cnt[p1]--;
		cnt[p2]--;
		win[winner]--;
	}

	return;
}

int main(){
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	for (int i = 0; i < 20; i++)
		cin >> h[1][i];
	for (int i = 0; i < 20; i++)
		cin >> h[2][i];

	dfs(0, 1);

	cout << 0;

	return 0;
}
