// 백준 G2 가운데를 말해요
// 중간값을 반드시 인덱스로 구해야 하는 것이 아니라, priority queue의 특성을 이용해 구할 수도 있음
// 이중 우선순위 

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int numbers[100001];
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>numbers[i];


    for(int i=0; i<n; i++){
        if(i%2 == 0) // max_heap부터 번갈아가며 삽입
            max_heap.push(numbers[i]);
        else
            min_heap.push(numbers[i]);
         
        // 실제 중간값과 max_heap.top()의 값이 달라지는 경우  
        if(!min_heap.empty() && !max_heap.empty() && (min_heap.top() < max_heap.top())){
            // min_heap.top()과 max_heap.top()의 값을 교환
            int min_to_max = min_heap.top();
            int max_to_min = max_heap.top();
            min_heap.pop(); max_heap.pop();
            
            max_heap.push(min_to_max);
            min_heap.push(max_to_min);
        }
        
        cout<<max_heap.top()<<"\n";
    }

    return 0;
}
