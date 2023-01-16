// 백준 G3 LCA
// LCA(Lowest Common Ancestor,  최소 공통 조상) 알고리즘

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

vector<int> tree[50001];
int parent[50001];
int depths[50001];
bool visited[50001] = {false, };

void dfs(int node, int depth){
    visited[node] = true;
    depths[node] = depth;
    
    for(auto next : tree[node]){
        if(!visited[next]){
            parent[next] = node;
            dfs(next, depth+1);
        }
    }
}

int LCA(int u, int v){
    if(depths[u] > depths[v])
        swap(u, v);
        
    while(depths[u] != depths[v])
        v = parent[v];
        
    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    
    return u;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int n, m;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    memset(parent, -1, sizeof(parent));
    depths[0] = 1;
    dfs(1, 0);

    cin>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }
    
    return 0;
}
