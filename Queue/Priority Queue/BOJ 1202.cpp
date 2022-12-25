// 백준 보석도둑 (G2)
// 우선순위 큐, Greedy

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    priority_queue<int> stolen;
    pair<int, int> jewelry[300001];
    int bag[300001];
    long long max_price = 0;
    
    int n, k;
    cin>>n>>k;
    
    for(int i=0; i<n; i++)
        cin>>jewelry[i].first>>jewelry[i].second;
    
    for(int i=0; i<k; i++)
        cin>>bag[i];
    
    // 보석(무게 기준), 가방 용량 오름차순 정렬    
    sort(jewelry, jewelry+n);
    sort(bag, bag+k);
    
    // 용량이 작은 가방부터 탐색
    // 가방에 넣을 수 있으면서(무게) 가격이 가장 높은 보석을 Priority Queue에 저장
    int idx = 0;
    for(int i=0; i<k; i++){
        // 현재 가방에 넣을 수 있는 보석을 모두 Priority Queue에 저장
        while(idx < n && jewelry[idx].first <= bag[i]){
            stolen.push(jewelry[idx].second);
            idx++;
        }
        
        if(!stolen.empty()){
            max_price += stolen.top();
            stolen.pop();
        }
    }
    
    cout<<max_price<<endl;
    
    return 0;
}
