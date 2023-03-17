// 백준 G2 친구 네트워크

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int parent[200001]; // f <= 100,000, 한 줄에 두 명의 이름이 있으므로 2*100000
int network[200001]; // 각 사용자가 속한 친구 네트워크에 몇 명이 있는지 저장

int find(int node){
    if(parent[node] == node)
        return node;
    
    return parent[node] = find(parent[node]);
}

int merge(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x != y){
        if(network[x] < network[y])
            swap(x, y);
        
        network[x] += network[y];
        parent[y] = x;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T, num = 1; 
    cin>>T;
    for(int t=0; t<T; t++){
        map<string, int> users; // string=입력받은 이름, int=임의의 숫자 매핑 (parent 배열에서 사용)
        int f; cin>>f;
        
        for(int i=0; i<200001; i++){
            parent[i] = i;
            network[i] = 1;
        }
            
        for(int i=0; i<f; i++){
            string user1, user2;
            cin>>user1>>user2;
            
            if(users.count(user1) == 0)
                users[user1] = num++;
            if(users.count(user2) == 0)
                users[user2] = num++;
                
            int root = merge(users[user1], users[user2]);
            // user1, user2 두 노드가 속한 트리에 대해 merge를 수행했으므로
            // user1의 root와 user2의 root가 같은 것이 보장됨
            cout<<network[root]<<"\n";
        }
    }
}
