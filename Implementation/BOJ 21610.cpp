#include<bits/stdc++.h>

using namespace std;

int board[51][51],check[51][51];

int n, m;
vector<pair<int, int>> order;
queue<pair<int, int>> q,sq;

int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int get_ans();
void move_cloud(pair<int, int> pr);
void duplicate_magic();
void make_cloud();
void init();
void input();

void show();

int main()
{
	input();
	for (int i = 0; i < order.size(); i++) {
		move_cloud(order[i]);
		//show();
		//cout << "\n";
	}
	cout << get_ans();
	return 0;
}
void show()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}
int get_ans()
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum += board[i][j];
	return sum;
}
//구름의 이동
void move_cloud(pair<int,int> pr)
{	
	int size=q.size();
	for (int i = 0; i < size; i++) {
		pair<int, int> cur = q.front();
		q.pop();

		int tx=cur.first, ty=cur.second;
		for (int s = 0; s < pr.second; s++) {
			tx += dx[pr.first];
			ty += dy[pr.first];

			if (tx <= 0)tx = n;
			if (ty <= 0)ty = n;
			if (tx > n)tx = 1;
			if (ty > n)ty = 1;
		}
		q.push({ tx,ty });
	}
	sq = q;
	//구름에 있는 칸에 비 1씩
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		//구름 체크
		check[cur.first][cur.second] = 1;
		//비가 1씩
		board[cur.first][cur.second] += 1;
	}
	duplicate_magic();
	make_cloud();
	init();
}
//물복사마법
void duplicate_magic()
{
	while (!sq.empty()) {
		pair<int, int> cur = sq.front();
		sq.pop();
		for (int i = 1; i < 8; i += 2) {
			int tx = cur.first + dx[i];
			int ty = cur.second + dy[i];

			if (tx <= 0 || tx > n || ty <= 0 || ty > n)continue;

			if (board[tx][ty] > 0)
				board[cur.first][cur.second] += 1;
		}
	}
}
//구름 생성
void make_cloud()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!check[i][j] && board[i][j] >= 2) {
				q.push({ i,j });
				board[i][j] -= 2;
			}
}
void init()
{
	memset(check, 0, sizeof(check));
}
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		order.push_back({ x-1,y });
	}
	q.push({ n,1 });
	q.push({ n,2 });
	q.push({ n - 1,1 });
	q.push({ n - 1,2 });
}
