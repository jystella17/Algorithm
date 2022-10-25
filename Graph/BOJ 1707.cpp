#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 987654321;
#define RED 1
#define BLUE 2
using namespace std;

int v, e;
vector<vector<int>> graph;
vector<int> isVisited;

void DFS(int cur){
    if(!isVisited[cur]) 
        isVisited[cur] = RED;

    for(int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];

        if(!isVisited[next]){
            if(isVisited[cur] == RED)   
                isVisited[next] = BLUE;
            
            else if(isVisited[cur] == BLUE) 
                isVisited[next] = RED;
            
            DFS(next);
        }
    }
}

bool isBipartite(){
    for(int cur = 1; cur <= v; cur++){
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
      
            if(isVisited[cur] == isVisited[next])   
                return false;
        }
    }
    return true;
}

int main(){
    int tc;
    cin>>tc;
    
    while(tc--){
        cin>>v>>e;
        graph.assign(v + 1, vector<int>(0, 0));
        isVisited.assign(v + 1, false);

        for(int i = 0; i < e; i++){
            int s, e;
            cin>>s>>e;
            graph[s].emplace_back(e);
            graph[e].emplace_back(s);
        }
        
        for(int i = 1; i <= v; i++){
            if(!isVisited[i])   
                DFS(i);
        }
        
        if(isBipartite())   
            cout<<"YES"<<endl;
        
        else    
            cout<<"NO"<<endl;
    }

    return 0;
}
