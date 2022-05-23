#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int graph[300][300];
int tmp[300][300];
bool visited[300][300];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void check(int r, int c) {
	queue<pair<int, int>>q;
	q.push({ r,c });

	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];

			if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
				if (graph[nr][nc] != 0 && !visited[nr][nc]) {
					q.push({ nr,nc });
					visited[nr][nc] = true;
				}
			}
		}
	}
}
void meltIce() {
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) continue;
			int waterCnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (graph[nx][ny] == 0) {
					waterCnt++;
				}
			}
			int val = graph[i][j] - waterCnt;
			if (val > 0) tmp[i][j] = val;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			graph[i][j] = tmp[i][j];
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	int time = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && graph[i][j] != 0) {
					check(i, j);
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			cout << 0;
			break;
		}

		else if (cnt >= 2) {
			cout << time;
			break;
		}

		time++;
		meltIce();
		memset(visited, false, sizeof(visited));

	}
	return 0;
}
