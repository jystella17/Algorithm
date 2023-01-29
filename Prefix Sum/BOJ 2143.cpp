// 백준 G3 두 배열의 합
// 누적합 + Binary Search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t; 
    
    long long n;
    cin>>n;
    vector<long long> A(n);
    for(int i=0; i<n; i++)
        cin>>A[i];
    
    long long m;
    cin>>m;
    vector<long long> B(m);
    for(int i=0; i<m; i++)
        cin>>B[i];
    
    // 각 배열의 모든 구간합 저장 (ex. 1~n까지의 구간합, 2~n까지의 구간합 등)
    vector<long long> sum_A, sum_B;

    for(int i=0; i<n; i++){
        long long sum = A[i];
        sum_A.push_back(sum);
        
        for (int j=i+1; j<n; j++){
            sum += A[j];
            sum_A.push_back(sum);
        }
    }

    for(int i=0; i<m; i++){
        long long sum = B[i];
        sum_B.push_back(sum);
        
        for (int j=i+1; j<m; j++){
            sum += B[j];
            sum_B.push_back(sum);
        }
    }
        
    sort(sum_A.begin(), sum_A.end());
    sort(sum_B.begin(), sum_B.end());
    
    // 두 배열 중 한 배열의 모든 가능한 구간합을 기준으로
    // 해당 값과 더해서 T가 되는 다른 배열의 구간합을 찾는다.
    // lower_bound => T-sum_A[x]와 같거나 큰 값을 갖는 구간합
    // upper_bound => T-sum_A[x]보다 큰 값을 갖는 구간합
    // 이 때, 시간복잡도를 줄이기 위해 이분 탐색을 활용한다.
    
    long long answer = 0;
    
    for(int i=0; i<sum_A.size(); i++){
        int low = lower_bound(sum_B.begin(), sum_B.end(), t-sum_A[i]) - sum_B.begin();
        int high = upper_bound(sum_B.begin(), sum_B.end(), t-sum_A[i]) - sum_B.begin();
        
        // 구간합이 같은 부배열이 여러 개 있다면, 각 부배열을 다른 케이스로 저장해야 하므로
        // high - low = 구간합이 T-sum_A[x]인 부배열의 개수를 구함
        answer += (high - low);
    }
    
    cout<<answer<<endl;
    return 0;
}
