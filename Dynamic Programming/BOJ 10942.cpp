// 백준 G4 팰린드롬?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2001];
bool palindrom[2001][2001] = { false, };

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

	int n; cin >> n;

	for(int i=1; i<=n; i++)
		cin >> arr[i];

	for(int i=1; i<=(n-1); i++) {
		if (arr[i] == arr[i+1])
			palindrom[i][i+1] = true;
	}

	for(int i=1; i<=n; i++) {
		palindrom[i][i] = true;
	}

	for(int i=n-1; i>=1; i--) {
		for (int j=i+2; j<=n; j++) {
			if (arr[i] == arr[j] && palindrom[i+1][j-1] == true) {
				palindrom[i][j] = true;
			}
		}
	}

	int m; cin >> m;
	for (int i=0; i<m; i++) {
        int s, e; cin>>s>>e;
		cout<<palindrom[s][e]<<'\n';
	}
	return 0;
}
