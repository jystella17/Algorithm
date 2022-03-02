#include <cstdio>

int dx[] = { -1, 1,0,0 };
int dy[] = { 0, 0,-1,1 };

int ans = 0, v = 1;
char map[5][6];
int temp[5][5] = { 0 };
int visit[5][5] = { 0 };

int getCount(int x, int y) {
	int c = 1;
	visit[x][y] = v;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visit[nx][ny] == v || temp[nx][ny] == 0) continue;
		c += getCount(nx, ny);
	}
	return c;
}

void dfs(int idx, int c, int d) {
	if (d == 7) {
		if (c >= 4 && getCount((idx - 1) / 5, (idx - 1) % 5) == 7) ans++;
		v++;
		return;
	}
	for (int i = idx; i < 25; i++) {
		int x = i / 5, y = i % 5;
		temp[x][y] = 1;
		dfs(i + 1, c + (map[x][y] == 'S'), d + 1);
		temp[x][y] = 0;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%s", map[i]);
	}
	dfs(0, 0, 0);
	printf("%d", ans);
}
