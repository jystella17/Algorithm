#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt = 0;
int dist[1001];
int before_val[1001] = {0, };
vector <pair<int, int>> vec[1001];
int n, m, s, e; 

void dijkstra() {
	priority_queue <pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0; 
    
	while (!pq.empty()) {
		int cost = - pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int ncost = vec[cur][i].second;
			int ncur = vec[cur][i].first;

			if (dist[ncur] > cost + ncost) {
				dist[ncur] = ncost + cost;
				pq.push(make_pair(-dist[ncur], ncur));
				before_val[ncur] = cur;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n>>m;

	for (int i = 1; i <= n; i++)
		dist[i] = 2000000000;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
	}

	cin>>s>>e;
	dijkstra();

	vector <int> arr;
	arr.push_back(e);
	int val = before_val[e];
    
	while(val) {
		arr.push_back(val);
		val = before_val[val];
	}

	cout<<dist[e]<<endl;
	cout<<arr.size()<<endl;
	for (int i = arr.size() - 1; i >= 0; i--)
		cout<<arr[i]<<" ";

	cout<<endl;

	return 0;
}
