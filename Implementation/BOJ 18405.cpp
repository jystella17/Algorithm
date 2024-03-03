// 백준 G5 경쟁적 전염
// BFS 풀이도 가능

#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#define INF 987654321
using namespace std;

int contagion[1001][1001];
vector<pair<int, int>> search_list;
set<pair<int, int>> candidate;

int main(){
    int n, k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>contagion[i][j];

            if(contagion[i][j] != 0)
                search_list.push_back(make_pair(i, j));
        }
    }

    int s, x, y; cin>>s>>x>>y;
    for(auto ch : search_list) {
        int distance = abs(ch.first - x) + abs(ch.second - y);
        if(distance > s)
            continue;

        candidate.insert(make_pair(contagion[ch.first][ch.second], distance));
    }

    int answer = INF, min_time = INF;
    for(auto c : candidate){
        if(c.second <= min_time){
            if(c.second == min_time && c.first >= answer)
                continue;
            
            answer = c.first;
            min_time = c.second;
        }
    }
    
    if(answer == INF)
        cout<<0<<"\n";
    else
        cout<<answer<<"\n";
    return 0;
}
