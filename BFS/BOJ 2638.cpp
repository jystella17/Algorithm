#include <cstdio>
#include <cstring>
#include <vector>
#define N 100
using namespace std;

vector<pair<int, int>> cheese;
int a[N + 1][N + 1];
int c[N + 1][N + 1];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;

void DFS(int, int);
bool check();
void find();
void set();
int main(void)
{
	int ans = 0, tmp;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &c[i][j]);

	// 초기 외부 공기, 내부 공기 나누기
	// 0일 경우 내부 공기
	// 1일 경우 외부 공기
	DFS(0, 0);

	while (!check())
	{
		find();	// 이번 턴에 녹을 치즈를 찾음
		set(); // 상태 갱신
		cheese.clear();
		ans++;
	}

	printf("%d\n", ans);
	return 0;
}

void DFS(int y, int x)
{
	a[y][x]++;

	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		
		// 아직 방문하지 않았고, 치즈가 아니라면
		if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
		if (a[ny][nx] == 0 && c[ny][nx] == 0) DFS(ny, nx);
	}
}

bool check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j]) return false;

	return true;
}

void find()
{
	int tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == 0) continue;

			tmp = 0;

			for (int k = 0; k < 4; k++) {
				int ny = dy[k] + i;
				int nx = dx[k] + j;

				if (a[ny][nx] == 1 && c[ny][nx] == 0) tmp++;
			}

			if (tmp >= 2) cheese.push_back({ i, j });
		}
	}
}

void set()
{
	for (int i = 0; i < cheese.size(); i++) {

		int y = cheese[i].first;
		int x = cheese[i].second;
		c[y][x] = 0; a[y][x] = 0;

		DFS(y, x);
	}
}
