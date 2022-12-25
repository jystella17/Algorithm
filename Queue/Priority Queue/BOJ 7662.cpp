// 백준 이중 우선순위 큐 (G3)
// 우선순위 큐, map
// 주의: 이중 우선순위 큐 사용 시 min heap과 max heap 중 한 쪽에서 삭제된 값은 다른 한쪽에서도 삭제되어야 함

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    
    for(int t=0; t<tc; t++){
        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int, vector<int>, less<int>> max_heap;
        map<int, int> in_queue;
        
        int k;
        cin>>k;
        
        for(int i=0; i<k; i++){
            char calc;
            int n;
            cin>>calc>>n;  
            
            if(calc == 'I'){
                min_heap.push(n);
                max_heap.push(n);
                
                if(in_queue.count(n) == 0)
                    in_queue[n] = 1;
                else
                    in_queue[n]++;
            }
            
            else{ // calc == 'D'
                if(n == 1){
                    while(!max_heap.empty() && in_queue[max_heap.top()] == 0)
                        max_heap.pop();
                    
                    if(!max_heap.empty()){
                        in_queue[max_heap.top()]--;
                        max_heap.pop();
                    }
                }
                
                else{ // n == -1
                    while(!min_heap.empty() && in_queue[min_heap.top()] == 0)
                        min_heap.pop();
                    
                    if(!min_heap.empty()){
                        in_queue[min_heap.top()]--;
                        min_heap.pop();
                    }
                }
            }
        }
        
        while(!max_heap.empty() && in_queue[max_heap.top()] == 0)
            max_heap.pop();
            
        while(!min_heap.empty() && in_queue[min_heap.top()] == 0)
            min_heap.pop();
            
        if(min_heap.empty() || max_heap.empty())
            cout<<"EMPTY"<<endl;
        
        else
            cout<<max_heap.top()<<" "<<min_heap.top()<<endl;
    }
    
    return 0;
}
