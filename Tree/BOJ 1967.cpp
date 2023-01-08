// 백준 G4 트리의 지름
// 트리의 지름을 구하는 방법 : 1. root에서 가장 멀리 떨어진 노드 구하기 -> 2. 해당 노드에서 가장 멀리 떨어진 노드까지의 거리 구하기

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001] = {false, };
int point, answer = 0;

void dfs(int x, int diameter){
    // 이미 방문된 지점 = parent이므로, 탐색을 진행해도 지름이 더 작아짐
    if(visited[x])
        return;
        
    visited[x] = true;
    for(int i=0; i<tree[x].size(); i++){
        if(answer < diameter){
            answer = diameter;
            point = x;
        }
        
        dfs(tree[x][i].first, diameter+tree[x][i].second);
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    
    for(int i=0; i<n-1; i++){
        int a, b, weight;
        cin>>a>>b>>weight;
        
        tree[a].push_back(make_pair(b, weight));
        tree[b].push_back(make_pair(a, weight));
    }

    // root(=1)에서 가장 멀리 떨어진 노드 A 구하기
    dfs(1, 0);
    
    answer = 0;
    memset(visited, false, sizeof(visited));
    
    // 노드 A에서 가장 멀리 떨어진 노드 B 구하기 => 지름의 최대값
    dfs(point, 0);
    cout<<answer<<endl;
    
    return 0;
}
