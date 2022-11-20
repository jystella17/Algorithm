// 백준 여행 가자 (Gold 4)
// Union-Find 알고리즘

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cities[201];

int getParent(int x){
    if(cities[x] < 0)
        return x;
        
    return cities[x] = getParent(cities[x]);
}

void merge(int par_a, int par_b){ // Union-Find의 가중법칙 적용
    if(par_a >= par_b){ // root a에 연결된 node의 개수가 root b에 연결된 node의 개수보다 많은 경우
        // root b에 연결된 트리 전체가 root a에 연결된 트리의 서브 트리가 되므로
        cities[par_a] += cities[par_b]; // root a에 새로 연결된 서브 트리의 원소 개수를 더함
        cities[par_b] = par_a; // root b였던 원소는 더이상 트리의 root가 아니므로 연결된 node의 개수를 저장하지 않고 root의 index를 저장
    }
    
    else{ // root b에 연결된 node의 개수가 root a에 연결된 node의 개수보다 많은 경우
        // root a에 연결된 트리 전체가 root b에 연결된 트리의 서브 트리가 되므로
        cities[par_b] += cities[par_a]; // root b에 새로 연결된 서브 트리의 원소 개수를 더함
        cities[par_a] = par_b; // root a였던 원소는 더이상 트리의 root가 아니므로 연결된 node의 개수를 저장하지 않고 root의 index를 저장
    }
}

int main(){
    bool answer = true;
    int n,m;
    cin>>n>>m;
    
    memset(cities, -1, sizeof(cities)); 
    // 가중법칙 적용 시, 기본적으로 각 node에는 root node의 index를 저장하되 root node에는 해당 트리에 연결된 node의 총 개수를 저장
    // 최초에는 각 root node와 연결된 노드가 없기 때문에 모두 -1로 임의 초기화
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int connect;
            cin>>connect;
            
            if(connect){ // i와 j가 서로 연결된 node이면
                int a = getParent(i);
                int b = getParent(j);
                
                if(a == b) // 두 node의 root가 같다면 아무런 작업을 하지 않음
                    continue;
                    
                merge(a, b); // 서로 다른 root를 가진다면 Union 과정 수행
            }
        }
    }
    
    int root;
    for(int i=0; i<m; i++){
        int plan;
        cin>>plan;
        
        if(i == 0)
            root = getParent(plan);
            
        else{
            if(root != getParent(plan)){
                answer = false;
                break;
            }
        }
    }
    
    if(answer)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
        
    return 0;
}
