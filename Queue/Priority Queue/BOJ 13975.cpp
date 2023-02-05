// 백준 G4 파일 합치기 3

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int tc, k;
    cin>>tc;
    
    for(int t=0; t<tc; t++){
        priority_queue<long long, vector<long long>, greater<long long>> files;
        cin>>k;
        
        for(int i=0; i<k; i++){
            int tmp; cin>>tmp;
            files.push(tmp);
        }
        
        long long min_cost = 0;
        for(int i=0; i<k-1; i++){
            long long sum = 0;
            sum += files.top(); files.pop();
            sum += files.top(); files.pop();
            
            min_cost += sum;
            files.push(sum);
        }
        
        cout<<min_cost<<"\n";
    }

    return 0;
}
