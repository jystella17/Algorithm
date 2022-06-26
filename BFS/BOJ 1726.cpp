#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, res = 987654321;
int sX, sY, sD;
int eX, eY, eD; 
int dx[4] = { 1, 0, -1, 0 }; 
int dy[4] = { 0, -1, 0, 1 };
int p[110][110];
int visit[110][110][5];

struct robot {
	int x;
	int y;
	int dir;
};

void bfs()
{
	visit[sX][sY][sD] = 0;
	queue<robot> q;
	q.push({ sX,sY,sD });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();

		if (x == eX && y == eY && dir == eD) {
			res = min(res, visit[x][y][dir]);
			continue;
		}

		int nD = (dir + 1) % 4;
		if (visit[x][y][nD] == -1) {
			q.push({ x,y,nD });
			visit[x][y][nD] = visit[x][y][dir] + 1;
		}

		nD = (dir + 3) % 4;
		if (visit[x][y][nD] == -1) {
			q.push({ x,y,nD });
			visit[x][y][nD] = visit[x][y][dir] + 1;
		}

		//Go 1, 2, 3
		for (int i = 1; i <= 3; i++) {
			int nx = x + i * dx[dir];
			int ny = y + i * dy[dir];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if(p[nx][ny]==1) break;
			if (visit[nx][ny][dir] == -1 || visit[nx][ny][dir] > visit[x][y][dir] + 1) {
				q.push({ nx,ny,dir });
				visit[nx][ny][dir] = visit[x][y][dir] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			cin >> p[i][j];
	cin >> sX >> sY >> sD >> eX >> eY >> eD;
    
	if (sD == 1) sD = 3;
	else if (sD == 2) sD = 1;
	else if (sD == 3) sD = 0;
	else sD = 2;

	if (eD == 1) eD = 3;
	else if (eD == 2) eD = 1;
	else if (eD == 3) eD = 0;
	else eD = 2;
	

	memset(visit, -1, sizeof(visit));

	bfs();

	cout << res;
}
