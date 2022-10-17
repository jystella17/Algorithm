#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;

int bfs(vector<string> start, vector<string> dest)
{
	set<vector<string>> discovered;
	map<vector<string>, int> depth;
	queue<vector<string>> q;

	discovered.insert(start);
	depth.insert(make_pair(start, 0));
	q.push(start);

	while (!q.empty())
	{
		vector<string> here = q.front();
		q.pop();

		if (here == dest)
			return depth[here];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
					continue;

				if (here[i].size() == 0)
					continue;

				vector<string> there = here;
				string from = there[i];
				string to = there[j];
				char from_top = there[i].back();
				from.pop_back();
				to += from_top;

				there[i] = from;
				there[j] = to;

				if (discovered.count(there) == 0)
				{
					discovered.insert(there);
					depth.insert(make_pair(there, depth[here] + 1));
					q.push(there);
				}
			}
		}
	}

	return -1;
}

int main(){
	vector<string> stick(3, "");
	int A_num = 0;
	int B_num = 0;
	int C_num = 0;

	for (int i = 0; i < 3; i++)
	{
		int input;
		string won = "";

		cin >> input;

		if (input != 0)
			cin >> won;

		for (int j = 0; j < input; j++)
		{
			if (won[j] == 'A')
				A_num++;
			else if (won[j] == 'B')
				B_num++;
			else if (won[j] == 'C')
				C_num++;
		}

		stick[i] = won;
	}

	vector<string> dest_stick(3, "");

	for (int i = 0; i < A_num; i++)
		dest_stick[0] += 'A';
	for (int i = 0; i < B_num; i++)
		dest_stick[1] += 'B';
	for (int i = 0; i < C_num; i++)
		dest_stick[2] += 'C';

	cout << bfs(stick, dest_stick);

	return 0;
}
