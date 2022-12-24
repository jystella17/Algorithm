// 백준 순회강연 (G3)
// 우선순위 큐, Greedy

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<pair<int, int>> offer;
    priority_queue<int, vector<int>, greater<int>> accepted;
    int n, p, d;
    int money = 0;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>p>>d;
        offer.push_back(make_pair(d,p));
    }
    sort(offer.begin(), offer.end());
    
    for(int i=0; i<n; i++){
        accepted.push(offer[i].second);
        
        if(accepted.size() > offer[i].first)
            accepted.pop();
    }
    
    while(!accepted.empty()){
        money += accepted.top();
        accepted.pop();
    }
    
    cout<<money<<endl;
    
    return 0;
}
