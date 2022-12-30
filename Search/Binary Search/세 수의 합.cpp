// 백준 G4 세 수의 합
// 이분탐색 응용 - 세 개의 수 중 두 수의 합을 먼저 구하고, (세 수의 합 - 세 번째 수) = (첫 번째 수 + 두 번째 수) 가 되는 값을 찾아야 함

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int set[1001];
    vector<int> two_sum;
    int answer = 0;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
        cin>>set[i];
        
    sort(set, set+n);
    
    // 두 수의 합 모두 구하기
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            two_sum.push_back(set[i] + set[j]);
            
    sort(two_sum.begin(), two_sum.end());
    
    // x + y + z = k => x + y = k - z => x번째와 y번째 수의 합 = 세 수의 합 - z번째 수
    // Binary Search로 두 수의 차가 two_sum의 원소 중 하나와 같아지는 k, z를 구하고
    // 가장 큰 k값 찾기
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            if(binary_search(two_sum.begin(), two_sum.end(), set[i]-set[j]))
                answer = max(answer, set[i]);
        }
    }
    
    cout<<answer<<endl;
    
    return 0;
}
