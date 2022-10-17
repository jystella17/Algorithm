#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> pii;

int n, k;
string st;
map<string, bool> visited;

int bfs(string s) {
	string correct = s;
	sort(correct.begin(), correct.end());
	queue<pii> q;
	q.push(pii(s, 0));
	visited[s] = true;

	while (!q.empty()) {
		string now = q.front().first;
		int cnt = q.front().second;
		q.pop();
        
		if (now == correct) 
            return cnt;
        
		for (int i = 0; i <= n - k; ++i) {
			string temp = now.substr(i, k);
			reverse(temp.begin(), temp.end());
			string next = now.substr(0, i);
			next += temp;
			next += now.substr(i + k);

			if (!visited.count(next)) {
				q.push(pii(next, cnt + 1));
				visited[next] = true;
			}
		}
	}
	return -1;
}

int main() {
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
	    char a;
	    cin >> a;
	    st += a;
    }

    cout<<bfs(st)<<endl;
    return 0;
}
