// 백준 G3 파티
// 역방향 그래프 변환 착안

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, x;
vector<pair<int, int>> village[1001];
vector<pair<int, int>> reversed[1001];

int dist_go[1001], dist_back[1001];

void go_party(int start){
    // duration, destination
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    
    fill_n(dist_go, n+1, INF);
    dist_go[start] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_time = -pq.top().first;
        pq.pop();
        
        for(int i=0; i<reversed[cur].size(); i++){
            int next = reversed[cur][i].second;
            int duration = reversed[cur][i].first + cur_time;
            
            if(dist_go[next] <= duration)
                continue;
                
            dist_go[next] = duration;
            pq.push(make_pair(-duration, next));
        }
    }
}

void back_home(int start){
    // duration, destination
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    
    fill_n(dist_back, n+1, INF);
    dist_back[start] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_time = -pq.top().first;
        pq.pop();
        
        for(int i=0; i<village[cur].size(); i++){
            int next = village[cur][i].second;
            int duration = village[cur][i].first + cur_time;
            
            if(dist_back[next] <= duration)
                continue;
                
            dist_back[next] = duration;
            pq.push(make_pair(-duration, next));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>x;
    for(int i=0; i<m; i++){
        int start, end, duration; 
        cin>>start>>end>>duration;
        
        village[start].push_back(make_pair(duration, end));
        reversed[end].push_back(make_pair(duration, start));
    }
    
    go_party(x); 
    back_home(x);
    
    int answer = 0;
    for(int i=1; i<=n; i++){
        int times = dist_go[i] + dist_back[i];
        answer = max(answer, times);
    }
    
    cout<<answer<<"\n";
    return 0;
}
