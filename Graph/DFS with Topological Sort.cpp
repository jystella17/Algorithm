#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> visited, order;
vector<vector<int>> adj;

void dfs(int start){
    visited[start] = 1;
    
    for(int next=0; next<adj.size(); next++)
        if(!visited[next] && adj[start][next])
            dfs(next);

    order.push_back(start);
}

vector<int> topologicalSort(){
    int m = adj.size();
    visited = vector<int>(m,0);
    order.clear();
    
    for(int i=0; i<m; i++){
        if(!visited[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());
    
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            if(adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}

int main(){
    int tc, n;
    vector<string> dict;
    adj = vector<vector<int>>(26, vector<int>(26,0));
    
    cin>>tc>>n;
    for(int i=0; i<tc; i++){
        for(int j=0; j<n; j++){
            string word;
            cin>>word;
            dict.push_back(word);
        }
    }
    
    for(int i=0; i<dict.size()-1; i++){
        int j = i+1;
        int len = min(dict[i].size(), dict[j].size());
        
        for(int k=0; k<len; k++){
            if(dict[i][k] != dict[j][k]){
                int x = dict[i][k] - 'a';
                int y = dict[j][k] - 'a';
                
                adj[x][y] = 1;
                break;
            }
        }
    }
    
    vector<int> answer = topologicalSort();
    
    if(answer.empty())
        cout<<"INVALID HYPOTHESIS"<<endl;
    
    for(int i=0; i<answer.size(); i++)
        cout<<char(answer[i] + 97);
    cout<<endl;
    
    return 0;
}
