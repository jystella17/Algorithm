#include <iostream>
#include <string>
using namespace std;

int learn, word[50];

int max(int a, int b) { return a > b ? a : b; }

int DFS(int start, int N, int K, int learning)
{
	int ret = 0;

	if (learning == K)
	{
		for (int i = 0; i < N; i++)
			if ((word[i] & learn) == word[i]) 
				ret++;

		return ret;
	}

	for (int i = start; i < 26; i++)
	{
		if ((learn & (1 << i)) == 0)
		{
			learn |= (1 << i);
			ret = max(ret, DFS(i + 1, N, K, learning + 1));
			learn &= ~(1 << i);
		}
	}

	return ret;
}

int main(void)
{
	learn |= 1 << ('a' - 'a');
	learn |= 1 << ('c' - 'a');
	learn |= 1 << ('i' - 'a');
	learn |= 1 << ('n' - 'a');
	learn |= 1 << ('t' - 'a');

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++)
			word[i] |= (1 << (str[j] - 'a'));
	}
		
	if (K < 5 || K == 26)
		cout << (K == 26 ? N : 0) << endl;
	else
		cout << DFS(0, N, K, 5) << endl;

	return 0;
}
