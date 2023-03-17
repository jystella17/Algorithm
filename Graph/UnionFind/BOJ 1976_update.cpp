// 백준 G4 여행 가자

#include <iostream>
#include <algorithm>
using namespace std;

int city[201];

int find(int node){
    if(city[node] == node)
        return node;
    
    return city[node] = find(city[node]);
}

void merge(int x, int y){
    x = find(x); y = find(y);
    
    if(x != y) // 두 노드의 root가 다른 경우
        city[y] = x; // 한 쪽으로 집합을 합침
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; bool answer = true;
    cin>>n; cin>>m;
    for(int i=0; i<=n; i++)
        city[i] = i; // 자기 자신을 부모로 갖도록 초기화
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int connected; cin>>connected;
            if(connected) // 서로 연결된 도시라면 merge로 전체 연결 정보 업데이트
                merge(i, j);
        }
    }
    
    int root;
    for(int i=0; i<m; i++){
        int plan; cin>>plan;
        
        if(i == 0)
            root = find(plan); // 출발 도시의 root를 기준으로
            
        else{
            if(root != find(plan)){ // 출발 도시의 root와 현재 도시의 root가 다르다면 여행 불가능
                answer = false;
                break;
            }
        }
    }
    
    if(answer)
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
        
    return 0;
}
