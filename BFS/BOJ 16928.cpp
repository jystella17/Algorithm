#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int lddr_snk[101];
int roll[101];

void bfs(int start){
    queue<int> q;
    q.push(start);
    roll[start] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=1; i<=6; i++){
            int next = cur + i;
            
            if(next > 100)
                continue;
                
            if(lddr_snk[next] != 0)
                next = lddr_snk[next];
            
            if(roll[next] == -1){
                roll[next] = roll[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        lddr_snk[x] = y;
    }
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        lddr_snk[u] = v;
    }
    
    memset(roll, -1, sizeof(roll));
    bfs(1);
    
    cout<<roll[100]<<endl;
    
    return 0;
}
