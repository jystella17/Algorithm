#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> work(works.begin(), works.end());
    int size = works.size();
    
    for(int i=0; i<n; i++){
        if(work.top() == 0)
            return 0;
        
        works[size-1]--;
        int tmp = work.top();
        work.pop();
        work.push(tmp-1);
    }
    
    for(int i=0; i<size; i++){
        answer += work.top() * work.top();
        work.pop();
    }       
    
    return answer;
}
