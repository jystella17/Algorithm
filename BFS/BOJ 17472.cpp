#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M, ans;
int island_num;
int map[11][11];
int visit[11][11];
int island_visit[7];
int parent[7];
int island[7][4]; // X1, X2, Y1, Y2
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<tuple<int, int, int>> vec;
vector<int> graph[7];
queue<int> q;

int find(int u)
{
	if (u == parent[u]) return u;
	else return find(parent[u]);
}

bool union_island(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u != v)
	{
		parent[u] = v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		return true;
	}
	else return false;
		
}

void DFS(int x, int y)
{
	if (visit[x][y]) return;
	
	visit[x][y] = true;
	map[x][y] = island_num; 

	island[island_num][0] = min(island[island_num][0], x);
	island[island_num][1] = max(island[island_num][1], x);
	island[island_num][2] = min(island[island_num][2], y);
	island[island_num][3] = max(island[island_num][3], y); 

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
		{
			if (map[next_x][next_y] != 0 && !visit[next_x][next_y])
				DFS(next_x, next_y);
		}
	}
}

void distance(int now, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int now_x = x;
		int now_y = y;
		int dist = 0;

		while (true)
		{
			now_x += dx[i];
			now_y += dy[i];

			if (now_x < 1 || now_x > N || now_y < 1 || now_y > M || map[now_x][now_y] == now) break;

			if (map[now_x][now_y] != 0)
			{
				vec.push_back({ dist , now, map[now_x][now_y] });
				break;
			}
			dist++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= 6; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] != 0)
			{
				if(!visit[i][j]) island_num++;
				DFS(i, j);
			}
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] != 0)
			{
				distance(map[i][j], i, j);
			}
		}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		int dist = get<0>(vec[i]);
		int island_1 = get<1>(vec[i]);
		int island_2 = get<2>(vec[i]);

		if (dist < 2) continue;

		if (union_island(island_1, island_2))
			ans += dist;
	}

	int cnt = 1;
	q.push(1);

	while (!q.empty())
	{
		int now_island = q.front();
		q.pop();
		island_visit[now_island] = true;

		for (int i = 0; i < graph[now_island].size(); i++)
		{
			int next_island = graph[now_island][i];
			if (!island_visit[next_island])
			{
				q.push(next_island);
				cnt++;
			}
		}
	}

	if (cnt != island_num) cout << -1 << '\n';
	else cout << ans << '\n';
}
