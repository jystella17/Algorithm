// BOJ 1715 카드 정렬하기

#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> card;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        
        card.push(tmp);
    }
    
    int ans = 0;
    int i=0;
    
    while(!card.empty()){
        if(i == n-1)
            break;
            
        int c1 = card.top();
        card.pop();
        int c2 = card.top();
        card.pop();
        
        ans += (c1+c2);
        card.push(c1+c2);
        i++;
    }
    
    cout<<ans<<endl;
}
